#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

ll dp[5005][5005];
ll dpc[5005];
int n, k, a, b;

int minr[5005], maxr[5005];

int main() {
    scanf("%d%d%d%d", &n, &a, &b, &k);
    a--; b--;

    FO(j,0,n) {
        minr[j] = 1e9;
        maxr[j] = -1;
        FO(l,0,n) if (abs(j-l) < abs(j-b) && l!=j) {
            minr[j] = min(minr[j],l);
            maxr[j] = max(maxr[j],l);
        }
    }

    FO(i,0,n) dp[0][i] = 1;

    FO(i,1,k+1) {
        FO(j,0,n) dpc[j+1] = (dpc[j]+dp[i-1][j])%MOD;
        FO(j,0,n) {
            if (minr[j] <= maxr[j]) dp[i][j] = (MOD + dpc[maxr[j]+1] - dpc[minr[j]]) % MOD;
            if (minr[j] <= j && j <= maxr[j]) dp[i][j] = (dp[i][j] + MOD - dp[i-1][j]) % MOD;
        }
    }
    printf("%lld\n", dp[k][a]);
}