#include <bits/stdc++.h>

#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back

using namespace std;

const int inf = 1e9;

struct edge
{
    int from, to;
    int cap, flow;
    edge() {}
    edge(int u, int v, int c)
    {
        from = u, to = v, cap = c, flow = 0;
    }
};

int n;
vector<edge> edges;
vector<vector<int> > g;
vector<int> level;
vector<int> ptr;
int s, t;

void addEdge(int from, int to, int cap)
{
    g[from].pb(sz(edges));
    edges.pb({from, to, cap});
    g[to].pb(sz(edges));
    edges.pb({to, from, 0});
}

int bfs()
{
    level.assign(n, inf);
    ptr.assign(n, 0);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int e : g[v]) {
            if (edges[e].cap > edges[e].flow && level[edges[e].to] == inf) {
                level[edges[e].to] = level[v] + 1;
                q.push(edges[e].to);
            }
        }
    }
    return level[t] != inf;
}

int dfs(int v, int flow)
{
    if (v == t) {
        return flow;
    }
    for (int i = ptr[v]; i < sz(g[v]); ++i) {
        int e = g[v][i];
        if (edges[e].cap > edges[e].flow && level[edges[e].to] == level[v] + 1) {
            int x = dfs(edges[e].to, min(flow, edges[e].cap - edges[e].flow));
            if (x) {
                edges[e].flow += x;
                edges[e ^ 1].flow -= x;
                return x;
            }
        }
        ++ptr[v];
    }
    return 0;
}

int dinic()
{
    int ans = 0;
    int x;
    while (bfs()) {
        while ((x = dfs(s, inf))) {
            ans += x;
        }
    }
    return ans;
}

bool isPrime(int x)
{
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

vector<char> used;
vector<int> tmp;

void solve(int v)
{
    used[v] = true;
    tmp.pb(v);
    for (int e : g[v]) {
        //cout << v << " " << edges[e].to << "\n";
        if (edges[e].flow && !used[edges[e].to] && edges[e].to >= 1 && edges[e].to <= n - 2) {
            solve(edges[e].to);
        }
    }
}

int main()
{

    //ifstream cin("input.txt");

    cin >> n;

    vector<int> a(n);
    int odd = 0;
    vector<int> id(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] & 1) {
            ++odd;
        }
    }

    vector<int> vct(n + 1);

    int x = 1, y = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] & 1) {
            id[i] = x++;
        } else {
            id[i] = odd + y;
            ++y;
        }
        //cout << id[i] << "\n";
        vct[id[i]] = i + 1;
    }

    s = 0, t = n + 1;
    n += 2;
    g.resize(n);

    for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < n - 2; ++j) {
            if ((a[i] & 1) && !(a[j] & 1)) {
                if (isPrime(a[i] + a[j])) {
                    addEdge(id[i], id[j], 1);
                }
            }
        }
    }

    int ss = 0, tt = 0;

    for (int i = 0; i < n - 2; ++i) {
        if (a[i] & 1) {
            addEdge(s, id[i], 2);
            ss += 2;
        } else {
            addEdge(id[i], t, 2);
            tt += 2;
        }
    }

    int ans = dinic();
    if (ans != tt || ans != ss) {
        cout << "Impossible\n";
        return 0;
    }

    used.assign(n - 1, false);
    vector<vector<int> > res;

    for (int i = 0; i < n - 2; ++i) {
        if (!used[i + 1]) {
            tmp.clear();
            solve(i + 1);
            res.pb(tmp);
        }
    }

    cout << sz(res) << "\n";
    for (vector<int>& v : res) {
        cout << sz(v) << " ";
        for (int x : v) {
            cout << vct[x] << " ";
        }
        cout << "\n";
    }

}