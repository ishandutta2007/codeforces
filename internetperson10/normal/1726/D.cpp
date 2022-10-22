#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct dsu {
    vector<int> par, siz;
    dsu(int n) {
        par.resize(n);
        siz.resize(n, 1);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int get(int x) {
        if(x == par[x]) return x;
        return get(par[x]);
    }
    bool unite(int x, int y) {
        x = get(x); y = get(y);
        if(x == y) return false;
        if(siz[x] > siz[y]) swap(x, y);
        par[x] = y;
        siz[y] += siz[x];
        return true;
    }
};

vector<vector<int>> adj;
vector<int> dep;

void dfs(int x, int par = -1, int d = 0) {
    dep[x] = d;
    for(int ch : adj[x]) {
        if(ch == par) continue;
        dfs(ch, x, d+1);
    }
}

void solve() {
    int n, m, bad_count = 0;
    cin >> n >> m;
    dsu uf(n);
    adj.resize(n);
    dep.resize(n, -1);
    vector<int> x(m), y(m);
    vector<bool> bad(m);
    set<int> s;
    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
        if(!uf.unite(x[i], y[i])) {
            bad[i] = true;
            bad_count++;
            s.insert(x[i]);
            s.insert(y[i]);
        }
        else {
            adj[x[i]].push_back(y[i]);
            adj[y[i]].push_back(x[i]);
        }
    }
    if(bad_count == 3 && s.size() == 3) {
        int bad_num = *(s.begin());
        dfs(bad_num);
        int rem = *(++s.begin());
        for(int i = 0; i < m; i++) {
            if(bad[i]) continue;
            if(y[i] == rem) swap(x[i], y[i]);
            if(x[i] != rem) continue;
            if(dep[y[i]] < dep[x[i]]) {
                bad[i] = true;
                break;
            }
        }
        for(int i = 0; i < m; i++) {
            if(rem + bad_num == x[i] + y[i]) {
                bad[i] = false;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        cout << bad[i];
    }
    cout << '\n';
    adj.clear();
    dep.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}