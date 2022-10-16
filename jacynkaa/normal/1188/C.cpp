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
const int MAXN = 1e3 + 10;
const int MOD = 998244353;

vector<int> liczby;
int last = 0;
int ans = 0;
int dodaj[MAXN];
int dp[MAXN][MAXN];
int n, k;

void solve(int x)
{
    int poczatek = 0;
    fill(dodaj, dodaj + MAXN, 0);
    fill(dp[0], dp[0] + MAXN, 0);
    dp[0][1] = 1;
    for (int i = 1; i < n; i++)
    {
        while (liczby[i] - liczby[poczatek] >= x)
        {
            for (int j = 0; j <= k; j++)
                dodaj[j] = dp[poczatek][j];
            poczatek++;
        }

        for (int j = 1; j <= k; j++)
            dp[i][j] = (dodaj[j - 1] + dp[i - 1][j]) % MOD;
        dp[i][1] = dp[i][1] + 1;
    }
    int q = dp[n - 1][k];
    ans = (ans + (q - last + MOD) * x) % MOD;
    //cerr << x << ": " << q - last << endl;
    last = q;
}

main()
{
    _upgrade;
    cin >> n >> k;
    liczby.resize(n);
    rep(i, n) cin >> liczby[i];
    sort(all(liczby));
    for (int s = (liczby[n - 1] + 1) / (k - 1); s > 0; s--)
        solve(s);
    cout << ans << endl;
}