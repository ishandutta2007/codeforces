#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int k1, k2;
int dp[55][55][2];

int main() {
    int n1, n2;
    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
    FO(i,0,55) FO(j,0,55) {
        dp[i][j][0] = 1;
        for (int m = 1; m <= min(k1,i); m++) {
            if (dp[i-m][j][1] == 0) {
                dp[i][j][0] = 0;
            }
        }

        dp[i][j][1] = 0;
        for (int m = 1; m <= min(k2,j); m++) {
            if (dp[i][j-m][0] == 1) {
                dp[i][j][1] = 1;
            }
        }
    }
    if (dp[n1][n2][0] == 0) {
        printf("First\n");
    } else {
        printf("Second\n");
    }
}