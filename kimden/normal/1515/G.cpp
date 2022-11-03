#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int n, m;
vector<vector<pii>> g, gt;
int mkd[200200];
int com[200200];
ll dist[200200];
vector<ll> value;
vector<int> order;

ll gcd(ll x, ll y) {
    if (x == 0 || y == 0)
        return x + y;
    return gcd(y, x % y);
}

void dfs(int v) {
    mkd[v] = 1;
    for (auto& p: g[v]) {
        int u = p.first;
        int l = p.second;
        if (mkd[u] == 0) {
            dfs(u);
        }
    }
    mkd[v] = 2;
    order.push_back(v);
}

void dfs2(int v, int c, ll d = 0) {
    com[v] = c;
    mkd[v] = 1;
    dist[v] = d;
    for (auto& p: gt[v]) {
        int u = p.first;
        int l = p.second;
        if (mkd[u] == 0) {
            dfs2(u, c, d + l);
        } else if (mkd[u] == 1) {
            value[c] = gcd(value[c], d + l - dist[u]);
        } else if (mkd[u] == 2 && com[u] == com[v]) {
            value[c] = gcd(value[c], d + l - dist[u]);
        }
    }
    mkd[v] = 2;
}

void scc() {
    fill(mkd, mkd + n, 0);
    for (int i = 0; i < n; ++i) {
        if (mkd[i] == 0) {
            dfs(i);
        }
    }
    reverse(all(order));
    fill(mkd, mkd + n, 0);
    fill(com, com + n, -1);
    fill(dist, dist + n, 0);
    int comp = 0;
    for (int i: order) {
        if (mkd[i] == 0) {
            value.push_back(0);
            dfs2(i, comp);
            ++comp;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    g.resize(n);
    gt.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        --a;
        --b;
        g[a].emplace_back(b, l);
        gt[b].emplace_back(a, l);
    }
    scc();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int v, s, t;
        cin >> v >> s >> t;
        --v;
        if (s % gcd(t, value[com[v]]) == 0) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }




}