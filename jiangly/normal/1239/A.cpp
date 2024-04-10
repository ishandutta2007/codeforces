#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1E9 + 7, MAX_N = 1E5;
int f[MAX_N + 1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= MAX_N; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    cout << 2LL * ((f[n] + f[m] - 1) % MOD + MOD) % MOD << "\n";
    return 0;
}