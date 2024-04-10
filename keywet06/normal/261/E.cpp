#include <bits/stdc++.h>

using int64 = long long;

const int INF = 1e9;
const int INFp = INF + 1000;

const int N = 4000005;

bool u[100], g[N];

int k, i, j, Tmp, l, r, p, e = 1, Ans;
int D[N], V[N];

int main() {
    std::cin >> l >> r >> p;
    for (i = 2; i < 100; ++i) {
        if (!u[i]) {
            for (j = i * i; j < 100; j += i) u[j] = 1;
        }
    }
    V[0] = 1;
    for (i = 2; i < 100; ++i) {
        if (!u[i]) {
            int ee = e;
            for (j = 0; j < ee; ++j) {
                Tmp = V[j];
                while (Tmp * 1ll * i <= INFp) Tmp *= i, V[e++] = Tmp;
            }
        }
    }
    std::sort(V, V + e);
    for (i = 1, g[0] = 1; i < e; ++i) D[i] = INF;
    for (i = 2; i <= p; ++i) {
        j = 0, k = 0;
        while (true) {
            Tmp = V[j] * i;
            while (k < e && V[k] < Tmp) ++k;
            if (k == e) break;
            if (V[k] == Tmp && D[k] > D[j] + 1) {
                D[k] = D[j] + 1;
                if (D[k] + i <= p) g[k] = 1;
            }
            ++j;
        }
    }
    for (i = 0; i < e; ++i) Ans += l <= V[i] && V[i] <= r && g[i];
    std::cout << Ans << '\n';
    return 0;
}