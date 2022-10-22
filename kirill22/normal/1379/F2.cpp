#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

pii inv(pii a) {
    if (a.fi % 2 == 1) {
        return {a.fi + 1, a.se + 1};
    }
    return {a.fi - 1, a.se - 1};
}

vector<bool> t;
vector<int> a, b;

void merge(int v, int l, int r) {
    t[v] = (t[v * 2 + 1] && t[v * 2 + 2]);
    if (a[v * 2 + 1] <= b[v * 2 + 2]) t[v] = 0;
    a[v] = min(a[v * 2 + 1], a[v * 2 + 2]);
    b[v] = max(b[v * 2 + 1], b[v * 2 + 2]);
}

void update(int v, int l, int r, int i, int x, int y) {
    //debug(v, l, r, i, x, y);
    if (l + 1 == r) {
        a[v] = x;
        b[v] = y;
        t[v] = (x > y);
        return;
    }
    int m = (l + r) / 2;
    if (i < m) update(v * 2 + 1, l, m, i, x, y);
    else update(v * 2 + 2, m, r, i, x, y);
    merge(v, l, r);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    t.resize(4 * n, 1);
    a.resize(4 * n, 1e9);
    b.resize(4 * n, -1e9);
    set<int> c[n], d[n];
    for (int i = 0; i < n; i++) {
        c[i].insert(1e9);
        d[i].insert(-1e9);
    }
    for (int test = 0; test < q; test++) {
        pii x;
        cin >> x.fi >> x.se;
        x = inv(x);
        if (x.fi % 2 == 0) {
            if (c[x.fi / 2 - 1].find(x.se / 2 - 1) != c[x.fi / 2 - 1].end()) {
                c[x.fi / 2 - 1].erase(x.se / 2 - 1);
            }
            else {
                c[x.fi / 2 - 1].insert(x.se / 2 - 1);
            }
        }
        else {
            if (d[x.fi / 2].find(x.se / 2) != d[x.fi / 2].end()) {
                d[x.fi / 2].erase(x.se / 2);
            }
            else {
                d[x.fi / 2].insert(x.se / 2);
            }
        }
        update(0, 0, n, (x.fi -1) / 2, *c[(x.fi -1) / 2].begin(), *d[(x.fi -1) / 2].rbegin());
        if (t[0] == 1) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}