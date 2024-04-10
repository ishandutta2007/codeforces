#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define M 1000005

using namespace std;

int b[M+10];
int c[M+10];
int dp[M+10];
int n;

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x, y;
        scanf("%d %d", &x, &y);
        x++;
        b[x] = y;
        c[x] = 1;
    }
    FO(i,0,M) {
        c[i+1] += c[i];
    }
    dp[0] = 0;
    int ans = n;
    FO(i,1,M) {
        if (b[i] == 0) dp[i] = dp[i-1];
        else {
            // set at ith one off
            dp[i] = c[i-1] - c[max(i-b[i]-1,0)] + dp[max(i-b[i]-1,0)];
        }
        ans = min(ans, dp[i] + (n-c[i]));
    }
    printf("%d\n", ans);
}