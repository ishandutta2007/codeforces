#pragma GCC optimize("O3")
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
const int BIG = (int)(2e9 + 239);
const ll MOD = 1e9 + 7;
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
const int X = 110;

int tree[M];
ll s, a[M];
int n;

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    a[0] = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[i + 1] = a[i] + x;
    }
    vector<ll> al(a, a + n + 1);
    sort(al.begin(), al.end());
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += i;
        for (int t = upper_bound(al.begin(), al.end(), a[i] - s) - al.begin() - 1; t >= 0; t = (t & (t + 1)) - 1)
            ans -= tree[t];
        for (int t = lower_bound(al.begin(), al.end(), a[i]) - al.begin(); t <= n; t |= t + 1)
            tree[t]++;
    }
    cout << ans << "\n";
    return 0;
}