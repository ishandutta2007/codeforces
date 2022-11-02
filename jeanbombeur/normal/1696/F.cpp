#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_NODES = (100);

int Link[MAX_NODES][MAX_NODES][MAX_NODES];

vector <pair <int, int>> Adj[MAX_NODES][MAX_NODES];
int Seen[MAX_NODES][MAX_NODES];

vector <pair <int, int>> Compo;

int Deg[MAX_NODES];

int Dist[MAX_NODES][MAX_NODES];

char In[MAX_NODES + 1];

int nbNodes;

void Sz(pair <int, int> node) {
    Seen[node.first][node.second] = 1;
    Compo.push_back(node);
    for (pair <int, int> dest : Adj[node.first][node.second])
    {
        if (!Seen[dest.first][dest.second])
            Sz(dest);
    }
    return;
}

int CheckTree() {
    for (int i = 0; i < nbNodes; i ++)
    {
        Deg[i] = 0;
    }
    for (pair <int, int> edge : Compo)
    {
        Deg[edge.first] ++;
        Deg[edge.second] ++;
    }
    for (int i = 0; i < nbNodes; i ++)
    {
        if (!Deg[i])
            return 0;
    }
    for (int i = 0; i < nbNodes; i ++)
    {
        for (int j = 0; j < nbNodes; j ++)
            Dist[i][j] = MAX_NODES;
        Dist[i][i] = 0;
    }
    for (pair <int, int> edge : Compo)
    {
        Dist[edge.first][edge.second] = Dist[edge.second][edge.first] = 1;
    }
    for (int k = 0; k < nbNodes; k ++)
    {
        for (int i = 0; i < nbNodes; i ++)
        {
            for (int j = 0; j < nbNodes; j ++)
            {
                Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
            }
        }
    }
    for (int i = 0; i < nbNodes; i ++)
    {
        for (int j = 1; j < nbNodes - i; j ++)
        {
            for (int k = 0; k < nbNodes; k ++)
            {
                if (Link[i][j][k] != (Dist[i][k] == Dist[i + j][k]))
                    return 0;
            }
        }
    }
    return 1;
}

void Read() {
    scanf("%lld", &nbNodes);
    for (int i = 0; i < nbNodes; i ++)
    {
        for (int j = i + 1; j < nbNodes; j ++)
        {
            Adj[i][j].clear();
            Seen[i][j] = 0;
        }
    }
    for (int i = 0; i < nbNodes; i ++)
    {
        for (int j = 1; j < nbNodes - i; j ++)
        {
            scanf("%s", In);
            for (int k = 0; k < nbNodes; k ++)
            {
                if (In[k] == '1')
                {
                    Adj[min(i, k)][max(i, k)].push_back({min(i + j, k), max(i + j, k)});
                    Adj[min(i + j, k)][max(i + j, k)].push_back({min(i, k), max(i, k)});
                }
                Link[i][j][k] = In[k] == '1';
            }
        }
    }
    for (int i = 0; i < nbNodes; i ++)
    {
        for (int j = i + 1; j < nbNodes; j ++)
        {
            if (!Seen[i][j])
            {
                Compo.clear();
                Sz({i, j});
                if ((int)Compo.size() == nbNodes - 1 && CheckTree())
                {
                    printf("Yes\n");
                    for (pair <int, int> edge : Compo)
                    {
                        printf("%lld %lld\n", ++ edge.first, ++ edge.second);
                    }
                    return;
                }
            }
        }
    }
    printf("No\n");
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