//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int ll

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
const int BIG = (int)(2e9 + 239);
const ll MOD = 1e9 + 7;

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
const int X = 2010;

int n, m, q, dp[X][X];
vector<pair<int, int>> v[N];

ll func(ll x)
{
    return (x * (x + 1) / 2LL) % MOD;
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        int s, f, w;
        cin >> s >> f >> w;
        s--, f--;
        v[s].push_back(make_pair(f, w));
        v[f].push_back(make_pair(s, w));
    }
    dp[0][0] = 0;
    for (int i = 1; i < n; i++)
        dp[i][0] = -BIG;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i < n; i++)
            dp[i][j] = -BIG;
        for (int i = 0; i < n; i++)
            for (auto [x, w] : v[i])
                if (dp[x][j - 1] != -BIG)
                    dp[i][j] = max(dp[i][j], dp[x][j - 1] + w);
    }
    ll ans = 0;
    for (int j = 1; j <= min(n, q); j++)
    {
        int mx = 0;
        for (int i = 0; i < n; i++)
            mx = max(mx, dp[i][j]);
        ans += (mx % MOD);
        if (ans >= MOD)
            ans -= MOD;
    }
    if (n >= q)
    {
        cout << ans << "\n";
        return 0;
    }
    vector<pair<ll, ll>> ln;
    for (int i = 0; i < n; i++)
    {
        int mx = 0;
        for (auto [x, w] : v[i])
            mx = max(mx, w);
        ll cf = -INF;
        for (int j = 0; j <= n; j++)
            if (dp[i][j] != -BIG)
                cf = max(cf, (ll)dp[i][j] - (ll)j * (ll)mx);
        ln.emplace_back((ll)mx, cf);
    }
    sort(ln.begin(), ln.end());
    vector<pair<ll, ll>> nw;
    for (int i = 0; i < n; i++)
        if (i == n - 1 || ln[i].first != ln[i + 1].first)
            nw.push_back(ln[i]);
    ln = nw;
    /*for (int i = n + 1; i <= q; i++)
    {
        ll cur = -INF;
        for (pair<ll, ll> t : ln)
            cur = max(cur, t.first * i + t.second);
        ans += cur;
        if (ans >= MOD)
            ans -= MOD;
    }*/ // slow
    for (int i = 0; i < (int)ln.size(); i++)
    {
        ll l = n + 1;
        ll r = q;
        ll fi = ln[i].first;
        ll si = ln[i].second;
        for (int j = 0; j < i; j++)
        {
            ll fj = ln[j].first;
            ll sj = ln[j].second;
            if (sj >= si)
            {
                sj -= si;
                fj = fi - fj;
                l = max(l, (sj + fj - 1) / fj);
            }
        }
        for (int j = i + 1; j < (int)ln.size(); j++)
        {
            ll fj = ln[j].first;
            ll sj = ln[j].second;
            if (si <= sj)
            {
                r = 0;
                continue;
            }
            sj = si - sj;
            fj -= fi;
            r = min(r, (sj - 1) / fj);
        }
        if (l > r)
            continue;
        pair<ll, ll> t = ln[i];
        ll cur = t.second % MOD;
        if (cur < 0)
            cur += MOD;
        cur *= (r - l + 1);
        cur %= MOD;
        cur += ((((func(r) - func(l - 1)) % MOD + MOD) % MOD) * t.first) % MOD;
        if (cur >= MOD)
            cur -= MOD;
        ans += cur;
        if (ans >= MOD)
            ans -= MOD;
    }
    cout << ans << "\n";
    return 0;
}