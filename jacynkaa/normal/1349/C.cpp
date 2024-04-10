#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;
#define int long long

const int MAXN = 1009;
const int inf = (long long)1e18 + 99;

int num[MAXN][MAXN];
string tab[MAXN];
queue<pii> Q;
int t, n, m;

void pre()
{
    rep(i, MAXN) rep(j, MAXN)
        num[i][j] = inf;
}

inline bool valid(pii &P)
{
    return P.st >= 0 && P.st < n && P.nd >= 0 && P.nd < m;
}

vector<pii> getN(pii P)
{
    vector<pii> tmp = {{P.st - 1, P.nd},
                       {P.st + 1, P.nd},
                       {P.st, P.nd - 1},
                       {P.st, P.nd + 1}};
    vector<pii> res;
    for (auto p : tmp)
        if (valid(p))
            res.push_back(p);
    return res;
}
void dfs()
{
    rep(i, n) rep(j, m)
    {
        auto N = getN({i, j});
        for (auto p : N)
            if (tab[i][j] == tab[p.st][p.nd])
            {
                // cerr << i << " " << j << " " << p.st << " " << p.nd << endl;
                num[i][j] = 0;
                Q.push({i, j});
            }
    }

    while (!Q.empty())
    {
        auto p = Q.front();
        Q.pop();
        auto N = getN(p);
        for (auto y : N)
            if (num[y.st][y.nd] == inf)
            {
                num[y.st][y.nd] = num[p.st][p.nd] + 1;
                Q.push(y);
            }
    }
}

int32_t main()
{
    _upgrade;
    pre();
    cin >> n >> m >> t;

    rep(i, n)
    {
        cin >> tab[i];
        //cout << tab[i] << endl;
        rep(j, m) tab[i][j] -= '0';
    }

    //rep(i, n) rep(j, m) cerr << i << " " << j << " " << num[i][j] << endl;

    dfs();
    rep(i, t)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        int x = num[a][b];
        if (x > c)
            cout << ((int)tab[a][b]) << endl;
        else
            cout << (((int)tab[a][b]) ^ ((c - x) % 2)) << endl;
    }
}