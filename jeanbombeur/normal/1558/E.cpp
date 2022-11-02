#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  It that's what it takes to save the world, it's better to let that world die

const int MAX_CAVES = (1e3);

vector <int> Adj[MAX_CAVES];

pair <int, int> Power[MAX_CAVES];

int Vu[MAX_CAVES];

int nbCaves, nbTunnels;

bool Dfs(int node, int parent, int power) {
    if (Vu[node] == 0)
        Vu[node] = 1;
    bool win = false;
    for (int dest : Adj[node])
    {
        if (dest != parent)
        {
            if (Vu[dest] != 0 || (power > Power[dest].first && Dfs(dest, node, power + Power[dest].second)))
            {
                Vu[node] = min(Vu[node], -1LL);
                win = true;
            }
        }
    }
    return win;
}

bool Check(int startPower) {
    fill_n(Vu, nbCaves, 0LL);
    Dfs(0, 0, startPower);
    int nb = 0;
    for (int i = 0; i < nbCaves; i ++)
    {
        for (int j = 0; j < nbCaves; j ++)
        {
            if (Vu[j] == -1)
            {
                nb ++;
                startPower += Power[j].second;
                Vu[j] = -2;
            }
            Vu[j] = min(Vu[j], 0LL);
        }
        for (int j = 0; j < nbCaves; j ++)
        {
            if (Vu[j] < 0)
                Dfs(j, j, startPower);
        }
    }
    return nb == nbCaves;
}

void Solve() {
    scanf("%lld %lld", &nbCaves, &nbTunnels);
    Adj[0].clear();
    for (int i = 1; i < nbCaves; i ++)
    {
        Adj[i].clear();
        scanf("%lld", &Power[i].first);
    }
    for (int i = 1; i < nbCaves; i ++)
    {
        scanf("%lld", &Power[i].second);
    }
    for (int i = 0; i < nbTunnels; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        Adj[-- a].push_back(-- b);
        Adj[b].push_back(a);
    }
    int ans = 0;
    for (int bit = (1 << 30); bit > 0; bit >>= 1)
    {
        if (!Check(ans + bit))
            ans += bit;
    }
    printf("%lld\n", ++ ans);
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