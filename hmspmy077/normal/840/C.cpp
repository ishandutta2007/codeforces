#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

const int N = 300;
const int MOD = (int)1e9 + 7;

std::vector<int> odd_primes(int n)
{
    std::vector<int> res;
    for (int d = 2; d * d <= n; ++ d) {
        if (n % d == 0) {
            int exp = 0;
            while (n % d == 0) {
                n /= d;
                exp ++;
            }
            if (exp & 1) {
                res.push_back(d);
            }
        }
    }
    if (n > 1) {
        res.push_back(n);
    }
    std::sort(res.begin(), res.end());
    return res;
}

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int binom[N + 1][N + 1], fact[N + 1], ways[N + 1][N + 1], dp[2][N + 1];

int main()
{
#ifdef LOCAL_JUDGE
    freopen("C.in", "r", stdin);
#endif
    for (int i = 0; i <= N; ++ i) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; ++ j) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
        }
    }
    fact[0] = 1;
    for (int i = 1; i <= N; ++ i) {
        fact[i] = (long long)i * fact[i - 1] % MOD;
    }
    ways[0][0] = 1;
    for (int i = 1; i <= N; ++ i) {
        ways[i][1] = fact[i];
        for (int j = 2; j <= i; ++ j) {
            for (int k = 1; k <= i; ++ k) {
                update(ways[i][j], (long long)ways[i - k][j - 1] * binom[i - 1][k - 1] % MOD * fact[k] % MOD);
            }
        }
    }
    int n;
    while (scanf("%d", &n) == 1) {
        std::map<std::vector<int>, int> m_cnt;
        for (int i = 0; i < n; ++ i) {
            int a;
            scanf("%d", &a);
            m_cnt[odd_primes(a)] ++;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int cur = 0;
        for (auto&& it : m_cnt) {
            int cnt = it.second;
            cur ^= 1;
            memset(dp[cur], 0, sizeof(dp[cur]));
            for (int nparts = 1; nparts <= cnt; ++ nparts) {
                int w = ways[cnt][nparts];
                for (int parts = 0; parts <= n; ++ parts) {
                    if (dp[cur ^ 1][parts]) {
                        update(dp[cur][parts + nparts], (long long)dp[cur ^ 1][parts] * w % MOD);
                    }
                }
            }
        }
        int result = 0;
        for (int i = 1; i <= n; ++ i) {
            int val = (long long)dp[cur][i] * fact[i] % MOD;
            update(result, (n - i) & 1 ? MOD - val : val);
        }
        printf("%d\n", result);
    }
}