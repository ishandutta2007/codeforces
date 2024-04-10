#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  I've been looking forward to this

//  <|_|>

const int MAX_VALUES = (2e5);

vector <int> Adj[MAX_VALUES];

pair <int, int> Val[MAX_VALUES];

int nbNodes;

pair <int, int> Dfs(int node) {
    int nb = 0;
    int sum = 0;
    for (int dest : Adj[node])
    {
        pair <int, int> a = Dfs(dest);
        nb += a.first;
        sum += a.second;
    }
    if (sum < Val[node].first)
    {
        nb ++;
        sum = Val[node].second;
    }
    return {nb, min(sum, Val[node].second)};
}

void Solve() {
    scanf("%lld", &nbNodes);
    for (int i = 0; i < nbNodes; i ++)
    {
        Adj[i].clear();
    }
    for (int i = 1; i < nbNodes; i ++)
    {
        int p;
        scanf("%lld", &p);
        Adj[-- p].push_back(i);
    }
    for (int i = 0; i < nbNodes; i ++)
    {
        scanf("%lld %lld", &Val[i].first, &Val[i].second);
    }
    printf("%lld\n", Dfs(0).first);
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