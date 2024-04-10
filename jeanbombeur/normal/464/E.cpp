#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_NODES = (1e5);
const int MOD = (1e9 + 7);
const int LOG = 17;

struct node {
    int left, right;
    bool hasZero;
    long long hash;
};

struct event {
    int value;
    int node;
    int parent;
};

vector <node> Tree;

vector <pair <int, int>> Adj[MAX_NODES];

priority_queue <event> Dijkstra;

int Parent[MAX_NODES];
bool Vu[MAX_NODES];

int nbNodes, nbEdges;
int start, finish;

int Copy(int a) {
    Tree.push_back(Tree[a]);
    return Tree.size() - 1;
}

void Read() {
    scanf("%d %d", &nbNodes, &nbEdges);
    for (int i = 0; i < nbEdges; i ++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        Adj[-- a].push_back({-- b, c});
        Adj[b].push_back({a, c});
    }
    scanf("%d %d\n", &start, &finish);
    start --, finish --;
    return;
}

void Act(int node) {
    Tree[node].hasZero = Tree[Tree[node].left].hasZero | Tree[Tree[node].right].hasZero;
    Tree[node].hash = ((Tree[Tree[node].left].hash + 33) * (Tree[Tree[node].right].hash + 37)) % MOD;
    return;
}

void Setup() {
    Tree.push_back({-1, -1, false, 1});
    for (int i = 1; i < (1 << (LOG + 1)); i ++)
    {
        if (i < (1 << LOG))
            Tree.push_back({2 * i, 2 * i + 1, true, 0});
        else
            Tree.push_back({-1, -1, true, 0});
    }
    for (int i = (1 << LOG) - 1; i; i --)
    {
        Act(i);
    }
    return;
}

bool Add(int node, int left, int right, int target) {
    if (right - left <= 1)
    {
        if (Tree[node].hasZero)
        {
            Tree[node] = Tree[0];
            return true;
        }
        Tree[node] = Tree[1 << LOG];
        return false;
    }
    if (target == left && !Tree[node].hasZero)
    {
        Tree[node] = Tree[(left + (1 << LOG)) / (right - left)];
        return false;
    }
    int mid = (left + right) / 2;
    if (target < mid && Add(Tree[node].left = Copy(Tree[node].left), left, mid, target))
    {
        Act(node);
        return true;
    }
    bool ans = Add(Tree[node].right = Copy(Tree[node].right), mid, right, max(mid, target));
    Act(node);
    return ans;
}

int Ajout(int value, int power) {
    int root = Copy(value);
    Add(root, 0, 1 << LOG, power);
    return root;
}

bool Comp(int a, int b, int h) {
    if (h -- == 0)
        return Tree[a].hasZero && !Tree[b].hasZero;
    if (Tree[Tree[a].right].hash != Tree[Tree[b].right].hash)
        return Comp(Tree[a].right, Tree[b].right, h);
    return Comp(Tree[a].left, Tree[b].left, h);
}

bool operator<(event a, event b) {
    return Comp(b.value, a.value, LOG);
}

long long Exp(int n) {
    long long ans = 1, cur = 2;
    for (; n; n >>= 1)
    {
        if (n & 1)
            ans = (ans * cur) % MOD;
        cur = (cur * cur) % MOD;
    }
    return ans;
}

long long GetValue(int node, int h) {
    if (h -- == 0)
        return Tree[node].hasZero ? 0 : 1;
    return (GetValue(Tree[node].left, h) + GetValue(Tree[node].right, h) * Exp(Exp(h))) % MOD;
}

void Solve() {
    Dijkstra.push({Copy(1), start, -1});
    int sol = -1;
    while (!Dijkstra.empty())
    {
        event a = Dijkstra.top();
        Dijkstra.pop();
        if (!Vu[a.node])
        {
            Parent[a.node] = a.parent;
            if (a.node == finish)
                sol = a.value;
            Vu[a.node] = true;
            for (pair <int, int> dest : Adj[a.node])
            {
                if (!Vu[dest.first])
                    Dijkstra.push({Ajout(a.value, dest.second), dest.first, a.node});
            }
        }
    }
    if (sol < 0)
    {
        printf("-1\n");
        return;
    }
    printf("%lld\n", GetValue(sol, LOG));
    vector <int> Path;
    int cur = finish;
    while (cur >= 0)
    {
        Path.push_back(cur);
        cur = Parent[cur];
    }
    reverse(Path.begin(), Path.end());
    printf("%d\n", (int)Path.size());
    for (int a : Path)
        printf("%d ", ++ a);
    printf("\n");
    return;
}

int main() {
    Read();
    Setup();
    Solve();
    return 0;
}