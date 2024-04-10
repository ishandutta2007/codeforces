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
const int MOD = 1'000'000'007; // 1e9 + 7
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

    int inv(int a) {
        return power(a, MOD - 2);
    }
}

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 19) + 239;
const int B = 500;
const int X = 210;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll sum = 0;
    vector<vector<int>> v(2);
    for (int i = 0; i < n; i++) {
        v[a[i]].emplace_back(b[i]);
        sum += b[i];
    }
    sort(v[0].rbegin(), v[0].rend());
    sort(v[1].rbegin(), v[1].rend());
    auto calc = [&](int c0, int c1) {
        //cerr << c0 << " " << c1 << "\n";
        ll ans = sum;
        for (int i = 0; i < c0; i++) {
            ans += v[0][i];
        }
        for (int i = 0; i < c1; i++) {
            ans += v[1][i];
        }
        return ans;
    };
    ll ans = sum;
    if (v[0].empty() || v[1].empty()) {
        cout << sum << "\n";
        return;
    }
    {
        int sz = min(v[0].size(), v[1].size());
        int c0 = sz - 1;
        int c1 = sz;
        if (v[0].size() > sz) {
            c0++;
        }
        ans = max(ans, calc(c0, c1));
    }
    {
        int sz = min(v[0].size(), v[1].size());
        int c0 = sz;
        int c1 = sz - 1;
        if (v[1].size() > sz) {
            c1++;
        }
        ans = max(ans, calc(c0, c1));
    }
    cout << ans << "\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}