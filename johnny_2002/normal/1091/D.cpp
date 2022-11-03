#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

const int N = 1e6 + 10;
const int MOD = 998244353;


long long fac[N], p2[N];
long long rev[N], revfac[N];
long long C(int n, int k) {
    return fac[n] * revfac[k] % MOD * revfac[n - k] % MOD;
}
int main() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % MOD;
    p2[0] = 1;
    for(int i = 1; i < N; i++) p2[i] = p2[i - 1] * 2 % MOD;
    rev[1] = 1;
    for(int i = 2; i < N; i++) rev[i] = MOD - (MOD / i) * rev[MOD % i] % MOD;
    revfac[0] = 1;
    for(int i = 1; i < N; i++) revfac[i] = revfac[i - 1] * rev[i] % MOD;
    int n;
    cin >> n;
    long long ans = fac[n] * n - n + 1;
    for(int i = 1; i < n; i++) {
        //cout << C(n, i) * fac[n - i] * i << " " << i << '\n';
        ans = (ans - C(n, i + 1) * fac[n - i - 1] % MOD * i % MOD * i) % MOD;
    }
    cout << (ans + MOD) % MOD;
}