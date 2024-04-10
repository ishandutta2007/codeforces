#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 y00

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-9;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(2e9 + 239);
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18);
const int B = (int)sqrt(M);
const int X = 42;

deque<ll> q;

void add(ll x)
{
    while (!q.empty() && q.back() < x)
        q.pop_back();
    q.push_back(x);
}

void del(ll x)
{
    if (q.front() == x)
        q.pop_front();
}

int n, m, d, a[M], b[M], t[M];
ll dp[two][M];

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i] >> t[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++)
        dp[0][i] = 0;
    int last = 1;
    for (int p = 0; p < m; p++)
    {
        int l = 0;
        int r = 0;
        q.clear();
        int can = (int)min((ll)n, (ll)(t[p] - last) * (ll)d);
        last = t[p];
        for (int i = 0; i < n; i++)
        {
            dp[(p + 1) & 1][i] = (ll)b[p] - abs(a[p] - i);
            while (r < n && r - i <= can)
                add(dp[p & 1][r++]);
            while (l < n && i - l > can)
                del(dp[p & 1][l++]);
            dp[(p + 1) & 1][i] += q.front();
        }
    }
    ll ans = -INF;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[m & 1][i]);
    cout << ans;
    return 0;
}