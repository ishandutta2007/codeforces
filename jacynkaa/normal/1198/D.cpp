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

const int MAXN = 52;
int plansza[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];
int n;

int h(int x, int y)
{
    if (x >= 0 && y >= 0)
        return plansza[x][y];
    return 0;
}

int get(int x, int y, int k, int l)
{
    int val = 0;
    val += h(x + k, y + l);
    val -= h(x + k, y - 1);
    val -= h(x - 1, y + l);
    val += h(x - 1, y - 1);
    return val;
}

void wczytywnie()
{
    rep(i, MAXN)
        rep(j, MAXN)
            plansza[i][j] = 0;
    cin >> n;
    rep(i, n)
        rep(j, n)
    {
        char c;
        cin >> c;
        plansza[i][j] = (c == '#') ? 1 : 0;
    }
    rep(i, n)
    {
        rep(j, n) if (j != 0)
            plansza[i][j] = plansza[i][j] + plansza[i][j - 1];
    }
    rep(j, n)
    {
        rep(i, n) if (i != 0)
            plansza[i][j] = plansza[i][j] + plansza[i - 1][j];
    }
    cerr << "ok" << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        rep(j, n)
                cerr
            << plansza[i][j] << " ";
        cerr << endl;
    }
}

inline int sol(int x, int y, int k, int l)
{
    return dp[x][y][k][l];
}
int solve(int x, int y, int k, int l)
{
    int val = get(x, y, k, l);
    if (val < 2)
        return val;
    val = max(k, l) + 1;
    rep(i, l)
        val = min(val, sol(x, y, k, i) + sol(x, y + i + 1, k, l - i - 1));
    rep(i, k)
        val = min(val, sol(x, y, i, l) + sol(x + i + 1, y, k - i - 1, l));
    return val;
}

void solve()
{
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            for (int l = 0; l + i < n; l++)
                for (int k = 0; k + j < n; k++)
                {
                    dp[i][j][l][k] = solve(i, j, l, k);
                    //cerr << i << " " << j << " " << l << " " << k << " wynik: " << dp[i][j][l][k] << endl;
                }
}
main()
{
    _upgrade;
    wczytywnie();
    solve();
    what(get(2, 1, 0, 1));
    cout << dp[0][0][n - 1][n - 1] << endl;
}