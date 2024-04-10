#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_NODES = (4001);

char Adj[MAX_NODES][MAX_NODES];

int Dsu[MAX_NODES];

int Deg[MAX_NODES];

int Vu[MAX_NODES];
vector <int> Path;

int nbNodes;

int Find(int a) {
    return Dsu[a] < 0 ? a : Dsu[a] = Find(Dsu[a]);
}

void Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b)
        return;
    if (Dsu[a] > Dsu[b])
        swap(a, b);
    Dsu[a] += Dsu[b];
    Dsu[b] = a;
    return;
}

void Dfs(int node) {
    Path.push_back(node);
    Vu[node] = 1;
    for (int i = 0; i < nbNodes; i ++)
    {
        if (!Vu[i] && Adj[node][i] == '1')
            Dfs(i);
    }
    return;
}

bool Check(int node) {
    Path.clear();
    fill_n(Vu, nbNodes, 0);
    Dfs(node);
    int sz = - Dsu[node];
    while (Path.size() && Deg[Path.back()] == sz)
        Path.pop_back();
    if (Path.size())
    {
        printf("1\n%lld\n", Path.back() + 1);
        return true;
    }
    return false;
}

void Read() {
    scanf("%lld", &nbNodes);
    fill_n(Dsu, nbNodes, -1);
    fill_n(Deg, nbNodes, 0);
    for (int i = 0; i < nbNodes; i ++)
    {
        scanf("%s", Adj[i]);
        for (int j = 0; j < nbNodes; j ++)
        {
            if (Adj[i][j] == '1')
            {
                Union(i, j);
                Deg[i] ++;
            }
        }
        if (Deg[i])
            Deg[i] ++;
    }
    int nb = 0;
    int mini = Find(0);
    for (int i = 0; i < nbNodes; i ++)
    {
        nb += Dsu[i] < 0;
        if (Dsu[i] < 0 && Dsu[i] > Dsu[mini])
            mini = i;
    }
    if (nb == 1)
    {
        printf("0\n");
        return;
    }
    for (int i = 0; i < nbNodes; i ++)
    {
        if (Dsu[i] < 0 && Check(i))
            return;
    }
    if (nb >= 3)
    {
        for (int i = 0; i < nbNodes; i ++)
        {
            for (int j = 0; j < nbNodes; j ++)
            {
                if (Find(i) != Find(j))
                {
                    printf("2\n%lld %lld\n", i + 1, j + 1);
                    return;
                }
            }
        }
    }
    printf("%lld\n", - Dsu[mini]);
    for (int i = 0; i < nbNodes; i ++)
    {
        if (Find(i) == mini)
            printf("%lld ", i + 1);
    }
    printf("\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}