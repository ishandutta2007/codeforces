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
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define what(x) cerr << #x << " is " << x << endl;
const int MAXN = 1e3 + 10;

vector<vector<int>> W;
int tab[MAXN];
int odp[MAXN][MAXN];
int n;

void pre()
{
    cin >> n;
    W.resize(1);
    rep(i, n)
    {
        cin >> tab[i];
    }
    rep(i, n + 1) W[0].push_back(i);

    rep(i, MAXN)
        rep(j, MAXN)
            odp[i][j] = -1;
}

void debug(int i)
{
    what(i);
    for (auto V : W)
        cout << V.size() << endl;
}
void solve(int i)
{
    //debug(i);
    W.push_back(vector<int>());
    for (auto &V : W)
    {
        if (V.size() > 1)
        {
            while (V.size() > 1 && tab[i] > 0)
            {
                tab[i]--;
                W.back().push_back(V.back());
                odp[i][V.back()] = 1;
                V.pop_back();
            }
            for (auto a : V)
                odp[i][a] = 0;
            break;
        }
    }
    rep(j, n + 1) if (odp[i][j] == -1)
    {
        if (tab[i] > 0)
        {
            tab[i]--;
            odp[i][j] = 1;
        }
        else
            odp[i][j] = 0;
    }
}

main()
{
    _upgrade;
    pre();
    rep(i, n)
        solve(i);
    cout << n + 1 << endl;
    rep(i, n + 1)
    {
        rep(j, n) cout << odp[j][i];
        cout << endl;
    }
}