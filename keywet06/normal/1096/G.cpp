#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int N = 1 << 21;
const int M = 1 << 20;
const int P = 998244353;

int rev[N];
int64 fac[N], ifac[N], wnori[N], *wn = wnori + M;

inline int64 qpow(int64 a, int64 x) {
    int64 ans = 1;
    for (; x; x >>= 1, a = a * a % P)
        if (x & 1) ans = ans * a % P;
    return ans;
}
inline int pmd(int x) { return x < P ? x : x - P; }
inline int qmd(int x) { return x < 0 ? x + P : x; }
inline int64 C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fac[n] * ifac[r] % P * ifac[n - r] % P;
}

void pre() {
    int i;
    int64 g = qpow(3, (P - 1) / N), gi = qpow(g, P - 2);

    wn[0] = 1;
    for (i = 1; i < M; ++i) {
        wn[i] = wn[i - 1] * g % P, wn[-i] = wn[-i + 1] * gi % P;
    }
    fac[0] = 1;
    for (i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % P;
    ifac[N - 1] = qpow(fac[N - 1], P - 2);
    for (i = N - 2; ~i; --i) ifac[i] = ifac[i + 1] * (i + 1) % P;
}

int mp[N];

void fft(int *a, int N, int dft) {
    int step, i, j, cur = 0, stc = N * dft;
    for (i = 0; i < N; i++)
        if (i < (rev[i] = (rev[i >> 1] >> 1) | (N >> 1) * (i & 1)))
            swap(a[i], a[rev[i]]);
    for (step = 1; step < N; step <<= 1) {
        stc /= 2;
        for (i = 0; i < N; i += step << 1, cur = 0) {
            for (j = i; j < i + step; j++, cur += stc) {
                int x = a[j], y = a[j + step] * wn[cur] % P;
                a[j] = pmd(x + y);
                a[j + step] = qmd(x - y);
            }
        }
    }

    if (!~dft) {
        int64 invn = qpow(N, P - 2);
        for (i = 0; i < N; ++i) a[i] = a[i] * invn % P;
    }
}

int n, mx;

void solve() {
    int k, i, x;
    int64 ans = 0;
    scanf("%d%d", &n, &k);
    for (i = 0; i < k; ++i) {
        scanf("%d", &x);
        mx = max(mx, x);
        ++mp[x];
    }
    fft(mp, N, 1);
    for (i = 0; i < N; i++) mp[i] = qpow(mp[i], n >> 1);
    fft(mp, N, -1);
    for (i = 0; i < N; i++) ans = (ans + (int64)mp[i] * mp[i]) % P;
    printf("%lld\n", ans);
}

int main() {
    pre();
    solve();
    return 0;
}