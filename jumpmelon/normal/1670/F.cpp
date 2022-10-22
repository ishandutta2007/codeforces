#include <bits/stdc++.h>

using namespace std;

typedef long long big;

const int MAXN = 1000, P = 1000000007;
int n, Fac[MAXN + 5], InvFac[MAXN + 5];
int F[2][MAXN + 5];

int inv(int x) { return x == 1 ? 1 : int(big(P - P / x) * inv(P % x) % P); }

inline int C(int k, int r) {
    return int((big)Fac[k] * InvFac[r] % P * InvFac[k - r] % P);
}

int calc(big r, big z) {
    int p = 0;
    for (int i = 0; i <= n; i++)
        F[p][i] = 1;
    for (int k = 0; k < 64; k++) {
        for (int s = 0; s <= n; s++) {
            F[p ^ 1][s] = 0;
            int t = 2 * s + int(r >> k & 1);
            for (int i = int(z >> k & 1); i <= n && i <= t; i += 2)
                F[p ^ 1][s] = int((F[p ^ 1][s] + (big)C(n, i) * F[p][min(t - i, n)]) % P);
        }
        p ^= 1;
    }
    return F[p][0];
}

int main() {
    big l, r, z;
    scanf("%d%lld%lld%lld", &n, &l, &r, &z);

    Fac[0] = 1;
    for (int i = 1; i <= n; i++)
        Fac[i] = int((big)Fac[i - 1] * i % P);
    InvFac[n] = inv(Fac[n]);
    for (int i = n; i >= 1; i--)
        InvFac[i - 1] = int((big)InvFac[i] * i % P);

    printf("%d\n", (calc(r, z) + P - calc(l - 1, z)) % P);
    return 0;
}