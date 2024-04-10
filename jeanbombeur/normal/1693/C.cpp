#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

//  I've been looking forward to this

//  <|_|>

const int MAX_VALUES = (2e5);

struct event {
    int node, dist;
};

bool operator<(event a, event b) {
    return a.dist > b.dist;
}

vector <int> Parents[MAX_VALUES];

int Nb[MAX_VALUES];
int Dist[MAX_VALUES];

priority_queue <event> Dijkstra;

int nbNodes, nbEdges;

void Solve() {
    scanf("%lld %lld", &nbNodes, &nbEdges);
    for (int i = 0; i < nbEdges; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        Parents[-- b].push_back(-- a);
        Nb[a] ++;
    }
    fill_n(Dist, nbNodes, -1);
    Nb[nbNodes - 1] = 0;
    Dijkstra.push({nbNodes - 1, 0});
    while (!Dijkstra.empty())
    {
        event a = Dijkstra.top();
        Dijkstra.pop();
        if (Dist[a.node] < 0)
        {
            Dist[a.node] = a.dist;
            for (int dest : Parents[a.node])
            {
                Nb[dest] --;
                Dijkstra.push({dest, a.dist + 1 + Nb[dest]});
            }
        }
    }
    printf("%lld\n", Dist[0]);
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}