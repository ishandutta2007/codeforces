#include <bits/stdc++.h>
using namespace std;

int MOD = 998'244'353;

long long power(long long base, int e, int M=MOD)
{
    long long result = 1;
    base %= M;
    while (e) {
        if (e & 1)
            result = (result * base) % M;
        base = (base * base) % M;
        e >>= 1;
    }
    return result;
}

auto inverse(long long x) {
    return power(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;

    auto p = a * inverse(b) % MOD;
    auto q = (b - a) * inverse(b) % MOD;
    vector<long long> ps(n+1);
    vector<long long> qs(n+1);
    ps[0] = 1;
    qs[0] = 1;
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] * p % MOD;
        qs[i] = qs[i - 1] * q % MOD;
    }

    vector<vector<long long>> cp(n + 1, vector<long long>(n + 1, 0));
    cp[0][0] = 1;
    for (int s = 1; s <= n; s++) {
        cp[s][0] = 1;
        for (int i = 1; i <= n; i++) {
            cp[s][i] = ((cp[s - 1][i] * ps[i] % MOD) + (cp[s - 1][i -1] * qs[s - i] % MOD)) % MOD;
        }
    }

    vector<long long> strong(n + 1, 0);
    strong[0] = 1;
    strong[1] = 1;
    for (int i = 2; i <= n; i++) {
        strong[i] = 1;
        for (int j = 1; j < i; j++) {
            strong[i] -= strong[j] * cp[i][j] % MOD;
        }
        strong[i] = (strong[i] % MOD + MOD) % MOD;
    }

    vector<long long> ans(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        long long sum = 0;
        for (int j = 1; j < i; j++) {
            sum += strong[j] * cp[i][j] % MOD * (j * (j - 1) / 2 + j * (i - j) + ans[j] + ans[i - j]) % MOD;
        }
        sum %= MOD;
        // ans[i] = sum + strong[i] * cp[i][i] * (i * (i - 1) / 2 + ans[i])
        sum = (sum + strong[i] * cp[i][i] % MOD * (i * (i - 1) / 2)) % MOD;
        // ans[i] = sum + strong[i] * cp[i][i] * ans[i]
        // ans[i] * (1 - strong[i] * cp[i][i]) = sum
        long long g = 1 - strong[i] * cp[i][i] % MOD;
        g = (g + MOD) % MOD;
        long long gi = inverse(g);
        ans[i] = sum * gi % MOD;
    }

    cout << ans[n] << '\n';
}