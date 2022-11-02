#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

vector<vector<int>> g, h, ng;

vector<int> rk, p;

int getp(int a) { return a == p[a] ? a : p[a] = getp(p[a]); }

void unite(int a, int b) {
    a = getp(a), b = getp(b);
    if (a == b) return;
    if (rk[a] < rk[b]) swap(a, b);
    rk[a] += rk[b];
    p[b] = a;
}

vector<vector<int>> comp;

vector<int> ord;
vector<int> used;
bool fl;

void ts(int v, const vector<vector<int>> &g) {
    used[v] = 1;
    for (int u : g[v]) {
        if (used[u] == 0)
            ts(u, g);
        else if (used[u] == 1)
            fl = false;
        if (!fl) return;
    }
    ord.push_back(v);
    used[v] = 2;
}

bool topsort(const vector<vector<int>> &g) {
    int n = g.size();
    used.assign(n, 0);
    ord.clear();
    fl = true;
    forn(i, n) if (!used[i]) {
        ts(i, g);
        if (!fl) return false;
    }
    reverse(ord.begin(), ord.end());
    return true;
}

vector<int> pos;

bool dfs(int v) {
    for (int u : g[v]) {
        if (pos[u] < pos[v]) return false;
        if (!dfs(u)) return false;
    }
    return true;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    g.resize(n);
    h.resize(n);
    ng.resize(n);
    int rt = -1;
    forn(i, n) {
        int p;
        scanf("%d", &p);
        --p;
        if (p == -1)
            rt = i;
        else
            g[p].push_back(i);
    }
    rk.assign(n, 1);
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    forn(i, m) {
        int v, u;
        scanf("%d%d", &v, &u);
        --v, --u;
        h[v].push_back(u);
        unite(v, u);
    }
    if (!topsort(h)) {
        puts("0");
        return 0;
    }
    auto ord1 = ord;
    vector<int> pos1(n);
    forn(i, n) pos1[ord1[i]] = i;
    forn(v, n) for (int u : g[v]) if (getp(v) != getp(u)) ng[getp(v)].push_back(
        getp(u));
    if (!topsort(ng)) {
        puts("0");
        return 0;
    }
    comp.resize(n);
    forn(i, n) comp[getp(i)].push_back(i);
    vector<int> fin;
    for (int it : ord) {
        sort(comp[it].begin(), comp[it].end(),
             [&](int v, int u) { return pos1[v] < pos1[u]; });
        for (int v : comp[it]) fin.push_back(v);
    }
    pos.resize(n);
    forn(i, n) pos[fin[i]] = i;
    if (!dfs(rt)) {
        puts("0");
        return 0;
    }
    for (int v : fin) printf("%d ", v + 1);
    puts("");
}