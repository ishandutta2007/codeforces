#include <bits/stdc++.h>
 
using namespace std;
 
 
struct Edge{
    int x, y, w;
    Edge(const int &a, const int &b, const int &c):
        x(a), y(b), w(c) {}
    bool operator < (const Edge &t) const {
        if (w != t.w) return  w < t.w;
        return make_pair(x, y) < make_pair(t.x, t.y);
    }
};
 
 
vector<int> p(200010);
vector<long long> sz(200010);
long long ans = 0;
 
 
int find_p(const int &x) {
    return p[x] == x ? x : p[x] = find_p(p[x]);
}
 
void unite(int a, int b) {
    a = find_p(a);
    b = find_p(b);
    if (a == b) {
        return;
    }
    if (rand() & 1) {
        p[b] = a;
        ans += sz[a] * sz[b];
        sz[a] += sz[b];
    }
    else {
        p[a] = b;
        ans += sz[a] * sz[b];
        sz[b] += sz[a];
    }
    // cout << a + 1 << ' ' << b + 1 << ' ' << ans << '\n';
}
 
signed main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> e;
    for (int i = 0; i < n - 1; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        e.emplace_back(x - 1, y - 1, w);
    }
    vector<pair<int, int> > q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i].first;
        q[i].second = i;
    }
    vector<long long> res(m);
    sort(q.begin(), q.end());
    sort(e.begin(), e.end());
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        sz[i] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        int k = n - 1;
        for (int j = cnt; j < n - 1; ++j) {
            if (e[j].w > q[i].first) {
                k = j;
                break;
            }
            unite(e[j].x, e[j].y);
        }
        cnt = k;
        res[q[i].second] = ans;
    }
    for (int i = 0; i < m; ++i) {
        cout << res[i] << ' ';
    }
}