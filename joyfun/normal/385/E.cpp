#include <stdio.h>
#include <string.h>

__int64 n, sx, sy, dx, dy, t;

struct mat {
    __int64 v[10][10];
    mat() {
        memset(v, 0, sizeof(v));
    }
    void init() {
        int m[10][10] = {
            {2, 1, 1, 0, 1, 2},
            {1, 2, 0, 1, 1, 2},
            {1, 1, 1, 0, 1, 2},
            {1, 1, 0, 1 ,1, 2},
            {0, 0, 0, 0, 1, 1},
            {0, 0, 0, 0, 0, 1},
        };
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                v[i][j] = m[i][j];
    }
    mat operator * (const mat &a) {
        mat c;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                for (int k = 0; k < 6; k++) {
                    c.v[i][j] = ((c.v[i][j] + v[i][k] * a.v[k][j]) % n + n) % n;
                }
        return c;
    }
};

mat pow_mod(mat a, __int64 k) {
    if (k <= 1) return a;
    mat c = pow_mod(a * a, k / 2);
    if (k % 2)
        c = c * a;
    return c;
}

int main() {
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &n, &sx, &sy, &dx, &dy, &t);
    mat m; m.init();
    m = pow_mod(m, t);
    __int64 ansx = (((m.v[0][0] * (sx - 1) + m.v[0][1] * (sy - 1) + m.v[0][2] * dx + m.v[0][3] * dy + m.v[0][5]) % n) + n) % n;
    __int64 ansy = (((m.v[1][0] * (sx - 1) + m.v[1][1] * (sy - 1) + m.v[1][2] * dx + m.v[1][3] * dy + m.v[1][5]) % n) + n) % n;
    printf("%I64d %I64d\n", ansx + 1, ansy + 1);
    return 0;
}