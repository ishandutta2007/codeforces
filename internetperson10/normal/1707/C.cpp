#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct dsu {
    vector<int> par;
    dsu(int n) {
        par.resize(n);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int get(int x) {
        if(par[x] == x) return x;
        return par[x] = get(par[x]);
    }
    bool unite(int x, int y) {
        x = get(x); y = get(y);
        if(x == y) return false;
        par[x] = y;
        return true;
    }
};

vector<vector<int>> adj;
vector<int> par, dep, sub;
vector<pair<int, int>> bad_edges;
int lift[20][100001];
bool taken[100001];

void dfs(int x) {
    for(int ch : adj[x]) {
        if(ch == par[x]) continue;
        dep[ch] = dep[x] + 1;
        par[ch] = x;
        dfs(ch);
    }
}

int go_up(int x, int k) {
    if(k > dep[x]) return -1;
    for(int i = 0; i < 20; i++) {
        if((1 << i) & k) x = lift[i][x];
    }
    return x;
}

int get_lca(int x, int y) {
    if(dep[x] > dep[y]) swap(x, y);
    for(int i = 0; i < 20; i++) {
        if((1 << i) & (dep[y] - dep[x])) y = lift[i][y];
    }
    if(x == y) return x;
    for(int i = 19; i >= 0; i--) {
        if(lift[i][x] != -1) {
            if(lift[i][x] != lift[i][y]) {
                x = lift[i][x];
                y = lift[i][y];
            }
        }
    }
    return par[x];
}

void get_sum(int x) {
    if(x == 0) return;
    if(taken[x]) return;
    taken[x] = true;
    get_sum(par[x]);
    sub[x] += sub[par[x]];
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    adj.resize(n);
    par.resize(n); dep.resize(n); sub.resize(n);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(uf.unite(x, y)) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        else {
            bad_edges.push_back({x, y});
        }
    }
    dep[0] = 0;
    par[0] = -1;
    dfs(0);
    for(int i = 0; i < n; i++) {
        taken[i] = false;
        lift[0][i] = par[i];
    }
    for(int i = 1; i < 20; i++) {
        for(int j = 0; j < n; j++) {
            if(lift[i-1][j] == -1) lift[i][j] = -1;
            else lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }
    for(auto p : bad_edges) {
        int x, y;
        tie(x, y) = p;
        if(dep[x] > dep[y]) swap(x, y);
        int l = get_lca(x, y);
        if(x == l) {
            sub[go_up(y, dep[y] - dep[x] - 1)]++;
            sub[y]--;
        }
        else {
            sub[x]--;
            sub[y]--;
            sub[0]++;
        }
    }
    for(int i = 0; i < n; i++) {
        get_sum(i);
        cout << !((bool)(sub[i]));
    }
    cout << '\n';
}