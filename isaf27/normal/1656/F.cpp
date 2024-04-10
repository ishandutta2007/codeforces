#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
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
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 5050;

ll a[M];
int n;

ll divup(ll x, ll y) {
    if (x % y == 0 || x < 0) {
        return x / y;
    }
    return (x / y) + 1;
}

ll divdown(ll x, ll y) {
    if (x % y == 0 || x >= 0) {
        return x / y;
    }
    return (x / y) - 1;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    if (a[0] > 0) {
        cout << "INF\n";
        return;
    }
    if (a[n - 1] < 0) {
        cout << "INF\n";
        return;
    }
    ll s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
    }
    vector<ll> A;
    for (int i = 0; i < n - 1; i++) {
        A.emplace_back(s + a[n - 1] * i + a[0] * (n - 2 - i));
    }
    vector<ll> B;
    ll s1 = 0;
    ll s2 = s - a[0] - a[n - 1];
    for (int i = 0; i < n - 1; i++) {
        ll cur = s1 * a[n - 1] + s2 * a[0] + a[0] * a[n - 1];
        B.emplace_back(cur);
        s1 += a[i + 1];
        s2 -= a[i + 1];
    }
    vector<ll> C = A;
    sort(C.begin(), C.end());
    if (C[0] > 0) {
        cout << "INF\n";
        return;
    }
    if (C.back() < 0) {
        cout << "INF\n";
        return;
    }
    ll l = INF;
    for (int i = 0; i < n - 1; i++) {
        l = min(l, B[i]);
    }
    /*A.emplace_back(-1);
    B.emplace_back(-1);*/
    /*for (int i = 0; i < (int)A.size(); i++) {
        cout << A[i] << " " << B[i] << "\n";
    }*/
    ll r = INF;
    while (r - l > 1) {
        ll h = (l + r) / 2;
        ll L = -INF * 4LL;
        ll R = INF * 4LL;
        bool check = true;
        for (int i = 0; i < (int)A.size(); i++) {
            if (A[i] == 0) {
                check &= (B[i] >= h);
            }
            if (A[i] < 0) {
                R = min(R, divdown(B[i] - h, -A[i]));
            }
            if (A[i] > 0) {
                L = max(L, divup(h - B[i], A[i]));
            }
        }
        if (R >= L && check) {
            l = h;
        } else {
            r = h;
        }
    }
    cout << l << "\n";
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