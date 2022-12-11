#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

const int nmax = 2e6;
char *s;
ll **dp;

ll max(ll a, ll b)
{
    return (a < b ? b : a);
}

int solve()
{
    int n = strlen(s);
    ll lf = 0, rg = (ll)(1e8) + 1;
    while (lf < rg - 1) {
        ll md = (lf + rg) >> 1;
        dp[0][0] = 0;
        dp[0][1] = -md;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][1] - md;
            dp[i][1] = dp[i - 1][0] - md;
            if (s[i - 1] == 'L') {
                dp[i][1] = max(dp[i][1], dp[i - 1][0] + (ll)(1e8) - md);
            } else if (s[i - 1] == 'R') {
                dp[i][0] = max(dp[i][0], dp[i - 1][1] + (ll)(1e8) - md);
            }
            dp[i][0] = max(dp[i][0], dp[i][1] - md);
            dp[i][1] = max(dp[i][1], dp[i][0] - md);
        }
        //cout << md << " " << dp[n][0] << "\n";
        if (dp[n][0] >= 0) {
            lf = md;
        } else {
            rg = md;
        }
    }
    return lf;
}

int main()
{
    
    s = (char*)malloc(nmax);
    memset(s, 0, nmax);
    dp = (ll**)malloc(nmax * sizeof(ll*));
    for (int i = 0; i < nmax; ++i) {
        dp[i] = (ll*)malloc(2 * sizeof(ll));
        dp[i][0] = dp[i][1] = 0;
    }

    char t[nmax];
    scanf("%s", t);
    int pos = 0;
    for (int i = 0; t[i]; ++i) {
        if (i && t[i] == t[i - 1] && t[i] != 'X') {
            s[pos++] = 'X';
        }
        s[pos++] = t[i];
    }

    int ans = 0;
    if (s[0] == s[pos - 1] && s[0] != 'X') {
        if (s[0] == 'L') {
            s[pos++] = 'X';
            //printf("%s\n", s);
        } else {
            memmove(s + 1, s, pos + 1);
            s[0] = 'X';
            //printf("%s\n", s);
        }
    }
    ans = solve();

    printf("%d.%06d\n", ans / (int)(1e6), ans % (int)(1e6));

}