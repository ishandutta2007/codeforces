#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const lint M = 2e5 + 10, MOD = 998244353;

lint n, F[M], I[M]; string S;

lint _pow(lint a, lint x) {
    lint ret = 1;
    while (x) {
        if (x & 1) ret = ret * a % MOD;
        a = a * a % MOD; x /= 2;
    }
    return ret;
}
void solve() {
    cin >> n >> S; S = S + '0';
    int a = 0, b = 0;
    for (int i = 0, s = 0; i <= n; i++) {
        if (S[i] == '1') s += 1;
        else if (s) {
            a += (s / 2); b += (s % 2); s = 0;
        }
    }
    cout << F[n - a - b] * I[a] % MOD * I[n - 2 * a - b] % MOD << '\n';
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    F[0] = 1;
    for (int i = 1; i < M; i++) F[i] = F[i - 1] * i % MOD;
    I[M - 1] = _pow(F[M - 1], MOD - 2);
    for (int i = M - 1; i > 0; i--) I[i - 1] = I[i] * i % MOD;

    int t; cin >> t;
    while (t--) {
        solve();
    }
}