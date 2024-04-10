#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

vector<int> a, t;
int LOL = 0;

void build(int v, int l, int r) {
    if (l + 1 == r) {
        t[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

void update(int v, int l, int r, int i, int x) {
    if (l + 1 == r) {
        t[v] = x;
        return;
    }
    int m = (l + r) / 2;
    if (i < m) update(v * 2 + 1, l, m, i, x);
    else update(v * 2 + 2, m, r, i, x);
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

int get(int v, int l, int r, int l1, int r1, int d) {
    if (l1 >= r || l >= r1) return 0;
    if (l1 <= l && r <= r1) return t[v];
    int m = (l + r) / 2;
    bool is_flex = false;
    if (((1 << d) & LOL) > 0) is_flex = true;
    if (is_flex) return get(v * 2 + 1, m, r, l1, r1, d - 1) + get(v * 2 + 2, l, m, l1, r1, d - 1);
    else return get(v * 2 + 1, l, m, l1, r1, d - 1) + get(v * 2 + 2, m, r, l1, r1, d - 1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int d, q;
    cin >> d >> q;
    int n = (1 << d);
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    t.resize(4 * n);
    build(0, 0, n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, k;
            cin >> i >> k;
            i--;
            i ^= LOL;
            update(0, 0, n, i, k);
        }
        if (t == 2) {
            int k;
            cin >> k;
            LOL ^= (1 << (k)) - 1;
        }
        if (t == 3) {
            int k;
            cin >> k;
            LOL ^= (1 << (k));
        }
        if (t == 4) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << get(0, 0, n, l, r + 1, d - 1) << '\n';
        }
    }
}