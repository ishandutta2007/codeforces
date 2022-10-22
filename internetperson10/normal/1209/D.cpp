#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct dsu {
    vector<int> par, siz;
    void init(int n) {
        par.resize(n);
        siz.resize(n, 1);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int get(int x) {
        if(par[x] == x) return x;
        return par[x] = get(par[x]);
    }
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if(x == y) return false;
        if(siz[x] > siz[y]) swap(x, y);
        par[x] = y;
        siz[y] += siz[x];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    dsu uf;
    uf.init(1+n);
    int ans = 0;
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        if(!uf.unite(a, b)) ans++;
    }
    cout << ans << '\n';
}