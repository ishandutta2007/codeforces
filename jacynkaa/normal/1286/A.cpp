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

const int MAXN = 150;

int dp[MAXN][MAXN][MAXN][2];
int tab[MAXN];

int pl(int a)
{
    return (a + 1) % 2;
}

main()
{
    _upgrade;
    int n;
    cin >> n;
    rep(i, n) cin >> tab[i];

    rep(i, MAXN) rep(j, MAXN) rep(k, MAXN) dp[i][j][k][0] = dp[i][j][k][1] = 10000;

    if (tab[0] == 0)
        dp[0][0][1][1] = dp[0][1][0][0] = 0;
    if (tab[0] % 2)
        dp[0][0][1][1] = 0;
    else
        dp[0][1][0][0] = 0;

    for (int i = 1; i < MAXN - 2; i++)
        rep(j, MAXN - 2) rep(k, MAXN - 2)
        {

            dp[i][j + 1][k][0] = min(dp[i - 1][j][k][0], dp[i - 1][j][k][1] + 1);
            dp[i][j][k + 1][1] = min(dp[i - 1][j][k][1], dp[i - 1][j][k][0] + 1);

            if (tab[i] != 0)
            {
                if (tab[i] % 2)
                    dp[i][j + 1][k][0] = 10000;
                else
                    dp[i][j][k + 1][1] = 10000;
            }
        }
    /*
    rep(i, MAXN) rep(j, MAXN) rep(k, MAXN)
    {
        if (max(dp[i][j][k][0], dp[i][j][k][1]) < 0)
            continue;
        what(i);
        what(j);
        what(k);
        what(dp[i][j][k][0]);
        what(dp[i][j][k][1]);
    }
    what(n / 2);
    what((n + 1) / 2);
*/
    cout << min(dp[n - 1][n / 2][(n + 1) / 2][0], dp[n - 1][n / 2][(n + 1) / 2][1]) << endl;
}