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

int Order[MAX_NODES];
int cnt = 0;

int Parent[MAX_NODES];

int nbNodes;

int Query(int nb) {
    if (nb < 2)
        return 0;
    if (nb > nbNodes)
        return 1 << 30;
    printf("? %lld ", nb);
    for (int i = 0; i < nb; i ++)
    {
        printf("%lld ", Order[i]);
    }
    cout << endl;
    int ans;
    scanf("%lld", &ans);
    return ans;
}

void Dfs(int node, int parent) {
    Parent[node] = parent + 1;
    Order[cnt ++] = node + 1;
    for (int dest : Adj[node])
    {
        if (dest ^ parent)
            Dfs(dest, node);
    }
    return;
}

void Solve() {
    scanf("%lld", &nbNodes);
    for (int i = 1; i < nbNodes; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        Adj[-- a].push_back(-- b);
        Adj[b].push_back(a);
    }
    Dfs(0, 0);
    int maxi = Query(nbNodes);
    int ans = 0;
    for (int bit = 1 << 9; bit > 0; bit >>= 1)
    {
        if (Query(ans + bit) < maxi)
            ans += bit;
    }
    printf("! %lld %lld", Parent[Order[ans] - 1], Order[ans]);
    cout << endl;
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