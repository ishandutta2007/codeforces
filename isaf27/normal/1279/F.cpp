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
const int MOD = 998244353; //(int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e6 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20);
const int B = 500;
const int X = 1e4 + 239;

int n, k, l, c, pos[M], pr[M], bef[M];
pair<ll, int> dp[M];
bool a[M];

deque<pair<ll, int>> mn;

void add(pair<ll, int> cur)
{
    while (!mn.empty() && mn.back() > cur)
        mn.pop_back();
    mn.push_back(cur);
}

void del(pair<ll, int> cur)
{
    if (mn.empty())
        return;
    if (mn.front() == cur)
        mn.pop_front();
}

pair<ll, int> func(ll lambda)
{
    dp[0] = make_pair(0, 0);
    int l = 0;
    mn.clear();
    add(dp[0]);
    for (int i = 0; i < c; i++)
    {
        while (l < pr[i] + 1)
        {
            del(dp[l]);
            l++;
        }
        dp[i + 1] = mn.front();
        dp[i + 1].first += lambda;
        dp[i + 1].second++;
        //make_pair(dp[pr[i] + 1].first + lambda, dp[pr[i] + 1].second + 1);
        dp[i + 1] = min(dp[i + 1], make_pair(dp[i].first + 1, dp[i].second));
        add(dp[i + 1]);
    }
    return dp[c];
}

ll solve()
{
    c = 0;
    for (int i = 0; i < n; i++)
        if (a[i])
            pos[c++] = i;
    if (k >= c)
        return 0;
    //cerr << c << "\n";
    //for (int i = 0; i < c; i++)
    //    cerr << pos[i] + 1 << " ";
    //cerr << "\n";
    int ls = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i])
            ls++;
        bef[i] = ls;
    }
    for (int i = 0; i < c; i++)
    {
        if (pos[i] < l)
            pr[i] = -1;
        else
            pr[i] = bef[pos[i] - l];
    }
    int l = -n - 1;
    int r = n + 1;
    while (r - l > 1)
    {
        int h = (l + r) / 2;
        pair<ll, int> cur = func(h);
        if (cur.second > k)
            l = h;
        else
            r = h;
    }
    //cerr << l << " " << r << "\n";
    pair<ll, int> now = func(r);
    //cerr << now.first << " " << now.second << "!\n";
    return now.first - (ll)r * k;
}

string s;

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> l >> s;
    for (int i = 0; i < n; i++)
        a[i] = ('a' <= s[i] && s[i] <= 'z');
    ll f1 = solve();
    for (int i = 0; i < n; i++)
        a[i] = ('A' <= s[i] && s[i] <= 'Z');
    ll f2 = solve();
    cout << min(f1, f2) << "\n";
    return 0;
}