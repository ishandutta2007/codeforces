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
const int X = 2010;

int d, n;
pair<int, int> a[X];
vector<int> v[X];
bool good[X];

int dfs(int p, int pr)
{
    if (!good[p])
        return 0;
    int ans = 1;
    for (int i : v[p])
        if (i != pr)
            ans = 1LL * ans * (dfs(i, p) + 1) % MOD;
    return ans;
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> d >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int t = 0; t < n; t++)
            good[t] = false;
        for (int t = 0; t <= i; t++)
            if (a[t].first >= a[i].first - d)
                good[a[t].second] = true;
        ans += dfs(a[i].second, -1);
        if (ans >= MOD)
            ans -= MOD;
    }
    cout << ans << "\n";
    return 0;
}