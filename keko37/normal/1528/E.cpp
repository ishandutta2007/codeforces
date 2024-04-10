#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1000005;
const int MOD = 998244353;

int n, sol;
int dp[MAXN], sum[MAXN];

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    dp[0] = dp[1] = 1;
    sum[0] = 1; sum[1] = 2;
    for (int i = 2; i <= n; i++) {
        dp[i] = mul(dp[i - 1], sum[i - 2]);
        dp[i] = add(dp[i], (llint) dp[i - 1] * (dp[i - 1] + 1) / 2 % MOD);
        sum[i] = add(sum[i - 1], dp[i]);
    }
    sol = mul(dp[n], sub(sum[n], 1));
    sol = add(sol, mul((llint) dp[n] * (dp[n] + 1) / 2 % MOD, sum[n - 1]));
    sol = add(sol, mul(mul(dp[n], mul(sub(dp[n], 1), sub(dp[n], 2))), (MOD + 1) / 6));
    sol = add(sol, mul(dp[n], sub(dp[n], 1)));
    sol = add(sol, dp[n]);
    sol = sub(mul(2, sol), 1);
    for (int i = 1; i <= n-2; i++) {
        sol = add(sol, mul(sub(dp[i + 1], dp[i]), sub(dp[n - i], 1)));
    }
    cout << sol;
    return 0;
}