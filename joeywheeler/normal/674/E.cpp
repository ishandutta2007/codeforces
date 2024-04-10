#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MH 45

using namespace std;

int q;
int p[500005];
double dp[500005][MH];
double lgsm[500005][MH];
int nd = 1;

int main() {
    scanf("%d", &q);
    FO(j,1,MH) {
        dp[0][j] = 0;
    }
    dp[0][0] = 1;
    p[0] = -1;

    FO(z,0,q) {
        int t; scanf(" %d", &t);
        if (t == 1) {
            int par; scanf("%d", &par); par--;
            p[nd] = par;
            double op = 0, np = 0;
            int i, h;
            for (i = nd, h = 0; h < MH && i != -1; i = p[i], h++) {
                if (h == 0) {
                    op = dp[i][h];
                    dp[i][0] = 1;
                    np = dp[i][h];
                } else {
                    double olg = log(1 - op/2);
                    double nlg = log(1 - np/2);

                    lgsm[i][h] -= olg;
                    lgsm[i][h] += nlg;

                    op = dp[i][h];
                    dp[i][h] = 1 - exp(lgsm[i][h]);
                    np = dp[i][h];
                }
            }
            //assert(i == -1 || fabs(op-np) < 1e-10);
            nd++;
        } else {
            int i; scanf("%d", &i); i--;
            double res = 0;
            FO(h,1,MH) res += dp[i][h];
            printf("%.10lf\n", res);
        }
    }
}