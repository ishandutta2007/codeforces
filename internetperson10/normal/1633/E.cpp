#include <bits/stdc++.h>
#define int long long
typedef long long ll;

using namespace std;

struct dsu {
    vector<int> par, siz;
    dsu(int n) {
        vector<int>().swap(par);
        vector<int>().swap(siz);
        par.resize(n);
        siz.resize(n, 1);
        for(int i = 0; i < n; i++) par[i] = i;
    }
    int get(int x) {
        if(par[x] == x) return x;
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

const ll BIG = 1234567890;

vector<pair<int, pair<int, int>>> edges;
vector<pair<int, pair<int, int>>> sorted;
vector<ll> bounds, vals, lesses;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    edges.resize(m);
    sorted.resize(m);
    for(int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        edges[i] = {c, {x, y}};
    }
    sort(edges.begin(), edges.end());
    bounds.push_back(-1);
    for(int i = 0; i < m; i++) {
        for(int j = i; j < m; j++) {
            bounds.push_back((edges[i].first + edges[j].first + 1) / 2);
        }
    }
    sort(bounds.begin(), bounds.end());
    bounds.erase(unique(bounds.begin(), bounds.end()), bounds.end());
    vals.resize(bounds.size());
    lesses.resize(bounds.size());
    for(int i = 0; i < bounds.size(); i++) {
        dsu uf(n);
        for(int j = 0; j < m; j++) {
            sorted[j] = {abs(edges[j].first - bounds[i]), edges[j].second};
            if(bounds[i] >= edges[j].first) sorted[j].second.first += BIG;
        }
        sort(sorted.begin(), sorted.end());
        ll ans = 0;
        for(int j = 0; j < m; j++) {
            int x, y;
            tie(x, y) = sorted[j].second;
            bool small = false;
            if(x >= BIG) {
                x -= BIG;
                small = true;
            }
            if(uf.unite(x, y)) {
                ans += sorted[j].first;
                lesses[i] += small;
            }
        }
        vals[i] = ans;
    }
    ll ans = 0;
    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    vector<ll> q(k);
    for(int i = 0; i < p; i++) cin >> q[i];
    for(int i = p; i < k; i++) q[i] = ((ll)(q[i-1]) * (ll)a + b) % c;
    for(int i = 0; i < k; i++) {
        int l = 0, r = bounds.size();
        while(l != r - 1) {
            int mid = (l + r) / 2;
            if(bounds[mid] <= q[i]) l = mid;
            else r = mid;
        }
        ll currAns = vals[l] + (ll)(bounds[l] - q[i]) * (ll)((n - 1) - 2 * (lesses[l]));
        ans ^= currAns;
    }
    cout << ans << '\n';
}