#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

bool ss[N];

int n;
int d[N], a[N], s[N], sa[N], sb[N], sac[N], sbc[N], pp[N];

vector<int> adj[N];

queue<int> qu;

void dfs2(int u, int p = -1) {
    d[u] = ~p ? d[p] + 1 : 0;
    for (int v : adj[u])
        if (v ^ p) dfs2(v, u);
}

void chk(int u) {
    dfs2(u);
    memset(a, -1, 4 * n);
    for (int i = 0; i < n; ++i) {
        if (a[d[i]] == -1)
            a[d[i]] = adj[i].size();
        else if (a[d[i]] ^ adj[i].size())
            return;
    }
    cout << u + 1;
    exit(0);
}

bool dfs1(int u, int p = -1) {
    if (adj[u].size() > 2) {
        if (ss[u]) return 0;
        int ts;
        if (p == pp[u])
            ts = n - s[u];
        else
            ts = s[p];
        if (ts == sa[u] && !sac[u]) return 1;
        if (ts == sb[u] && !sbc[u]) return 1;
        return 0;
    }
    for (int v : adj[u])
        if (v ^ p) return dfs1(v, u);
}

void dfs3(int u = 0, int p = -1) {
    s[u] = 1;
    pp[u] = p;
    sa[u] = sb[u] = -1;
    for (int v : adj[u]) {
        if (v ^ p) {
            dfs3(v, u);
            s[u] += s[v];
            if (s[v] == sa[u]) {
                sac[u] = 1;
                continue;
            }
            if (s[v] == sb[u]) {
                sbc[u] = 1;
                continue;
            }
            if (sa[u] < 0)
                sa[u] = s[v];
            else if (sb[u] < 0)
                sb[u] = s[v];
            else
                ss[u] = 1;
        }
    }
    if (n - s[u] == sa[u]) {
        sac[u] = 1;
        return;
    }
    if (n - s[u] == sb[u]) {
        sbc[u] = 1;
        return;
    }
    if (sa[u] < 0)
        sa[u] = n - s[u];
    else if (sb[u] < 0)
        sb[u] = n - s[u];
    else
        ss[u] = 1;
}

int dfs4(int u = 0, int p = -1) {
    for (int v : adj[u])
        if (v ^ p) return dfs4(v, u);
    return u;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(d, 0x3f, 4 * n);
    for (int i = 0; i < n; ++i) {
        if (adj[i].size() < 2) {
            d[i] = 0;
            qu.push(i);
        }
    }
    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        for (int v : adj[u]) {
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                qu.push(v);
            }
        }
    }
    int mxd = -1, mxi;
    for (int i = 0; i < n; ++i) {
        if (d[i] > mxd) {
            mxd = d[i];
            mxi = i;
        } else if (d[i] == mxd)
            mxi = -1;
    }
    if (~mxi) chk(mxi);
    int deg = 0;
    for (int i = 0; i < n; ++i) deg = max(deg, (int)adj[i].size());
    if (deg <= 2) chk(dfs4());
    dfs3();
    for (int i = 0; i < n; ++i) {
        if (adj[i].size() > 1) continue;
        if (dfs1(i)) chk(i);
    }
    cout << -1;
}