#include <bits/stdc++.h>

using int64 = long long;

const int C = 25;
const int N = 100005;

int L, R;
int a[N], b[N];

int64 tt;
int64 d[C][N];

inline void add(int x) { tt += b[x]++; }

inline void sub(int x) { tt -= --b[x]; }

inline void moveL(int tL) {
    while (L < tL) sub(a[++L]);
    while (L > tL) add(a[L--]);
}

inline void moveR(int tR) {
    while (R < tR) add(a[++R]);
    while (R > tR) sub(a[R--]);
}

int main() {
    std::queue<std::tuple<int, int, int, int> > q;
    int i, j, k, n, m;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        d[0][i] = 1e18;
    }
    for (i = 1; i <= m; i++) {
        q.emplace(1, n, 0, n - 1);
        while (!q.empty()) {
            int S, E, L, R, M;
            std::tie(S, E, L, R) = q.front();
            q.pop();
            if (S > E) continue;
            M = S + E >> 1;
            moveR(M);
            d[i][M] = 1e18;
            for (j = k = L; j <= R && j < M; j++) {
                moveL(j);
                int64 t = d[i - 1][j] + tt;
                if (t < d[i][M]) {
                    d[i][M] = t;
                    k = j;
                }
            }
            q.emplace(S, M - 1, L, k);
            q.emplace(M + 1, E, k, R);
        }
    }
    printf("%lld\n", d[m][n]);
    return 0;
}