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
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 19;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 300;

int n, x, m;
vector<int> vx;
vector<pair<int, int>> v;
bool ok[X];

void solve()
{
    cin >> n >> x >> m;
    vx.clear();
    vx.push_back(0);
    vx.push_back(n);
    x--;
    vx.push_back(x);
    vx.push_back(x + 1);
    v.clear();
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        vx.push_back(l);
        vx.push_back(r);
        v.push_back(make_pair(l, r));
    }
    sort(vx.begin(), vx.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    for (int i = 0; i < (int)vx.size(); i++)
        ok[i] = false;
    ok[lower_bound(vx.begin(), vx.end(), x) - vx.begin()] = true;
    for (pair<int, int> t : v)
    {
        int l = lower_bound(vx.begin(), vx.end(), t.first) - vx.begin();
        int r = lower_bound(vx.begin(), vx.end(), t.second) - vx.begin();
        bool ex = false;
        for (int i = l; i < r; i++)
            ex |= ok[i];
        if (ex)
        {
            for (int i = l; i < r; i++)
                ok[i] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i + 1 < (int)vx.size(); i++)
        if (ok[i])
            ans += vx[i + 1] - vx[i];
    cout << ans << "\n";
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