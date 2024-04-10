#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
    int x = 0, f = 1, c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
    for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
    return f ? x : -x;
}
int mod = 1000000007;
int qp(int x, int n) {
    return !n ? 1 : 1LL * qp(1LL * x * x % mod, n >> 1) * (n & 1 ? x : 1) % mod;
}
const int N = 100005;
int fac[N], invfac[N], ten[N];
int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return 1LL * fac[n] * invfac[k] % mod * invfac[n - k] % mod;
}
char d[N];
int main() {
    fac[0] = invfac[0] = ten[0] = 1;
    for (int i = 1; i < N; ++ i) {
        fac[i] = 1LL * fac[i - 1] * i % mod;
        invfac[i] = qp(fac[i], mod - 2);
        ten[i] = ten[i - 1] * 10LL % mod;
    }
    int n = read(), k = read();
    scanf("%s", d);
    for (int i = 0; i < n; ++ i) d[i] -= '0';
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
        (ans += 1LL * ten[n - 1 - i] * C(i, k) % mod * d[i] % mod) %= mod;
    }
    int tmp = 0;
    for (int i = n - 2; ~i; -- i) {
        (tmp += 1LL * ten[n - 2 - i] * C(i, k - 1) % mod) %= mod;
        (ans += 1LL * tmp * d[i] % mod) %= mod;
    }
    printf("%d\n", ans);
    return 0;
}