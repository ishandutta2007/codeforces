#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

int n;
int p[100005];
ll dp[200005][2];
ll DP[200005][2];
ll dpp[200005][2][2];
vector<int> u[100005];

int main() {
    scanf("%d", &n);
    FO(i,1,n) {
        scanf("%d", p+i);
        p[i]--;
        u[p[i]].push_back(i);
    }
    int F = 200004;
    FO(i,0,n) {
        u[i].push_back(F--);
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = sz(u[i])-1; j >= 0; j--) {
            for (int p = 0; p <= 1; p++) {
                // first j children of i are done
                // do rest with parity p
                if (j == sz(u[i])-1) dp[u[i][j]][p] = !p;
                else dp[u[i][j]][p] = dp[u[i][j+1]][p] +
                        (dp[u[i][j+1]][p] * DP[u[i][j]][0]) % MOD +
                        (dp[u[i][j+1]][p^1] * DP[u[i][j]][1]) % MOD;
                dp[u[i][j]][p] %= MOD;

                FO(q,0,2) {
                    // first j children of i are done
                    // do rest with parity p using only q
                    if (j == sz(u[i])-1) dpp[u[i][j]][p][q] = !p;
                    else dpp[u[i][j]][p][q] = dpp[u[i][j+1]][p][q] +
                        (dpp[u[i][j+1]][p^q][q] * DP[u[i][j]][q]) % MOD;
                    dpp[u[i][j]][p][q] %= MOD;
                }
            }
        }
        // i is white
        // colour it's subtree with parity p
        FO(k,0,2) {
            DP[i][k] = 2*dp[u[i][0]][!k] + 2*MOD - dpp[u[i][0]][!k][0];
            if (!k) {
                DP[i][k] += 2*MOD - dpp[u[i][0]][!k][1];
            }
            DP[i][k] %= MOD;
        }
        //printf("DP[%d][%d]=%lld\n", i, 0, DP[i][0]);
        //printf("DP[%d][%d]=%lld\n", i, 1, DP[i][1]);
    }
    printf("%lld\n", (DP[0][0] + DP[0][1]) % MOD);
}