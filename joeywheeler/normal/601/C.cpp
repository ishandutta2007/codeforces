#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
int x[105];
double dp[105][100005];

int main() {
    scanf("%d%d", &n, &m);
    if (m == 1) {
        printf("1\n");
        return 0;
    }
    int s = 0;
    FO(i,0,n) {
        scanf("%d", &x[i]);
        s += x[i];
    }
    FO(i,1,s+1) dp[0][i] = 1;
    FO(i,1,n+1) {
        int w = x[i-1];
        FO(j,1,s+1) dp[i-1][j] += dp[i-1][j-1];
        FO(j,0,s+1) {
            // [j-m,j-1] \ j-w
            double l = j-m-1 < 0 ? 0 : dp[i-1][j-m-1];
            double r = j-1 < 0 ? 0 : dp[i-1][j-1];
            double rem = j-w-1 < 0 ? 0 : dp[i-1][j-w]-dp[i-1][j-w-1];
            dp[i][j] = (r - l - rem) / (m-1);
        }
    }
    printf("%.15lf\n", 1 + (m-1) * dp[n][s]);
}