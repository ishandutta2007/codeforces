#include <bits/stdc++.h>

using namespace std;

typedef long long big;

const int MAXN = 1000000, P = 998244353;
// int F[MAXN + 1][MAXN + 1];
int Fac[MAXN + 1], InvFac[MAXN + 1];

int inv(int x) { return x == 1 ? 1 : int(big(P - P / x) * inv(P % x) % P); }

inline int C(int n, int m) {
    return int((big)Fac[n] * InvFac[m] % P * InvFac[n - m] % P);
}

int qpow(int x, int n) {
    int s = 1;
    while (n) {
        if (n & 1)
            s = int((big)s * x % P);
        x = int((big)x * x % P);
        n >>= 1;
    }
    return s;
}

inline int f(int k, int c) {
    return int((big)Fac[k] * qpow(k + 1, c - k) % P);
}

int main() {
    Fac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        Fac[i] = int((big)Fac[i - 1] * i % P);
    InvFac[MAXN] = inv(Fac[MAXN]);
    for (int i = MAXN; i >= 1; i--)
        InvFac[i - 1] = int((big)InvFac[i] * i % P);
    
    /*
    for (int c = 1; c <= MAXN; c++)
        F[0][c] = 1;
    for (int k = 1; k < MAXN; k++) {
        for (int c = k + 1; c <= MAXN; c++) {
            for (int i = k; i <= c; i++)
                F[k][c] = int((F[k][c] + (big)C(c - k, i - k) * F[k - 1][i]) % P);
            assert(F[k][c] == f(k, c));
        }
    }
    */
    
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int n, k, flag = 1;
        scanf("%d%d", &n, &k);
        int ans = Fac[k];
        for (int i = 1; i <= n; i++) {
            int v;
            scanf("%d", &v);
            if ((i == 1 || i > n - k) && v == -1)
                v = 0;
            if (i > n - k && v != 0)
                flag = 0;
            if (v == -1)
                ans = int((big)ans * (k + 1 + (i - 1)) % P);
            else if (v == 0 && i <= n - k)
                ans = int((big)ans * (k + 1) % P);
        }
        printf("%d\n", flag ? ans : 0);
    }
    return 0;
}