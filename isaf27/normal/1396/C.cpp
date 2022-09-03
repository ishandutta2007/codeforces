//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
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
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20) + 239;
const int B = 500;
const int X = 1e6 + 239;

int n;
ll d, r1, r2, r3, a[X], dp[X];

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1] = dp[i] + a[i] * r1 + r3;
        for (int j = 2; j <= 3 && j <= i + 1; j++)
        {
            ll cur = dp[i + 1 - j];
            cur += 2LL * d * (j - 1);
            for (int x = i + 1 - j; x <= i; x++)
                cur += min(r1 + r2, a[x] * r1 + min(2LL * r1, r3));
            dp[i + 1] = min(dp[i + 1], cur);
        }
    }
    ll ans = dp[n];
    ll cur = dp[n - 2];
    cur += d;
    cur += min(r1 + r2, a[n - 2] * r1 + min(2LL * r1, r3));
    cur += a[n - 1] * r1 + r3;
    ans = min(ans, cur);
    cout << ans + (ll)(n - 1) * d << "\n";
    return 0;
}