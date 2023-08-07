#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

struct Edge {
    int destination;
    int weight;
};

struct Vertex {
    struct Edge edges[MAX_VERTICES];
    int edgeCount;
};
void dijkstra(struct Vertex graph[], int start, int vertices, int distances[]) {
    bool visited[MAX_VERTICES] = { false };

    // Initialize distances from the start vertex to all other vertices as infinity
    for (int i = 0; i < vertices; i++) {
        distances[i] = INT_MAX;
    }

    // Distance from start vertex to itself is 0
    distances[start] = 0;

    // Loop through all vertices to find the shortest path
    for (int count = 0; count < vertices - 1; count++) {
        // Find the vertex with the minimum distance value from the set of unvisited vertices
        int minDistance = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && distances[i] < minDistance) {
                minDistance = distances[i];
                minIndex = i;
            }
        }

        // Mark the selected vertex as visited
        visited[minIndex] = true;

        // Update distances for adjacent vertices of the selected vertex
        for (int i = 0; i < graph[minIndex].edgeCount; i++) {
            int destination = graph[minIndex].edges[i].destination;
            int weight = graph[minIndex].edges[i].weight;

            if (!visited[destination] && distances[minIndex] != INT_MAX &&
                distances[minIndex] + weight < distances[destination]) {
                distances[destination] = distances[minIndex] + weight;
            }
        }
    }
}
