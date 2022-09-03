#pragma GCC optimize("O3")
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
const int MOD = 1e9 + 7; //(int)(1e9 + 7); //;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 11;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 3010;

int n;
vector<int> v[X];
ll dp[X][X];

int timer, tin[X], tout[X], kol[X], pr[X];
vector<int> et;

void dfs_pre(int p, int last)
{
    et.push_back(p);
    pr[p] = last;
    tin[p] = timer++;
    kol[p] = 1;
    for (int i : v[p])
        if (i != last)
        {
            dfs_pre(i, p);
            kol[p] += kol[i];
        }
    tout[p] = timer;
}

bool upper(int i, int j)
{
    return (tin[i] <= tin[j] && tout[j] <= tout[i]);
}

vector<int> st;

void dfs_dp(int p, int last)
{
    st.push_back(p);
    for (int x = (int)st.size() - 2; x >= 0; x--)
    {
        int i = st[x];
        int j = st[x + 1];
        dp[i][p] = kol[p] * (n - kol[j]);
        dp[i][p] += max(dp[j][p], dp[i][pr[p]]);
        dp[p][i] = dp[i][p];
    }
    for (int i : v[p])
        if (i != last)
            dfs_dp(i, p);
    st.pop_back();
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    timer = 0;
    dfs_pre(0, -1);
    dfs_dp(0, -1);
    for (int ii = 0; ii < n; ii++)
        for (int jj = ii + 1; jj < n; jj++)
        {
            int i = et[ii];
            int j = et[jj];
            if (upper(i, j) || upper(j, i))
                continue;
            dp[i][j] = kol[i] * kol[j];
            dp[i][j] += max(dp[pr[i]][j], dp[i][pr[j]]);
            dp[j][i] = dp[i][j];
        }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans = max(ans, dp[i][j]);
    cout << ans << "\n";
    return 0;
}