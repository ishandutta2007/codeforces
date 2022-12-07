#include <iostream>
#include <algorithm>
#include <memory.h>
#include <stdio.h>

using namespace std;

const int N = 100111;
int a[N], l[N], r[N], ans[N];
int cans[N];

int rmq[21][N];

int st[N];


int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", l + i, r + i, ans + i);
        l[i]--;
        r[i]--;
    }

    for (int lg = 0; lg < 31; ++lg) {
        memset(st, 0, sizeof(st));
        for (int i = 0; i < m; ++i) {
            if (ans[i] & (1 << lg)) {
                st[l[i]]++;
                st[r[i] + 1]--;
            }
        }

        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += st[i];
            if (s) cans[i] += (1 << lg);
        }
    }

    for (int i = 0; i < n; ++i) rmq[0][i] = cans[i];
    for (int lg = 1; lg < 21; ++lg) {
        int shift = 1 << (lg - 1);
        for (int j = 0; j + shift < n; ++j)
            rmq[lg][j] = rmq[lg - 1][j] & rmq[lg - 1][j + shift];
    }

    for (int i = 0; i < m; ++i) {
        int layer = 0;
        while ((1 << layer) * 2 < r[i] - l[i] + 1) ++layer;
        int got = rmq[layer][ l[i] ] & rmq[ layer ][ r[i] - (1 << layer) + 1 ];
        if (got != ans[i]) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    for (int i = 0; i < n; ++i) printf("%d ", cans[i]);
    cout << endl;

    return 0;
}