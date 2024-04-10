#pragma GCC optimize("O3")
#pragma GCC optimize("popcnt")
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
const ld eps = 1e-10;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //(int)(1e9 + 7); //;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 1e4 + 239;

int n, m, c[two][M], k, f[two][M];
vector<int> v[M];
int used[M], cnt, ban;

void dfs(int p, int t)
{
    c[t][p] = k;
    used[p] = cnt;
    for (int i : v[p])
        if (i != ban && used[i] != cnt)
            dfs(i, t);
}

void solve()
{
    int a, b;
    cin >> n >> m >> a >> b;
    a--, b--;
    for (int i = 0; i < n; i++)
        v[i].clear();
    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    cnt++;
    ban = a;
    k = 0;
    for (int i = 0; i < n; i++)
        if (i != ban && used[i] != cnt)
        {
            dfs(i, 0);
            k++;
        }
    cnt++;
    ban = b;
    k = 0;
    for (int i = 0; i < n; i++)
        if (i != ban && used[i] != cnt)
        {
            dfs(i, 1);
            k++;
        }
    for (int i = 0; i < n; i++)
        f[0][i] = 0, f[1][i] = 0;
    ll ans = 0;
    map<pair<int, int>, int> kol;
    for (int i = 0; i < n; i++)
        if (i != a && i != b)
        {
            kol[make_pair(c[0][i], c[1][i])]++;
            f[0][c[0][i]]++;
            f[1][c[1][i]]++;
        }
    for (int i = 0; i < n; i++)
        ans += ((ll)f[0][i] * (ll)(f[0][i] - 1)) / 2LL;
    for (int i = 0; i < n; i++)
        ans += ((ll)f[1][i] * (ll)(f[1][i] - 1)) / 2LL;
    for (const auto& t : kol)
        ans -= ((ll)t.second * (ll)(t.second - 1)) / 2LL;
    cout << ((ll)(n - 2) * (ll)(n - 3) / 2LL) - ans << "\n";
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}