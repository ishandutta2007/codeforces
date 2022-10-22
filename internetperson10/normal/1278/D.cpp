#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct dsu {
    vector<int> par, siz;
    int connComps;
    dsu(int n) {
        par.resize(n);
        siz.resize(n, 1);
        for(int i = 0; i < n; i++) par[i] = i;
        connComps = n;
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
        connComps--;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> updates(2*n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        updates[x-1] = i+1;
        updates[y-1] = -i-1;
        a[i] = x-1;
        b[i] = y-1;
    }
    int edgeNum = 0;
    dsu uf(n);
    set<pair<int, int>> active; // {index of start point, index of edge
    for(int i = 0; i < 2*n && edgeNum < n; i++) {
        int g = updates[i];
        if(g > 0) {
            g--;
            active.insert({i, g});
        }
        else {
            g = -g-1;
            auto it = active.end();
            it--;
            while((*it).first > a[g]) {
                edgeNum++;
                uf.unite(g, (*it).second);
                if(it == active.begin()) break;
                it--;
            }
            active.erase({a[g], g});
        }
    }
    if(edgeNum >= n || uf.connComps != 1) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}