#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
template<typename T>
void maxify(T &lhs, const T &rhs) {
    lhs = max(lhs, rhs);
}
int a[100000][3];
long long dp[100001][3];
int main() {
    int n;
    scanf("%d", &n);
    for(int j = 0; j < 3; j++)
        for(int i = 0; i < n; i++)
            scanf("%d", a[i] + j);
    dp[0][0] = 0;
    dp[0][1] = dp[0][2] = -1'000'000'000'000'000;
    for(int i = 1; i <= n; i++) {
        fill_n(dp[i], 3, -1'000'000'000'000'000);
        maxify(dp[i][0], dp[i - 1][0] + a[i - 1][0]);
        maxify(dp[i][0], dp[i - 1][1] + a[i - 1][0] + a[i - 1][1]);
        maxify(dp[i][0], dp[i - 1][2] + a[i - 1][0] + a[i - 1][1] + a[i - 1][2]);
        maxify(dp[i][1], dp[i - 1][0] + a[i - 1][0] + a[i - 1][1]);
        maxify(dp[i][1], dp[i - 1][1] +               a[i - 1][1]);
        maxify(dp[i][1], dp[i - 1][2] +               a[i - 1][1] + a[i - 1][2]);
        maxify(dp[i][2], dp[i - 1][0] + a[i - 1][0] + a[i - 1][1] + a[i - 1][2]);
        maxify(dp[i][2], dp[i - 1][1] +               a[i - 1][1] + a[i - 1][2]);
        maxify(dp[i][2], dp[i - 1][2] +                             a[i - 1][2]);
        if(i >= 2) {
            long long sum = 0LL + a[i - 1][0] + a[i - 1][1] + a[i - 1][2] +
                a[i - 2][0] + a[i - 2][1] + a[i - 2][2];
            maxify(dp[i][0], dp[i - 2][2] + sum);
            maxify(dp[i][2], dp[i - 2][0] + sum);
        }
    }
#if 0
    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < n; i++)
            printf("%lld ", dp[i][j]);
        putchar('\n');
    }
#endif
    printf("%lld\n", dp[n][2]);
}