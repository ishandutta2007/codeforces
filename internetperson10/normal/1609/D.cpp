#include <bits/stdc++.h>
typedef long long ll;

using namespace std;


struct dsu {
    vector<int> par, siz;
    int g;
    void init(int n) {
        g = 1;
        vector<int>().swap(par);
        vector<int>().swap(siz);
        par.resize(n);
        siz.resize(n, 1);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int get(int x) {
        if(par[x] == x) return x;
        return x = get(par[x]);
    }
    int best() {
        vector<int> siz_sor = siz;
        sort(siz_sor.rbegin(), siz_sor.rend());
        int ans = 0;
        for(int i = 0; i < g; i++) {
            ans += siz_sor[i];
        }
        return ans;
    }
    int unite(int x, int y) {
        x = get(x); y = get(y);
        if(x == y) {
            g++;
            return best(); 
        }
        if(siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        siz[y] = 0;
        return best(); 
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    dsu uf;
    uf.init(n);
    int g = 0;
    while(q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << uf.unite(x, y) - 1 << '\n';
    }
}