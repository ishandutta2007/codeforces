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
        return par[x] = get(par[x]);
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

int ask(int x) {
    cout << "? " << x+1 << endl;
    int y;
    cin >> y;
    return y-1;
}

void solve() {
    int n;
    cin >> n;
    dsu uf(n);
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    while(true) {
        int ma = -1, be = -1;
        for(int i = 0; i < n; i++) {
            if(v[i] > ma) {
                ma = v[i];
                be = i;
            }
        }
        if(be == -1) break;
        v[be] = -2;
        while(ma--) {
            int x = ask(be);
            uf.unite(x, be);
            if(v[x] == -2) break;
            else v[x] = -2;
        }
    }
    cout << "! ";
    for(int i = 0; i < n; i++) {
        cout << uf.get(i) + 1 << ' ';
    }
    cout << endl;
}

int main() {
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}