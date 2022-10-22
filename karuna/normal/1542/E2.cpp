#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 510, N = 13e4 + 10;

lint n, MOD, F[M], G[M], A[N << 1], B[N << 1], An[N << 1];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> MOD;
    F[0] = 1; G[0] = 1;
    for (int i = 1; i < M; i++) {
        F[i] = F[i - 1] * (n + 1 - i) % MOD;
        G[i] = G[i - 1] * i % MOD;
    }

    lint ans = 0;
    for (int i = 1; i < (N << 1); i++) {
        if (i < N) A[i] = 1;
        B[i] = (B[i - 1] + A[i]) % MOD;
    }
    for (int i = 2; i <= n; i++) {
        lint s = A[1] * (i * (i + 1) / 2) % MOD;
        lint l = N - i * (i - 1) / 2 - 5, r = N + i * (i - 1) / 2 + 5;
        for (int j = 1; j < l; j++) An[j] = G[i] * G[i] % MOD;
        for (int j = l; j <= r; j++) {
            s = (s + MOD) % MOD; An[j] = s;
            s = s - B[j] + B[j - i];
            s = s + A[j + 1] * i;
        }
        s = 0;
        for (int j = r; j >= l; j--) {
            s = (s + MOD) % MOD; An[j] += s;
            s = s - B[j + i - 1] + B[j];
            s = s + A[j] * (i - 1);
        }
        for (int j = 1; j < (N << 1); j++) {
            A[j] = An[j] % MOD;
            B[j] = (B[j - 1] + A[j]) % MOD;
        }
        s = 0;
        for (int j = 1; j <= i; j++) {
            s += A[N + j] * (i + 1 - j);
        }
        s %= MOD;
        ans += F[n - i - 1] * s % MOD;
    }
    cout << ans % MOD;
}