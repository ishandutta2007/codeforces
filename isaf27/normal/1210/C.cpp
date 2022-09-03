//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0

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
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const ll MOD = (int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 19);
const int B = 500;
const int X = 1e4 + 239;

ll ans, a[M];
int n;
vector<int> v[M];

void dfs(int p, int pr, vector<pair<int, ll>> up)
{
    for (pair<int, ll>& t : up)
    {
        t.first++;
        t.second = gcd(t.second, a[p]);
    }
    up.push_back(make_pair(0, a[p]));
    vector<pair<int, ll>> nw;
    for (pair<int, ll> t : up)
    {
        if (!nw.empty() && nw.back().second == t.second)
            continue;
        nw.push_back(t);
    }
    int ls = -1;
    for (int i = (int)nw.size() - 1; i >= 0; i--)
    {
        ans += (ll)(nw[i].first - ls) * nw[i].second;
        ans %= MOD;
        ls = nw[i].first;
    }
    for (int i : v[p])
        if (i != pr)
            dfs(i, p, nw);
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    ans = 0;
    dfs(0, -1, {});
    cout << ans;
    return 0;
}