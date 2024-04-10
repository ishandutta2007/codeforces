#include <cstdio>

const int mod = 1000000007;

int ile[11];
long long dp[11][107];
long long dwumian[107][107];

int N;

template<int o = 0>
void solve(int i) {
    for (int dl = 0; dl <= N; dl++) {
        for (int w = ile[i]; w <= N; w++) {
            if (dl - w >= 0) {
                if (dl - o >= 0)
                    dp[i][dl] += dp[i - 1][dl - w] * dwumian[dl - o][w];
                dp[i][dl] %= mod;
            }
        }
    }
};

int main() {
    scanf("%d", &N);
    for (int i = 0; i < 10; i++) {
        scanf("%d", &ile[i]);
    }
    ile[10] = ile[0];
    dwumian[0][0] = 1;
    for (int i = 1; i <= 100; i++) {
        dwumian[i][0] = 1;
        for (int w = 1; w <= 100; w++)
            dwumian[i][w] = (dwumian[i - 1][w] + dwumian[i - 1][w - 1]) % mod;
    }
    for (int dl = 0; dl <= N; dl++) {
        dp[1][dl] = (ile[1] <= dl);
    }
    for (int i = 2; i <= 9; i++)
        solve(i);
    solve<1>(10);
    long long wyn = 0;
    for (int i = 0; i <= N; i++) {
        wyn += dp[10][i];
    }
    printf("%I64d\n", wyn % mod);
    return 0;
}