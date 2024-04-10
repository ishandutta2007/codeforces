#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<pair<ll, pair<int, int>>> edges;

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

vector<ll> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll mi = 1e13;
    int nu = -1;
    nums.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(nums[i] < mi) {
            mi = nums[i];
            nu = i;
        }
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        x--; y--;
        if(w < nums[x] + nums[y]) edges.push_back({w, {x, y}});
    }
    for(int i = 0; i < n; i++) {
        if(i != nu) {
            edges.push_back({nums[i] + mi, {i, nu}});
        }
    }
    sort(edges.begin(), edges.end());
    dsu uf(n);
    ll ans = 0;
    for(auto p : edges) {
        if(uf.unite(p.second.first, p.second.second)) ans += p.first;
    }
    cout << ans << '\n';
}