#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

//  <|_|>

//  I've been looking forward to this

const int MAX_VALUES = (2e5);

vector <int> Adj[MAX_VALUES];

int nbNodes, nbBuds;

bool Dfs(int node, int parent) {
    bool t = false;
    for (int dest : Adj[node])
    {
        if (dest != parent && !Dfs(dest, node))
            t = true;
    }
    nbBuds += t;
    return t;
}

void Solve() {
    scanf("%lld", &nbNodes);
    for (int i = 0; i < nbNodes; i ++)
    {
        Adj[i].clear();
    }
    for (int i = 1; i < nbNodes; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        Adj[-- a].push_back(-- b);
        Adj[b].push_back(a);
    }
    nbBuds = 0;
    int ans = Dfs(0, 0);
    nbBuds -= ans;
    printf("%lld\n", nbNodes - 2 * nbBuds - ans);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}