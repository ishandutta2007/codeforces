#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const lint M = 1e6 + 10, MOD = 1e9 + 7;
lint n, F[M], I[M];


lint _pow(lint a, lint x = MOD - 2) {
    lint ret = 1;
    while (x) {
        if (x & 1) ret = ret * a % MOD;
        x /= 2; a = a * a % MOD;
    }
    return ret;
}
lint func(lint n, lint r) {
    if (r > n || r < 0) return 0;
    return F[n] * I[r] % MOD * I[n - r] % MOD;
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    F[0] = 1;
    for (int i = 1; i < M; i++) {
        F[i] = F[i - 1] * i % MOD;
    }
    I[M - 1] = _pow(F[M - 1]);
    for (int i = M - 1; i >= 1; i--) {
        I[i - 1] = I[i] * i % MOD;
    }
    lint ans = 0;
    for (int i = 2; i <= n; i += 2) {
        ans = (ans + F[i] * (MOD + func(i + 1, n - i) - func(i - 1, n - i - 2) % MOD)) % MOD;
    }
    cout << 2 * ans % MOD;
}