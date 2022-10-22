#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<pair<int, int>>> adj;

struct dsu {
    vector<int> par, siz, val;
    void init(int n) {
        vector<int>().swap(par);
        vector<int>().swap(siz);
        vector<int>().swap(val);
        par.resize(n);
        siz.resize(n);
        val.resize(n);
        for(int i = 0; i < n; i++) {
            par[i] = i;
            siz[i] = 1;
            val[i] = 0;
        }
    }
    int get(int x) {
        if(par[x] == x) return x;
        get(par[x]);
        val[x] ^= (val[par[x]]);
        return par[x] = get(par[x]);
    }
    bool unite(int x, int y, int c) {
        //cout << "Uniting " << x << ' ' << y << ' ' << c << '\n';
        get(x);
        get(y);
        int v1 = val[x];
        int v2 = val[y];
        //cout << v1 << ' ' << v2 << '\n';
        x = get(x); y = get(y);
        if(x == y) {
            if(v1 ^ v2 == c) return true;
            //cout << "Mismatch: " << x << ' ' << y << ' ' << c << '\n';
            return false;
        }
        if(siz[x] > siz[y]) swap(x, y);
        par[x] = y;
        siz[y] += siz[x];
        val[x] = (c ^ v1 ^ v2);
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, e;
        cin >> n >> e;
        vector<vector<pair<int, int>>>().swap(adj);
        adj.resize(n+1);
        dsu uf;
        uf.init(n+1);
        bool ok = true;
        for(int i = 1; i < n; i++) {
            int x, y, c;
            cin >> x >> y >> c;
            adj[x].push_back({y, c});
            adj[y].push_back({x, c});
            if(c > -1) {
                ok &= uf.unite(x, y, (__builtin_popcount(c))%2);
            }
        }
        for(int i = 0; i < e; i++) {
            int x, y, c;
            cin >> x >> y >> c;
            ok &= uf.unite(x, y, c);
        }
        if(!ok) {
            cout << "NO\n";
            continue;
        }
        else {
            cout << "YES\n";
            for(int i = 1; i <= n; i++) uf.get(i);
            for(int i = 0; i < adj.size(); i++) {
                for(auto p : adj[i]) {
                    if(i < p.first) {
                        cout << i << ' ' << p.first << ' ';
                        if(p.second > -1) cout << p.second << '\n';
                        else cout << (uf.val[i] ^ uf.val[p.first]) << '\n';
                    }
                }
            }
        }
    }
}