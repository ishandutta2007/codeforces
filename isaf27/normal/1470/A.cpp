//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int two = 2;
const ld eps = 1e-10;
const ll INF = (ll)(2e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(3e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 110;

int n, m, k[M], c[M];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        k[i]--;
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    sort(k, k + n);
    int l = 0;
    int r = min(n, m) + 1;
    while (r - l > 1) {
        int h = (l + r) / 2;
        bool ch = true;
        for (int i = 0; i < h; i++) {
            ch &= (i <= k[n - h + i]);
        }
        if (ch) {
            l = h;
        } else {
            r = h;
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += c[k[i]];
    }
    ll ans = sum;
    for (int t = 0; t < l; t++) {
        sum -= c[k[n - t - 1]];
        sum += c[t];
        ans = min(ans, sum);
    }
    //cerr << l << "\n";
    cout << ans << "\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}