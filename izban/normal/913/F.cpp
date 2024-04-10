// spasibo bozhe za pretest s perepolneniem summy treh intov
#include <bits/stdc++.h>
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;

const int MOD = 998244353;

int bin(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        n >>= 1;
    }
    return res;
}

int inv(int x) {
    return bin(x, MOD - 2);
}

void add(int &x, ll y) {
    x = (x + y) % MOD;
}

int binom(int n) {
    return 1LL * n * (n - 1) / 2 % MOD;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, a, b;
    while (cin >> n >> a >> b) {
        int p = 1LL * a * inv(b) % MOD;

        int op = (1 - p + MOD) % MOD;
        vector<int> pwP(n + 1);
        vector<int> pwP1(n + 1);
        pwP[0] = pwP1[0] = 1;
        for (int i = 1; i <= n; i++) {
            pwP[i] = 1LL * pwP[i - 1] * p % MOD;
            pwP1[i] = 1LL * pwP1[i - 1] * op % MOD;
        }


        vector<int> probCycle(n + 1);
        vector<vector<int> > dp(n + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        //dp[1][0] = 1;
        //dp[1][1] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                add(dp[i + 1][j], 1LL * pwP[j] * dp[i][j]);
                add(dp[i + 1][j + 1], 1LL * pwP1[i - j] * dp[i][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            probCycle[i] = 1;
            for (int j = 1; j < i; j++) {
                add(probCycle[i], MOD - 1LL * dp[i][j] * probCycle[j] % MOD);
            }
            dp[i][i] = probCycle[i];
        }

        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++) {
            // ans[i] = binom(i) + sum(j=1..i) dp[i][j] * probCycle[j] * (ans[j] + ans[i - j] - binom(i - j))
            int sum = binom(i);
            for (int j = 1; j < i; j++) {
                add(sum, 1LL * dp[i][j] * probCycle[j] % MOD * ((ll)ans[j] + ans[i - j] - binom(i - j) + MOD));
            }
            // ans[i] = sum + probCycle[i] * ans[i]
            ans[i] = 1LL * sum * inv((1 - probCycle[i] + MOD) % MOD) % MOD;
        }
        cout << ans[n] << endl;
    }


#ifdef HOME
    eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}