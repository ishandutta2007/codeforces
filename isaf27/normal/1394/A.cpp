//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
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
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20) + 239;
const int B = 500;
const int X = 1e4 + 239;

int n, d;
ll a, m;
vector<ll> good, bad;
ll pref_good[M], pref_bad[M];

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> d >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a <= m)
            good.push_back(a);
        else
            bad.push_back(a);
    }
    sort(good.rbegin(), good.rend());
    pref_good[0] = 0;
    for (int i = 0; i < (int)good.size(); i++)
        pref_good[i + 1] = pref_good[i] + good[i];
    sort(bad.rbegin(), bad.rend());
    pref_bad[0] = 0;
    for (int i = 0; i < (int)bad.size(); i++)
        pref_bad[i + 1] = pref_bad[i] + bad[i];
    if (bad.empty())
    {
        ll ans = 0;
        for (ll x : good)
            ans += x;
        cout << ans << "\n";
        return 0;
    }
    ll ans = 0;
    for (int k = 1; k <= (int)bad.size() && 1 + (k - 1) * (d + 1) <= n; k++)
    {
        int can = min(n, k * (d + 1));
        if (can < bad.size())
            continue;
        int work = max((int)bad.size(), 1 + (k - 1) * (d + 1));
        int can_good = n - work;
        ll cur = pref_good[can_good] + pref_bad[k];
        ans = max(ans, cur);
    }
    cout << ans << "\n";
    return 0;
}