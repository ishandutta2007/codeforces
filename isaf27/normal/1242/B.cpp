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
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 20);
const int B = 500;
const int X = 1e6 + 239;
 
int n, m;
vector<int> v[M];
vector<pair<int, int>> s[M];
set<int> used;
 
void dfs(int p)
{
    used.erase(p);
    for (pair<int, int> t : s[p])
    {
        int l = t.first;
        int r = t.second;
        while (true)
        {
            auto it = used.lower_bound(l);
            if (it == used.end())
                break;
            if (*it > r)
                break;
            int c = (*it);
            dfs(c);
        }
    }
}
 
int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        sort(v[i].begin(), v[i].end());
        if (v[i].empty())
        {
            s[i].push_back(make_pair(0, n - 1));
            continue;
        }
        if (v[i][0] > 0)
            s[i].push_back(make_pair(0, v[i][0] - 1));
        for (int t = 0; t + 1 < v[i].size(); t++)
            if (v[i][t + 1] > v[i][t] + 1)
                s[i].push_back(make_pair(v[i][t] + 1, v[i][t + 1] - 1));
        if (v[i].back() + 1 < n)
            s[i].push_back(make_pair(v[i].back() + 1, n - 1));
    }
    for (int i = 0; i < n; i++)
        used.insert(i);
    int ans = -1;
    for (int i = 0; i < n; i++)
        if (used.find(i) != used.end())
        {
            ans++;
            dfs(i);
        }
    cout << ans;
    return 0;
}