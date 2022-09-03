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
const int MOD = 1e9 + 7; //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18);
const int B = (int)sqrt(M);
const int X = 1e3 + 239;

string s[X];
int n, m, dp[X][X];

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int j = m - 1; j >= 0; j--)
        for (int i = 0; i < n; i++)
        {
            dp[i][j] = 1;
            if (j < m - 1 && s[i][j] == s[i][j + 1])
                dp[i][j] = dp[i][j + 1] + 1;
        }
    ll ans = 0;
    for (int j = 0; j < m; j++)
    {
        vector<pair<int, int> > v;
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || s[i][j] == s[i - 1][j])
                continue;
            v.push_back(make_pair(l, i));
            l = i;
        }
        v.push_back(make_pair(l, n));
        for (int i = 1; i < (int)v.size() - 1; i++)
        {
            int l = v[i].first;
            int r = v[i].second;
            if (v[i - 1].second - v[i - 1].first < r - l) continue;
            if (v[i + 1].second - v[i + 1].first < r - l) continue;
            int fl = v[i - 1].second - (r - l);
            int fr = v[i + 1].first + (r - l);
            int mx = m;
            for (int t = fl; t < fr; t++)
                mx = min(mx, dp[t][j]);
            ans += mx;
        }
    }
    cout << ans;
    return 0;
}