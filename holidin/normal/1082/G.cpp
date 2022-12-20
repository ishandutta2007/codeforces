#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1;
const int LogFlow = 30;
const int inf = 1e9 + 5;

struct edge {
    int p, a, b, f, c;
};

vector <int> e[N];
edge w[N];
bool used[N];
int d[N], top = 0;
int t[LogFlow];

void create_edge(int a, int b, int c) {
    ++top;
    e[a].push_back(top);
    w[top] = {top + 1, a, b, 0, c};
    ++top;
    e[b].push_back(top);
    w[top] = {top - 1, b, a, 0, 0};
}

bool bfs(int ist, int st, int n, int mn) {
    int i, j;
    for (i = 1; i <= n; ++i)
        d[i] = inf;
    d[ist] = 0;
    vector <int> v;
    v.push_back(ist);
    for (i = 0; i < v.size(); ++i)
    for (j = 0; j < e[v[i]].size(); ++j)
    if (d[w[e[v[i]][j]].b] == inf && w[e[v[i]][j]].c - w[e[v[i]][j]].f >= mn) {
        v.push_back(w[e[v[i]][j]].b);
        d[w[e[v[i]][j]].b] = d[v[i]] + 1;
    }
    return (d[st] != inf);
}

bool dfs(int u, int st, int mn) {
    if (u == st)
        return true;
    for (int i = 0; i < e[u].size(); ++i)
    if (!used[w[e[u][i]].b] && d[w[e[u][i]].b] == d[u] + 1 && w[e[u][i]].c - w[e[u][i]].f >= mn)
        if (dfs(w[e[u][i]].b, st, mn)) {
            w[e[u][i]].f += mn;
            w[w[e[u][i]].p].f -= mn;
            return true;
        }
    used[u] = true;
    return false;
}

long long dinic(int ist, int st, int n) {
    t[0] = 1;
    for (int i = 1; i < LogFlow; ++i)
        t[i] = t[i - 1] * 2;
    for (int i = LogFlow - 1; i >= 0; --i)
    while (true) {
        if (!bfs(ist, st, n, t[i]))
            break;
        for (int j = 1; j <= n; ++j)
            used[j] = false;
        while (dfs(ist, st, t[i]));
    }
    long long flow = 0;
    for (int i = 1; i <= top; ++i)
    if (w[i].b == st)
        flow += w[i].f;
    return flow;
}

int main() {
    int i, j, n, k, a, b, c;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int ist = 1, st = n + k + 2;
    for (i = 1; i <= n; ++i) {
        cin >> j;
        create_edge(ist, i + 1, j);
    }
    long long sumw = 0;
    for (i = 1; i <= k; ++i) {
        cin >> a >> b >> c;
        create_edge(a + 1, n + i + 1, inf);
        create_edge(b + 1, n + i + 1, inf);
        create_edge(n + i + 1, st, c);
        sumw += c;
    }
    //why it is working???
    long long flow = dinic(ist, st, st);
    cout << sumw - flow;
}