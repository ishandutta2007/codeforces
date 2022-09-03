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
const int X = (int)(1e6 + 239);

int n, a[M], b[M];

void solve() {
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    for (const auto& t : cnt) {
        if (t.second > (n / 2)) {
            cout << "NO\n";
            return;
        }
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            b[i] = a[i / 2];
        } else {
            b[i] = a[(i / 2) + (n / 2)];
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] > b[(i + n - 1) % n] && b[i] > b[(i + 1) % n]) {
            continue;
        }
        if (b[i] < b[(i + n - 1) % n] && b[i] < b[(i + 1) % n]) {
            continue;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i + 1 == n];
    }
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