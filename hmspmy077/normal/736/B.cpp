#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <climits>
//#include <vector>

bool is_prime(int n)
{
    for (int d = 2; d * d <= n; ++ d) {
        if (n % d == 0) {
            return false;
        }
    }
    return true;
}

int max_div(int n)
{
    for (int d = 2; d * d <= n; ++ d) {
        if (n % d == 0) {
            return n / d;
        }
    }
    return 1;
}

const int N = 100;

int dp[N];

int solve(int n)
{
    if (n <= 10) {
        return dp[n];
    }
    if (is_prime(n)) {
        return 1;
    }
    if (n % 2 == 0) {
        return 2;
    }
    if (is_prime(n - 2)) {
        return 2;
    }
    return 3;
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("B.in", "r", stdin);
#endif
    dp[0] = 0;
    for (int i = 1; i < N; ++ i) {
        dp[i] = 1000000000;
        for (int j = 2; j <= i; ++ j) {
            dp[i] = std::min(dp[i], dp[i - j] + max_div(j));
        }
        // printf("%d %d\n", i, dp[i]);
        // assert(dp[i] == solve(i));
    }
    int n;
    while (scanf("%d", &n) == 1) {
        printf("%d\n", solve(n));
    }
}