#include <bits/stdc++.h>

int a[7][8];

double d[7][8];

std::string s[5];

void swap_row(int r1, int r2) {
    for (int i = 1; i <= 7; ++i) std::swap(d[r1][i], d[r2][i]);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int h12, h13, h14, h23, h24, h34;
    std::cin >> h12 >> h13 >> h14 >> h23 >> h24 >> h34;
    int x7;
    a[1][4] = a[1][5] = a[1][6] = 1;
    a[2][2] = a[2][3] = a[2][6] = 1;
    a[3][1] = a[3][3] = a[3][5] = 1;
    a[4][2] = a[4][3] = a[4][4] = a[4][5] = 1;
    a[5][1] = a[5][3] = a[5][4] = a[5][6] = 1;
    a[6][1] = a[6][2] = a[6][5] = a[6][6] = 1;
    int ans = -1;
    int ansx[8];
    for (x7 = 0; x7 < 100005; ++x7) {
        a[1][7] = h12, a[2][7] = h13, a[3][7] = h14;
        a[4][7] = h23, a[5][7] = h24, a[6][7] = h34;
        int i, j;
        for (i = 1; i <= 6; ++i) {
            for (j = 1; j <= 7; ++j) d[i][j] = a[i][j];
        }
        for (j = 1; j <= 5; ++j) {
            int sel = -1;
            for (i = 1; i <= 6; ++i) {
                if (sel == -1 || fabs(d[i][j]) > fabs(d[sel][j])) sel = i;
            }
            swap_row(j, sel);
            for (i = j + 1; i <= 6; ++i) {
                int k;
                double koef = d[i][j] / d[j][j];
                for (k = 1; k <= 7; ++k) d[i][k] -= d[j][k] * koef;
            }
        }
        int x[8];
        for (i = 6; i >= 1; --i) {
            for (j = 6; j > i; --j) {
                double koef = d[i][j] / d[j][j];
                for (int k = 7; k >= i; --k) d[i][k] -= koef * d[j][k];
            }
            d[i][7] /= d[i][i], d[i][i] /= d[i][i], x[i] = (int)(d[i][7] + 0.5);
        }
        bool ok = true;
        int tot = 0;
        for (i = 1; i <= 6; ++i) {
            int res = 0;
            for (j = 1; j <= 6; ++j) {
                if (x[j] < 0) ok = false;
                res += a[i][j] * x[j];
            }
            tot += x[i];
            if (res != a[i][7]) ok = false;
        }
        tot += x7;
        if (!ok) {
            --h12, --h13, --h14;
            continue;
        }
        if (ans == -1 || tot < ans) {
            ans = tot;
            for (i = 1; i <= 6; ++i) ansx[i] = x[i];
            ansx[7] = x7;
        }
        --h12, --h13, --h14;
    }
    if (ans == -1) {
        printf("-1\n");
        return 0;
    }
    std::string xx[8] = {
        "", "aaab", "aaba", "aabb", "abaa", "abab", "abba", "abbb",
    };
    int i, j;
    for (i = 1; i <= 7; ++i) {
        for (j = 0; j < ansx[i]; ++j) {
            for (int k = 0; k < 4; ++k) s[k] += xx[i][k];
        }
    }
    std::cout << ans << '\n';
    for (j = 0; j < 4; ++j) std::cout << s[j].c_str() << '\n';
    return 0;
}