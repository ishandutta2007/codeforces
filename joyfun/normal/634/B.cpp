#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll s, x, dp[55][2];

int main() {
    scanf("%lld%lld", &s, &x);
    if (x&1) {
        if (!(s&1)) {
            printf("0\n");
            return 0;
        }
        dp[0][0] = 2;
    } else {
        if(s&1) {
            printf("0\n");
            return 0;
        }
        dp[0][0] = dp[0][1] = 1;
    }
    for (int i = 1; i <= 50; i++) {
        if ((x>>i)&1) {
            if ((s>>i)&1) dp[i][0] += 2 * dp[i - 1][0];
            else dp[i][1] += 2 * dp[i - 1][1];
        } else {
            if ((s>>i)&1) {
                dp[i][0] += dp[i - 1][1];
                dp[i][1] += dp[i - 1][1];
            } else {
                dp[i][0] += dp[i - 1][0];
                dp[i][1] += dp[i - 1][0];
            }
        }
    }
    if (s == x) dp[50][0] -= 2;
    printf("%lld\n", dp[50][0]);
    return 0;
}