#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_ROWS = (3e5);

struct node {
    int dist, id;
};

bool operator<(node a, node b) {
    return a.dist > b.dist;
}

priority_queue <node> Dijkstra;

char Grid[MAX_ROWS];

vector <pair <int, int>> Adj[MAX_ROWS];

int Dist[MAX_ROWS];

int nbRows, nbColumns;
int pRotate, pShift;

int C(int i, int j) {
    return i * nbColumns + j;
}

void Read() {
    scanf("%lld %lld", &nbRows, &nbColumns);
    scanf("%lld %lld", &pRotate, &pShift);
    for (int i = 0; i < nbRows; i ++)
    {
        scanf("%s", Grid + i * nbColumns);
    }
    for (int i = 0; i < nbRows; i ++)
    {
        for (int j = 0; j < nbColumns; j ++)
        {
            int num = C(i, j);
            Dist[num] = 1LL << 60;
            if (Grid[num] == '.')
                Dijkstra.push({0, num});
            if (Grid[num] == 'L')
            {
                if (j + 2 < nbColumns)
                    Adj[C(i, j + 2)].push_back({num, pShift});
                if (i > 0)
                    Adj[C(i - 1, j + 1)].push_back({num, pRotate});
                if (i + 1 < nbRows)
                    Adj[C(i + 1, j + 1)].push_back({num, pRotate});
            }
            if (Grid[num] == 'R')
            {
                if (j > 1)
                    Adj[C(i, j - 2)].push_back({num, pShift});
                if (i > 0)
                    Adj[C(i - 1, j - 1)].push_back({num, pRotate});
                if (i + 1 < nbRows)
                    Adj[C(i + 1, j - 1)].push_back({num, pRotate});
            }
            if (Grid[num] == 'D')
            {
                if (i > 1)
                    Adj[C(i - 2, j)].push_back({num, pShift});
                if (j > 0)
                    Adj[C(i - 1, j - 1)].push_back({num, pRotate});
                if (j + 1 < nbColumns)
                    Adj[C(i - 1, j + 1)].push_back({num, pRotate});
            }
            if (Grid[num] == 'U')
            {
                if (i + 2 < nbRows)
                    Adj[C(i + 2, j)].push_back({num, pShift});
                if (j > 0)
                    Adj[C(i + 1, j - 1)].push_back({num, pRotate});
                if (j + 1 < nbColumns)
                    Adj[C(i + 1, j + 1)].push_back({num, pRotate});
            }
        }
    }
    while (!Dijkstra.empty())
    {
        node a = Dijkstra.top();
        Dijkstra.pop();
        if (Dist[a.id] == 1LL << 60)
        {
            Dist[a.id] = a.dist;
            for (pair <int, int> dest : Adj[a.id])
            {
                Dijkstra.push({a.dist + dest.second, dest.first});
            }
        }
    }
    int ans = 1LL << 60;
    for (int i = 0; i < nbRows; i ++)
    {
        for (int j = 0; j < nbColumns; j ++)
        {
            if (i)
                ans = min(ans, Dist[C(i - 1, j)] + Dist[C(i, j)]);
            if (j)
                ans = min(ans, Dist[C(i, j - 1)] + Dist[C(i, j)]);
        }
    }
    printf("%lld\n", ans == 1LL << 60 ? -1 : ans);
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