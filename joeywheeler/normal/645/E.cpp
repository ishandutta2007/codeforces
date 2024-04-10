#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

char s[2000005];
int lt[26];
int n, m, k;
int dp[2000005];

int main() {
    scanf("%d %d", &n, &k);
    scanf(" %s", s);
    FO(i,0,k) lt[i] = -1;
    m = strlen(s);
    FO(i,0,m) lt[s[i]-'a'] = i;
    FO(i,m,m+n) {
        int mn = 0;
        FO(j,0,k) if (lt[j] < lt[mn]) mn = j;
        s[i] = mn+'a';
        lt[mn] = i;
    }
    n += m;
    FO(i,0,k) lt[i] = -1;
    FO(i,0,n) {
        dp[i] = 1;
        FO(j,0,k) if (lt[j] != -1) {
            dp[i] += dp[lt[j]];
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
        lt[s[i]-'a'] = i;
    }
    int res = 1;
    FO(j,0,k) if (lt[j] != -1) {
        res += dp[lt[j]];
        if (res >= MOD) res -= MOD;
    }
    printf("%d\n", res);
}