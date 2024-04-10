#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define fi first
#define se second

int n, l, w;
long long ans = 0;

int sz[100000], ban[100000], h[100000], dist[100000];
vector<pii> g[100000];

void get(int v, int pr) {
    sz[v] = 1;
    for (auto x : g[v]) {
        if (x.fi != pr && !ban[x.fi]) {
            get(x.fi, v);
            sz[v] += sz[x.fi];
        }
    }
}

int centr(int v, int pr, int n) {
    for (auto x : g[v]) {
        if (x.fi != pr && !ban[x.fi]) {
            if (sz[x.fi] > n / 2) {
                return centr(x.fi, v, n);
            }
        }
    }
    return v;
}

void solve2(int v, int pr, int d, int sw, int root) {
    h[v] = d;
    dist[v] = sw;
    if (v != root && d <= l && sw <= w) ans++;
    for (auto x : g[v]) {
        if (x.fi != pr && !ban[x.fi]) {
            solve2(x.fi, v, d + 1, x.se + sw, root);
        }
    }
}

vector<int> comp, st;

void flex(int v, int pr) {
    comp.push_back(v);
    st.push_back(v);
    for (auto x : g[v]) {
        if (!ban[x.fi] && x.fi != pr) flex(x.fi, v);
    }
}

vector<int> ft;

int get(int x) {
    return (x < 0 ? 0 : get((x & (x + 1)) - 1) + ft[x]);
}

void update(int i, int x) {
    while (i < ft.size()) ft[i] += x, i = (i | (i + 1));
}

void Kirill(vector<int> v, int p) {
    sort(v.begin(), v.end(), [&] (int x, int y) {
         return dist[x] < dist[y];
         });
    vector<int> tmp;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        while (tmp.size() > 0 && dist[tmp.back()] > w - dist[v[i]]) {
            update(h[tmp.back()], -1);
            tmp.pop_back();
        }
        ans += p * get(min(l - h[v[i]], (int) ft.size() - 1));
        tmp.push_back(v[i]);
        update(h[v[i]], 1);
    }
    for (auto x : tmp) update(h[x], -1);
}

void solve(int v) {
    st.clear();
    ft.clear();
    get(v, -1);
    v = centr(v, -1, sz[v]);
    solve2(v, -1, 0, 0, v);
    ft.resize(sz[v]);
    int cnt = 0;
    for (auto x : g[v]) {
        if (ban[x.fi]) continue;
        flex(x.fi, v);
        Kirill(comp, -1);
        comp.clear();
    }
    Kirill(st, 1);
    ban[v] = true;
    for (auto x : g[v]) {
        if (!ban[x.fi]) solve(x.fi);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> w;
    for (int i = 1; i < n; i++) {
        int x, d;
        cin >> x >> d;
        x--;
        g[x].push_back({i, d});
        g[i].push_back({x, d});
    }
    solve(0);
    cout << ans;
}