#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int used[20];
int d[20];
int a[20][20];
int64 dd[1 << 16];

int64 calc(int n, int x) {
    int i, j, k, b1, bit, tmp, cnt;
    vector<int> aa;
    bit = (1 << (x + 1)) - 1;
    tmp = 0;
    aa.clear();
    for (i = 0; i <= x; ++i) {
        tmp |= (1 << d[i]);
        aa.push_back(d[i]);
    }
    for (i = 0; i < n; ++i) {
        if (((1 << i) & tmp) == 0) aa.push_back(i);
    }
    memset(dd, 0, sizeof(dd));
    dd[bit] = 1;
    for (i = bit; i < (1 << n); ++i) {
        i |= bit;
        cnt = 0;
        for (j = 0; j < n; ++j) {
            if (((1 << j) & i) != 0) ++cnt;
        }
        for (j = 0; j < n; ++j)
            if (((1 << j) & i) == 0) {
                b1 = 1;
                for (k = 0; k < n; ++k) {
                    if (a[j][k] == 1) {
                        if ((k <= x) && (d[k] < aa[cnt])) {
                            b1 = 0;
                            break;
                        }
                    }
                    if (a[k][j] == 1) {
                        if (((1 << k) & i) == 0) {
                            b1 = 0;
                            break;
                        }
                        if ((k <= x) && (d[k] > aa[cnt])) {
                            b1 = 0;
                            break;
                        }
                    }
                }
                if (b1 == 1) dd[i | (1 << j)] += dd[i];
            }
    }
    return dd[(1 << n) - 1];
}

int main() {
    int64 ye, tmp;
    int i, j, n, m, x, y, k, b1;
    cin >> n >> ye >> m;
    ye -= 2000;
    memset(a, 0, sizeof(a));
    for (i = 0; i < m; ++i) {
        cin >> x >> y, --x, --y;
        a[x][y] = 1;
    }
    memset(used, 0, sizeof(used));
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j)
            if (used[j] == 0) {
                b1 = 1;
                for (k = 0; k <= i; ++k) {
                    if ((a[i][k] == 1) && (d[k] < j)) {
                        b1 = 0;
                        break;
                    }
                    if ((a[k][i] == 1) && (d[k] > j)) {
                        b1 = 0;
                        break;
                    }
                }
                if (b1 == 0) continue;
                d[i] = j;
                tmp = calc(n, i);
                if (tmp >= ye) {
                    used[j] = 1;
                    break;
                }
                ye -= tmp;
            }
        if (j == n) {
            printf("The times have changed\n");
            return 0;
        }
    }
    for (i = 0; i < n; ++i) {
        if (i != 0) printf(" ");
        printf("%d", d[i] + 1);
    }
    printf("\n");
    return 0;
}