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

const int K = 400;

struct line {
    int k, b;
    line() {}
    line (int k, int b) : k(k), b(b) {}
};

ld X(line a, line b) {
    return ((ld) a.b - b.b) / ((ld) b.k - a.k);
}

void add(ve<line>& a, line t) {
    while (sz(a) >= 2) {
        line x = a.back();
        a.pop_back();
        line y = a.back();
        if (X(x, y) < X(y, t)) {
            a.pb(x);
            break;
        }
    }
    a.pb(t);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, w;
    cin >> n >> w;
    int mx = 0;
    ve<pii> A(n);
    forn (i, n) {
        cin >> A[i].fi >> A[i].se;
        mx = max(mx, A[i].se);
    }
    mx += 2;
    ve<int> ans(mx), ans2(mx), ans3(mx);
    ve<int> dp(mx);
    forn (i, n) dp[A[i].se]++;
    for (int i = mx - 1; i >= 0; i--) {
        if (i != mx - 1) dp[i] += dp[i + 1];
        ans[i] = dp[i] * i * w;
    }
    ve<pii> qu;
    forn (i, n) qu.pb({A[i].se, A[i].fi});
    qu.pb({mx - 1, 0});
    sort(all(qu));
    const int M = 1e5 + 5;
    ve<int> tmp(M);
    int id = 0;
    for (int L = 0; L < sz(qu); L += K) {
        int R = min(sz(qu) - 1, L + K - 1);
        ve<int> z;
        for (int i = L; i <= R; i++) z.pb(qu[i].se);
        z.pb(M - 1);
        sort(all(z));
        z.resize(unique(all(z)) - z.begin());
        ve<ve<line>> kht(sz(z));
        ve<int> uk(sz(z));
        ve<int> cnt(sz(z));
        int pr = 0;
        forn (i, sz(z)) {
            int x = z[i];
            for (int j = pr; j <= x; j++) add(kht[i], line(j, tmp[j]));
            pr = x + 1;
        }
        for (int i = L; i <= R; i++) {
            while (id < mx && qu[i].fi >= id) {
                forn (v, sz(z)) {
                    int x = cnt[v];
                    while (uk[v] > 0 && X(kht[v][uk[v]], kht[v][uk[v] - 1]) > x) uk[v]--;
                    while (uk[v] + 1 < sz(kht[v]) && X(kht[v][uk[v]], kht[v][uk[v] + 1]) <= x) uk[v]++;
                    int res = x * kht[v][uk[v]].k + kht[v][uk[v]].b;
                    if (ans2[id] < res) {
                        ans2[id] = res;
                        ans3[id] = kht[v][uk[v]].k;
                    }
                }
                id++;
            }
            for (int j = 0; j < sz(z) && z[j] <= qu[i].se; j++) {
                cnt[j]++;
            }
        }
        pr = 0;
        forn (i, sz(z)) {
            int x = z[i];
            for (int j = pr; j <= x; j++) tmp[j] += cnt[i] * j;
            pr = x + 1;
        }
    }
    forn (i, mx) {
        cout << ans[i] + ans2[i] << " " << ans3[i] << '\n';
    }
}