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
const int X = 1e6 + 239;

int n, x, a[X];

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0;
    int r = x + 1;
    while (r - l > 1)
    {
        int h = (l + r) / 2;
        int mx = 0;
        bool ch = true;
        for (int i = 0; i < n; i++)
            if (a[i] <= h)
            {
                ch &= (mx <= a[i]);
                mx = a[i];
            }
        if (ch)
            l = h;
        else
            r = h;
    }
    int lg = l;
    l = 0;
    r = x + 1;
    while (r - l > 1)
    {
        int h = (l + r) / 2;
        int mx = 0;
        bool ch = true;
        for (int i = 0; i < n; i++)
            if (a[i] >= h)
            {
                ch &= (mx <= a[i]);
                mx = a[i];
            }
        if (ch)
            r = h;
        else
            l = h;
    }
    int rg = r;
    vector<pair<int, int>> val;
    for (int i = 0; i < n; i++)
        if (a[i] <= lg)
            val.push_back(make_pair(a[i], i));
    vector<int> last(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        last[i + 1] = last[i];
        if (a[i] >= rg)
            last[i + 1] = a[i];
    }
    ll ans = 0;
    //cerr << lg << " " << rg << "?\n";
    for (int l = 1; l <= lg + 1; l++)
    {
        int it = lower_bound(val.begin(), val.end(), make_pair(l, 0)) - val.begin();
        int mx = (it == 0 ? -1 : last[val[it - 1].second]);
        //cerr << mx << " " << it << " ??\n";
        ans += x + 1 - max(rg - 1, max(mx, l));
    }
    cout << ans << "\n";
    return 0;
}