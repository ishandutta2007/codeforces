#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int a[505];
int n;
int dp[505][505];

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i);
    FO(len,1,n+1) {
        FO(i,0,n) {
            int j = i+len-1;
            if (j < n) {
                // [i,j]
                if (len == 1) dp[i][j] = 1;
                else {
                    dp[i][j] = 1e9;
                    for (int md = i; md < j; md++) {
                        dp[i][j] = min(dp[i][j], dp[i][md] + dp[md+1][j]);
                    }
                    if (a[i] == a[j]) {
                        int x = dp[i+1][j-1];
                        if (x == 0) x++;
                        dp[i][j] = min(dp[i][j], x);
                    }
                }
            } else {
                break;
            }
        }
    }
    printf("%d\n", dp[0][n-1]);
}