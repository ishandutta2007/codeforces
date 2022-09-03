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
const int MOD = 998244353; // (int)(1e9 + 7);
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 20);
const int B = 500;
const int X = 110;

int n, m, k;
string s[X], a[X];

void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<pair<int, int>> way;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
                way.push_back(make_pair(i, j));
        }
        else
        {
            for (int j = m - 1; j >= 0; j--)
                way.push_back(make_pair(i, j));
        }
    }
    int c = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            c += (s[i][j] == 'R');
    vector<int> kol(k, (c / k));
    for (int i = 0; i < (c % k); i++)
        kol[i]++;
    string t = "";
    for (char x = '0'; x <= '9'; x++)
        t += x;
    for (char x = 'a'; x <= 'z'; x++)
        t += x;
    for (char x = 'A'; x <= 'Z'; x++)
        t += x;
    for (int i = 0; i < n; i++)
        a[i] = s[i];
    int p = 0;
    for (int i = 0; i < k; i++)
    {
        int cur = 0;
        while (cur < kol[i])
        {
            a[way[p].first][way[p].second] = t[i];
            cur += (s[way[p].first][way[p].second] == 'R');
            p++;
        }
        while (i + 1 == k && p < n * m)
        {
            a[way[p].first][way[p].second] = t[i];
            p++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << "\n";
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}