#include <bits/stdc++.h>

typedef std::complex<double> comp;

double PI = 4 * atan(1);

const int C = 20;
const int N = 1 << C;
const int M = N + 5;

comp w[M], A[M], B[M], F[2][M];

char s[M];

int n;
int a[M], ans[M], rev[M];

void initFFT() {
    for (int i = 0; i < N; ++i) w[i] = comp(cos(2 * PI * i / N), sin(2 * PI * i / N));
    rev[0] = 0;
    for (int mask = 1; mask < N; ++mask) {
        int k = 0;
        while (((mask >> k) & 1) == 0) k++;
        rev[mask] = rev[mask ^ (1 << k)] ^ (1 << (C - 1 - k));
    }
}

void FFT(comp* A, int k) {
    int L = 1 << k;
    for (int mask = 0; mask < L; ++mask) F[0][rev[mask] >> (C - k)] = A[mask];
    int t = 0, nt = 1;
    for (int lvl = 0; lvl < k; ++lvl) {
        int len = 1 << lvl;
        for (int st = 0; st < L; st += (len << 1)) {
            for (int i = 0; i < len; ++i) {
                comp ad = F[t][st + len + i] * w[i << (C - 1 - lvl)];
                F[nt][st + i] = F[t][st + i] + ad;
                F[nt][st + len + i] = F[t][st + i] - ad;
            }
        }
        std::swap(t, nt);
    }
    for (int i = 0; i < L; ++i) A[i] = F[t][i];
    return;
}

void solve() {
    scanf("%d %s", &n, s);
    int k = 0;
    while ((1 << k) < (2 * n + 3)) k++;
    if (k > 5) {
        int L = 1 << k;
        for (int i = 0; i < L; ++i) A[i] = B[i] = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'V') {
                A[i] = 1;
            } else if (s[i] == 'K') {
                B[n - i] = 1;
            }
        }
        FFT(A, k);
        FFT(B, k);
        for (int i = 0; i < L; ++i) A[i] *= B[i];
        FFT(A, k);
        for (int i = 0; i < L; ++i) a[i] = (int)(A[i].real() / L + 0.5);
        std::reverse(a + 1, a + L);
        for (int d = 1; d <= n; ++d) ans[d] = 1;
        for (int d = 1; d < n; ++d) {
            if (a[n - d] + a[n + d] > 0) ans[d] = 0;
        }
    } else {
        for (int d = 1; d <= n; ++d) {
            ans[d] = 1;
            for (int i = 0; i + d < n; ++i) {
                if (s[i] != s[i + d] && s[i] != '?' && s[i + d] != '?') ans[d] = 0;
            }
        }
    }
    int cnt = 0;
    for (int x = 1; x <= n; ++x) {
        for (int y = x + x; y <= n; y += x) ans[x] &= ans[y];
        cnt += ans[x];
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; ++i) {
        if (ans[i]) printf("%d ", i);
    }
    printf("\n");
}

int main() {
    initFFT();
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}