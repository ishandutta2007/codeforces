#include <bits/stdc++.h>

using namespace std;

const int maxn = 505;

int row[maxn][maxn];
int col[maxn][maxn];
char table[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int h, w;
    scanf("%d%d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", &table[i]);
    }

    for (int r = 0; r < h; r++) {
        for (int c = 1; c < w; c++) {
            row[r][c] = row[r][c - 1];
            if (table[r][c] == '.' && table[r][c - 1] == '.') {
                row[r][c]++;
            }
        }
    }
    for (int c = 0; c < w; c++) {
        for (int r = 1; r < h; r++) {
            col[c][r] = col[c][r - 1];
            if (table[r][c] == '.' && table[r - 1][c] == '.') {
                col[c][r]++;
            }
        }
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        r1--; c1--; r2--; c2--;
        int res = 0;
        for (int r = r1; r <= r2; r++) {
            res += row[r][c2];
            if (c1 != 0) {
                res -= row[r][c1 - 1];
                if (table[r][c1] == '.' && table[r][c1 - 1] == '.') {
                    res--;
                }
            }
        }
        for (int c = c1; c <= c2; c++) {
            res += col[c][r2];
            if (r1 != 0) {
                res -= col[c][r1 - 1];
                if (table[r1][c] == '.' && table[r1 - 1][c] == '.') {
                    res--;
                }
            }
        }
        printf("%d\n", res);
    }
}