#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double
#define ve vector
#define forn(i, n) for (int i = 0; i < n; i++)

ve<int> t, t2, d;

void build(int v, int l, int r) {
    if (l + 1 == r) {
        t[v] = t2[v] = l;
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
    t2[v] = min(t2[v * 2 + 1], t2[v * 2 + 2]);
}

void build2(int v, int l, int r) {
    if (l + 1 == r) {
        t[v] = t2[v] = -l;
        return;
    }
    int m = (l + r) / 2;
    build2(v * 2 + 1, l, m);
    build2(v * 2 + 2, m, r);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
    t2[v] = min(t2[v * 2 + 1], t2[v * 2 + 2]);
}

void push(int v, int l, int r) {
    t[v] += d[v];
    t2[v] += d[v];
    if (l + 1 != r) {
        d[v * 2 + 1] += d[v];
        d[v * 2 + 2] += d[v];
    }
    d[v] = 0;
}

void update(int v, int l, int r, int l1, int r1, int x) {
    push(v, l, r);
    if (l >= r1 || l1 >= r) return;
    if (l1 <= l && r <= r1) {
        d[v] = x;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    update(v * 2 + 1, l, m, l1, r1, x);
    update(v * 2 + 2, m, r, l1, r1, x);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
    t2[v] = min(t2[v * 2 + 1], t2[v * 2 + 2]);
}

int getmax(int v, int l, int r, int l1, int r1) {
    push(v, l, r);
    if (l >= r1 || l1 >= r) return -1e18;
    if (l1 <= l && r <= r1) return t[v];
    int m = (l + r) / 2;
    return max(getmax(v * 2 + 1, l, m, l1, r1), getmax(v * 2 + 2, m, r, l1, r1));
}

int getmin(int v, int l, int r, int l1, int r1) {
    push(v, l, r);
    if (l >= r1 || l1 >= r) return 1e18;
    if (l1 <= l && r <= r1) return t2[v];
    int m = (l + r) / 2;
    return min(getmin(v * 2 + 1, l, m, l1, r1), getmin(v * 2 + 2, m, r, l1, r1));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    t.resize(4 * (n + 1));
    t2.resize(4 * (n + 1));
    d.resize(4 * (n + 1));
    build(0, 0, n + 1);
    ve<int> a(n);
    forn (i, n) cin >> a[i];
    ve<int> ans(n);
    map<int, ve<int>> dp;
    forn (i, n) dp[a[i]].pb(i);
    for (auto el : dp) {
        for (auto i : el.se) {
            int res = getmax(0, 0, n + 1, i + 1, n + 1);
            //cout << res << " " <<  getmin(0, 0, n + 1, 0, i + 1) << " " << i << endl;
            res -= getmin(0, 0, n + 1, 0, i + 1);
            ans[i] = max(ans[i], res / 2);
        }
        for (auto i : el.se) {
            update(0, 0, n + 1, i + 1, n + 1, -2);
        }
    }
    fill(all(d), 0);
    build2(0, 0, n + 1);
    for (auto el : dp) {
        for (auto i : el.se) {
            update(0, 0, n + 1, i + 1, n + 1, 2);
        }
        for (auto i : el.se) {
            update(0, 0, n + 1, i + 1, n + 1, -2);
            int res = getmax(0, 0, n + 1, i + 1, n + 1);
            res -= getmin(0, 0, n + 1, 0, i + 1);
            ans[i] = max(ans[i], (res + 1) / 2);
            update(0, 0, n + 1, i + 1, n + 1, 2);
        }
    }
    for (auto x : ans) cout << x << " ";
}