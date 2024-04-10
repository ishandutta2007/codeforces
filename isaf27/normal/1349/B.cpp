//#pragma GCC optimize("O3")
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
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll btc = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7;

//random
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 1010;

int n, k, a[M], pref[M];

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << (a[0] == k ? "yes\n" : "no\n");
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += (a[i] == k);
    if (cnt == 0)
    {
        cout << "no\n";
        return;
    }
    pref[0] = 0;
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i];
        if (a[i] < k)
            pref[i + 1]--;
        else
            pref[i + 1]++;
    }
    int mn_prev = BIG;
    int mn = 0;
    bool fnd = false;
    for (int i = 1; i <= n; i++)
    {
        if (mn_prev < pref[i])
            fnd = true;
        mn_prev = mn;
        mn = min(mn, pref[i]);
        if (a[i - 1] == k && fnd)
        {
            cout << "yes\n";
            return;
        }
    }
    int mx_prev = -BIG;
    int mx = pref[n];
    fnd = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (mx_prev > pref[i])
            fnd = true;
        mx_prev = mx;
        mx = max(mx, pref[i]);
        if (a[i] == k && fnd)
        {
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}