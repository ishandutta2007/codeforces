#include <bits/stdc++.h>

typedef long long int64;

const int C = 26;
const int N = 300;

char pa[N][N];

int n, m;
int pb[N], pc[N], p[N];
int c[N][C];

bool ck(int i, int j) {
    if (pc[i] != pc[j]) return false;
    if (i == j) return true;
    for (int k = 0; k < C; ++k) {
        if (c[i][k] != c[j][k]) return false;
    }
    return true;
}

int get() {
    p[0] = 1;
    int mx = 1, id = 0, k = 2 * n - 1, ans = pc[0] >= 0;
    for (int i = 1; i < k; ++i) {
        int i0 = i / 2, i1 = (i + 1) / 2;
        p[i] = mx > i1 ? std::min(mx - i1, p[2 * id - i]) : 0;
        if (mx <= i1 || mx - i1 <= p[2 * id - i]) {
            while (i0 - p[i] >= 0 && i1 + p[i] < n && ck(i0 - p[i], i1 + p[i]))
                ++p[i];
        }
        if (i1 + p[i] > mx) mx = i1 + p[i], id = i;
        if (pc[i1] >= 0) ans += p[i];
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    int64 ans = 0;
    for (int i = 0; i < n; ++i) scanf("%s", pa[i]);
    for (int l = 0; l < m; ++l) {
        memset(pb, 0, sizeof pb);
        memset(c, 0, sizeof c);
        for (int r = l; r < m; ++r) {
            for (int i = 0; i < n; ++i) {
                pb[i] ^= 1 << (pa[i][r] - 'a');
                pc[i] = pb[i] & (pb[i] - 1) ? -i - 1 : pb[i];
                ++c[i][pa[i][r] - 'a'];
            }
            ans += get();
        }
    }
    printf("%I64d\n", ans);
    return 0;
}