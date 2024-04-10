#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

bool bad[N];

int who[N], L[N], R[N], kb[N];

int main() {
    int n, m, d;
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < n; ++i) who[i] = 0;
    for (int i = 0; i < m; ++i) {
        int foo;
        scanf("%d", &foo);
        while (foo--) {
            int bar;
            scanf("%d", &bar);
            who[bar - 1] = (1 << i);
        }
    }
    int nn = (n + d - 1) / d * d;
    for (int i = n; i < nn; ++i) who[i] = 0;
    int cur = 0;
    for (int i = 0; i < nn; ++i) {
        if (i % d == 0) cur = 0;
        cur |= who[i];
        L[i] = cur;
    }
    cur = 0;
    for (int i = nn - 1; i >= 0; --i) {
        if ((i + 1) % d == 0) cur = 0;
        cur |= who[i];
        R[i] = cur;
    }
    for (int i = 0; i < (1 << m); ++i) bad[i] = false;
    for (int i = 0; i < n - d + 1; ++i) {
        int now = R[i] | L[i + d - 1];
        bad[now] = true;
    }
    for (int bit = 0; bit < m; ++bit)
        for (int i = 0; i < (1 << m); ++i)
            if ((!(i & (1 << bit))) && bad[i]) bad[i | (1 << bit)] = true;
    kb[0] = 0;
    for (int i = 1; i < (1 << m); ++i) kb[i] = kb[i & (i - 1)] + 1;
    int ans = 0;
    for (int i = 0; i < (1 << m); ++i)
        if ((!bad[i]) && kb[i] > ans) ans = kb[i];
    printf("%d\n", m - ans);
    return 0;
}