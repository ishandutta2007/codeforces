#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MOD = (998244353);
const int MAX_VALUES = (2e5);


struct event {
    int node;
    int value;
};

bool operator<(event a, event b) {
    return a.value > b.value;
}

int Val[MAX_VALUES];

priority_queue <event> ToPop;

vector <int> Adj[MAX_VALUES];
vector <int> Parents[MAX_VALUES];

int Deg[MAX_VALUES];

int curTime = 0;

int nbNodes, nbEdges;

void RunOnce() {
    vector <int> Flow;
    for (int i = 0; i < nbNodes; i ++)
    {
        if (Val[i])
            Flow.push_back(i);
    }
    for (int i : Flow)
    {
        for (int dest : Adj[i])
            Val[dest] ++;
        Val[i] --;
    }
    if (!Flow.empty())
        curTime ++;
    return;
}

void RunAll(int nb) {
    for (int i = 0; i < nbNodes; i ++)
    {
        Val[i] += (Deg[i] - 1) * nb;
        Val[i] %= MOD;
    }
    return;
}

void Read() {
    scanf("%lld %lld", &nbNodes, &nbEdges);
    for (int i = 0; i < nbNodes; i ++)
    {
        scanf("%lld", &Val[i]);
        Adj[i].clear();
        Parents[i].clear();
        Deg[i] = 0;
    }
    curTime = 0;
    for (int i = 0; i < nbEdges; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        Adj[-- a].push_back(-- b);
        Parents[b].push_back(a);
        Deg[b] ++;
    }
    for (int i = 0; i < nbNodes; i ++)
        RunOnce();
    for (int i = 0; i < nbNodes; i ++)
    {
        if (!Val[i])
            for (int dest : Adj[i])
                Deg[dest] --;
    }
    for (int i = 0; i < nbNodes; i ++)
    {
        if (!Deg[i] && Val[i])
            ToPop.push({i, curTime + Val[i]});
    }
    while (!ToPop.empty())
    {
        event a = ToPop.top();
        ToPop.pop();
        curTime += Val[a.node];
        RunAll(Val[a.node]);
        for (int dest : Adj[a.node])
        {
            if (-- Deg[dest] == 0)
                ToPop.push({dest, curTime + Val[dest]});
        }
    }
    curTime %= MOD;
    printf("%lld\n", (curTime + MOD) % MOD);
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