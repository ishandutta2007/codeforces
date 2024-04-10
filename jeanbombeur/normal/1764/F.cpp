#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_NODES = (2e3);

struct event {
    int val, parent, child;
};

vector <int> Adj[MAX_NODES];

event Opti[MAX_NODES];

int Dist[MAX_NODES][MAX_NODES];

int In[MAX_NODES];

int nbNodes;

bool operator<(event a, event b) {
    return a.val < b.val;
}

int Dfs(int node, int parent) {
    int nb = 1;
    for (int dest : Adj[node])
        nb += Dfs(dest, node);
    if (parent >= 0)
        printf("%lld %lld %lld\n", parent + 1, node + 1, (Dist[parent][parent] - Dist[node][parent]) / nb);
    return nb;
}

void Read() {
    scanf("%lld", &nbNodes);
    for (int i = 0; i < nbNodes; i ++)
    {
        for (int j = 0; j <= i; j ++)
        {
            scanf("%lld", &Dist[i][j]);
            Dist[j][i] = Dist[i][j];
        }
    }
    In[0] = 1;
    for (int i = 1; i < nbNodes; i ++)
    {
        Opti[i] = {Dist[0][i], 0, i};
    }
    for (int k = 1; k < nbNodes; k ++)
    {
        event maxi = {-1, 0, 0};
        for (int i = 1; i < nbNodes; i ++)
        {
            if (!In[i] && maxi < Opti[i])
                maxi = Opti[i];
        }
        int cur = maxi.child;
        In[cur] = 1;
        Adj[maxi.parent].push_back(cur);
        for (int i = 0; i < nbNodes; i ++)
        {
            if (!In[i] && Opti[i] < (event){Dist[cur][i], cur, i})
                Opti[i] = {Dist[cur][i], cur, i};
        }
    }
    Dfs(0, -1);
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}