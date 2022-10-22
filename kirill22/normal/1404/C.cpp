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

vector<int> t, d;

void push(int v, int l, int r) {
    if (l + 1 != r) {
        d[v * 2 + 1] += d[v];
        d[v * 2 + 2] += d[v];
    }
    t[v] += d[v];
    d[v] = 0;
}

void update(int v, int l, int r, int l1, int r1, int x) {
    push(v, l, r);
    if (l1 >= r || l >= r1) return;
    if (l1 <= l && r <= r1) {
        d[v] += x;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    update(v * 2 + 1, l, m, l1, r1, x);
    update(v * 2 + 2, m, r, l1, r1, x);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

int get(int v, int l, int r, int x) {
    push(v, l, r);
    if (l + 1 == r) {
        if (t[v] >= x) return l;
        return -1;
    }
    int m = (l + r) / 2;
    push(v * 2 + 2, m, r);
    if (t[v * 2 + 2] >= x) return get(v * 2 + 2, m, r, x);
    else return get(v * 2 + 1, l, m, x);
}

int get2(int v, int l, int r, int i) {
    push(v, l, r);
    if (l + 1 == r) return t[v];
    int m = (l + r) / 2;
    if (i < m) return get2(v * 2 + 1, l, m, i);
    else return get2(v * 2 + 2, m, r, i);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), ans(q);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pii> query[n];
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        query[n - y - 1].pb({x, i});
    }
    t.resize(4 * n, 0);
    d.resize(4 * n, 0);
    for (int r = 0; r < n; r++) {
        a[r] = r - (a[r] - 1);
        if (a[r] >= 0) {
            int pos = min(get(0, 0, n, a[r]), r);
            update(0, 0, n, 0, pos + 1, 1);
        }
        for (auto el : query[r]) {
            ans[el.se] = get2(0, 0, n, el.fi);
        }
    }
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}