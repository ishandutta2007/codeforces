#include<bits/stdc++.h>
#define reg register
#define ll long long
#define ld double
using namespace std;
inline int read() {
    int x=0,f=1,c=getchar();
    for (;c< 48;c=getchar()) if (c=='-') f=0;
    for (;c>=48;c=getchar()) x = x*10 + c-'0';
    return f?x:-x;
}
ld qp(ld x, int n) {return !n ? 1 : qp(x * x, n >> 1) * (n & 1 ? x : 1);}
ld dp[5005][5005];
int main() {
    int n, T; n = read(); T = read();
    dp[0][0] = 1;
    ld ans = 0;
    for (int i = 0; i < n; ++ i) {
        ld pro = read() / 100.0;
        int t = read();
        ld e = qp(1 - pro, t - 1);
        ld sum = 0;
        for (int j = 1; j <= T; ++ j) {
            sum = sum * (1 - pro) + dp[i][j - 1];
            if (j >= t) sum -= e * dp[i][j - t];
            dp[i + 1][j] = sum * pro;
            if (j >= t) dp[i + 1][j] += e * dp[i][j - t];
            ans += dp[i + 1][j];
        }
    }
    printf("%.9f\n", ans);
    return 0;
}