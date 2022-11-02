#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  I'm back !

const int MAX_NODES = (2e5);

vector <int> Adj[MAX_NODES];

int Val[MAX_NODES];

bool win;

int nbNodes, nbCut;

pair <int, int> Dfs(int node, int parent, int target) {
    int xorSum = Val[node];
    int cnt = 0;
    for (int dest : Adj[node])
    {
        if (dest ^ parent)
        {
            pair <int, int> r = Dfs(dest, node, target);
            xorSum ^= r.first;
            cnt += r.second;
        }
    }
    if (cnt >= 2 || (cnt >= 1 && xorSum == 0))
        win = true;
    cnt += (xorSum == target);
    return {xorSum, cnt};
}

void Solve() {
    scanf("%lld %lld", &nbNodes, &nbCut);
    int xorTot = 0;
    win = false;
    for (int i = 0; i < nbNodes; i ++)
    {
        Adj[i].clear();
        scanf("%lld", &Val[i]);
        xorTot ^= Val[i];
    }
    for (int i = 1; i < nbNodes; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        Adj[-- a].push_back(-- b);
        Adj[b].push_back(a);
    }
    if (xorTot == 0)
    {
        printf("YES\n");
        return;
    }
    if (nbCut == 2)
    {
        printf("NO\n");
        return;
    }
    Dfs(0, 0, xorTot);
    if (win)
        printf("YES\n");
    else
        printf("NO\n");
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