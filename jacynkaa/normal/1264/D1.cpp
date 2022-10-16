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
#define int long long
const int MOD = 998244353;
const int MAXN = 5000;

int pot2[MAXN];
int ile[MAXN];
int dp[MAXN][MAXN];
string S;
int n;

int get(int p, int q)
{
    if (p > q)
        return 0;
    return ile[q] - ((p == 0) ? 0 : ile[p - 1]);
}

void pre()
{
    cin >> S;
    n = S.size();
    rep(i, n)
        ile[i] = ile[max(i - 1, 0ll)] + ((S[i] == '?') ? 1 : 0);
    //    rep(i, n) cerr << ile[i] << " ";
    // cerr << endl;

    pot2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pot2[i] = (pot2[i - 1] * 2) % MOD;
}

void solve()
{
    for (int k = 1; k <= n; k++)
        rep(i, n)
        {
            int j = k + i;
            if (j > n)
                continue;

            if (S[i] == ')')
            {
                dp[i][j] = dp[i + 1][j];
                continue;
            }
            if (S[j] == '(')
            {
                dp[i][j] = dp[i][j - 1];
                continue;
            }
            dp[i][j] = dp[i + 1][j - 1] + pot2[get(i + 1, j - 1)];

            if (S[i] == '?')
                dp[i][j] += dp[i + 1][j];
            if (S[j] == '?')
                dp[i][j] += dp[i][j - 1];
            if (S[i] == '?' && S[j] == '?')
                dp[i][j] += (MOD - dp[i + 1][j - 1]);

            dp[i][j] = dp[i][j] % MOD;
        }
}

main()
{
    _upgrade;
    pre();
    solve();
    cout << dp[0][n - 1] << endl;

    //  rep(i, n) for (int j = i + 1; j < n; j++) cerr << i << " " << j << " " << dp[i][j] << " " << get(i + 1, j - 1) << endl;
}