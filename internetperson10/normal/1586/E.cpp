#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> adj;
vector<multiset<int>> adj2;
vector<vector<int>> cyc;
vector<pair<int, int>> ques;
vector<int> path, path2;
vector<bool> taken;

int edge_erase(int x, int y) {
    auto it = adj2[x].find(y);
    adj2[x].erase(it);
    it = adj2[y].find(x);
    adj2[y].erase(it);
    return y;
}

bool dfs(int x, int y) {
    taken[x] = true;
    if(x == y) {
        path.push_back(x);
        return true;
    }
    for(int a : adj[x]) {
        if(taken[a]) continue;
        if(dfs(a, y)) {
            path.push_back(x);
            return true;
        }
    }
    return false;
}

struct dsu {
    vector<int> siz, par;
    void init(int n) {
        siz.resize(n, 1);
        par.resize(n);
        for(int i = 0; i < par.size(); i++) par[i] = i;
    }
    int get(int x) {
        if(par[x] == x) return x;
        return par[x] = get(par[x]);
    }
    bool unite(int x, int y) {
        x = get(x); y = get(y);
        if(x == y) return false;
        if(siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    adj2.resize(n+1);
    taken.resize(n+1);
    dsu uf;
    uf.init(n+1);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(uf.unite(x, y)) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        adj2[x].insert(y);
        adj2[y].insert(x);
        ques.push_back({x, y});
    }
    int k = 0;
    for(int i = 1; i <= n; i++) {
        if(adj2[i].size()%2) k++;
    }
    if(k) {
        cout << "NO\n" << k/2 << '\n';
    }
    else {
        cout << "YES\n";
        for(auto p : ques) {
            dfs(p.first, p.second);
            cout << path.size() << '\n';
            reverse(path.begin(), path.end());
            for(int i : path) cout << i << ' ';
            cout << '\n';
            vector<int>().swap(path);
            for(int i = 0; i < taken.size(); i++) taken[i] = false;
        }
    }
}