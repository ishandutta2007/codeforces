#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5E5, M = 1E7, P = 1E9 + 7;
int n, cnt_primes;
int a[N], mu[M + 1], primes[M], cnt[M + 1], pw[N + 1];
bool isprime[M + 1];
void sieve() {
    memset(isprime + 2, 1, (M - 1) * sizeof(bool));
    mu[1] = 1;
    for (int i = 2; i <= M; ++i) {
        if (isprime[i]) {
            primes[cnt_primes++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < cnt_primes; ++j) {
            if (i * primes[j] > M)
                break;
            isprime[i * primes[j]] = false;
            if (i % primes[j] == 0)
                break;
            mu[i * primes[j]] = -mu[i];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    pw[0] = 1;
    for (int i = 1; i <= n; ++i)
        pw[i] = 2 * pw[i - 1] % P;
    for (int i = 0; i < cnt_primes; ++i)
        for (int j = M / primes[i]; j > 0; --j)
            cnt[j] += cnt[j * primes[i]];
    int ans = 0;
    for (int i = 1; i <= M; ++i)
        ans = (ans - 1LL * mu[i] * (pw[cnt[i]] - 1) * (n - cnt[i])) % P;
    ans = (ans + P) % P;
    cout << ans << endl;
    return 0;
}