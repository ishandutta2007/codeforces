#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const lint M = 3e6 + 10, MOD = 1e9 + 7;

lint n, q, F[M], I[M];
lint A[M], B[M];

lint _pow(lint a, lint x = MOD - 2) {
    lint ret = 1;
    while (x) {
        if (x & 1) ret = ret * a % MOD;
        x /= 2; a = a * a % MOD;
    }
    return ret;
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> q;
    F[0] = 1;
    for (int i = 1; i <= 3 * n; i++) {
        F[i] = F[i - 1] * i % MOD;
    }
    I[3 * n] = _pow(F[3 * n]);
    for (int i = 3 * n; i >= 1; i--) {
        I[i - 1] = I[i] * i % MOD;
    }

    for (int i = 0; i < 3 * n; i++) {
        A[i] = F[3 * n] * I[i] % MOD * I[3 * n - i] % MOD;
    }
    for (int i = 0; i <= 3 * n - 3; i++) {
        B[i] = A[i];
        A[i + 1] = (A[i + 1] + 3 * (MOD - A[i])) % MOD;
        A[i + 2] = (A[i + 2] + 3 * (MOD - A[i])) % MOD;
    }
    for (int i = 0; i <= 3 * n; i++) {
        A[i] = B[i];
        if (i >= 1) A[i] = (A[i] + 3 * B[i - 1]);
        if (i >= 2) A[i] = (A[i] + 3 * B[i - 2]);
        if (i >= 3) A[i] = (A[i] + B[i - 3]);
        A[i] %= MOD;
    }
    while (q--) {
        int x; cin >> x;
        cout << A[3 * n - x] << '\n';
    }

}