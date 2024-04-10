#include <bits/stdc++.h>

using int64 = long long;

const int N = 10000005;

int64 n, pcnt, Mus, Cnt1, Cnt2, Cnt3, Cnt4;
int64 p[N], c[N], Phi[N], Cnt[N], Min[N], Sum[N];

inline int64 Max(int64 a, int64 b) { return a > b ? a : b; }
inline int64 calc(int64 l, int64 r) { return l > r ? 0 : Sum[r] - Sum[l - 1]; }

int main() {
    std::cin >> n;
    c[1] = Phi[1] = 1;
    for (int64 i = 2; i <= n; ++i) {
        if (c[i] == 0) p[++pcnt] = i, Min[i] = i, Phi[i] = i - 1;
        for (int64 j = 1; j <= pcnt; ++j) {
            if (i * p[j] > n) break;
            c[i * p[j]] = 1, Min[i * p[j]] = p[j];
            if (i % p[j] == 0) {
                Phi[i * p[j]] = Phi[i] * p[j];
                break;
            }
            Phi[i * p[j]] = Phi[i] * (p[j] - 1);
        }
        Cnt[Min[i]]++;
    }
    for (int64 i = 1; i <= n; ++i) Sum[i] = Sum[i - 1] + Cnt[i];
    Mus = Cnt1 = (n - 1) * (n - 2) / 2;
    for (int64 i = 2; i <= n; ++i) Cnt1 -= (Phi[i] - 1);
    for (int64 i = 1; i <= pcnt; ++i) {
        Cnt3 += Cnt[p[i]] * calc(Max(n / p[i] + 1, p[i] + 1), n / 2);
        Cnt4 += Cnt[p[i]] * calc(Max(n / 2 + 1, p[i] + 1), n);
    }
    Cnt2 = (n - 1) * (n - 2) / 2 - Cnt1 - Cnt3 - Cnt4;
    std::cout << Cnt1 * 1 + Cnt2 * 2 + Cnt3 * 3 + Cnt4 * 0 << std::endl;
    return 0;
}