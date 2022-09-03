//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acosl(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const ld eps = 1e-8;
const ll INF = (ll)(2e18) + 239;
const int BIG = (int)(1e9) + 239;
const int MOD = 998244353; // 1e9 + 7
const ll MOD2 = (ll)MOD * (ll)MOD;

namespace math {
    int sum(int a, int b) {
        a += b - MOD;
        a += (a >> 31) & MOD;
        return a;
    }

    int sub(int a, int b) {
        a -= b;
        a += (a >> 31) & MOD;
        return a;
    }

    int mul(int a, int b) {
        return 1LL * a * b % MOD;
    }

    int power(int a, int k) {
        int ans = 1;
        int pw = a;
        while (k) {
            if (k & 1) {
                ans = mul(ans, pw);
            }
            pw = mul(pw, pw);
            k >>= 1;
        }
        return ans;
    }
}

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(1e6 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 1010;

int n, m, d;
ll a[M];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    d = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        d = gcd(d, x);
    }
    vector<vector<ll>> in(d);
    for (int i = 0; i < n; i++) {
        in[i % d].emplace_back(a[i]);
    }
    for (int i = 0; i < d; i++) {
        sort(in[i].begin(), in[i].end());
    }
    ll ans = -INF;
    for (int t = 0; t < 2; t++) {
        ll now = 0;
        for (int i = 0; i < d; i++) {
            ll sum = 0;
            for (ll x : in[i]) {
                sum += x;
            }
            ll pref = 0;
            if (t == 1) {
                pref += in[i][0];
            }
            ll cur = -INF;
            for (int j = t; j <= (int)in[i].size(); j += 2) {
                cur = max(cur, sum - 2LL * pref);
                if (j + 2 <= (int)in[i].size()) {
                    pref += in[i][j];
                    pref += in[i][j + 1];
                }
            }
            now += cur;
        }
        ans = max(ans, now);
    }
    cout << ans << "\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //cout << fixed << setprecision(1);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}