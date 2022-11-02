#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int C = 3;
const int R = 300005;
const int N = 3000005;
const int P = 1000000009;

struct node {
    int64 ba, bb, value;
};

int n, m;

int64 ans;
int64 w[R];
int64 a[C][C];
int64 v[R][C][C], bq[R][C][C];

node f[N];

inline void buildtree(int k, int bleft, int bright) {
    f[k].ba = f[k].bb = 0;
    if (bleft == bright) {
        f[k].value = w[bleft];
        return;
    }
    int i = (bleft + bright) >> 1;
    buildtree(k + k, bleft, i);
    buildtree(k + k + 1, i + 1, bright);
    f[k].value = f[k + k].value + f[k + k + 1].value;
    f[k].value %= P;
}

int64 check(int64 ba, int64 bb, int64 bleft, int64 bright) {
    int64 e[C][C];
    for (int i = 1; i <= 2; ++i)
        for (int j = 1; j <= 2; ++j) {
            if (bleft) {
                e[i][j] = bq[bright][i][j] - bq[bleft - 1][i][j];
            } else {
                e[i][j] = bq[bright][i][j];
            }
            if (e[i][j] < 0) e[i][j] += P;
        }
    return (ba * e[1][1] + bb * e[2][1]) % P;
}

inline void update(int k, int bleft, int i, int bright) {
    f[k + k].ba += f[k].ba;
    f[k + k].ba %= P;
    f[k + k].bb += f[k].bb;
    f[k + k].bb %= P;
    f[k + k + 1].ba += check(f[k].ba, f[k].bb, i - bleft + 1, i - bleft + 1);
    f[k + k + 1].ba %= P;
    f[k + k + 1].bb += check(f[k].ba, f[k].bb, i - bleft + 2, i - bleft + 2);
    f[k + k + 1].bb %= P;
    f[k].ba = f[k].bb = 0;
}

inline void insert(int k, int bleft, int bright, int s, int t, int num) {
    if (bleft == s && bright == t) {
        f[k].ba += check(0, 1, num - 1, num - 1);
        f[k].ba %= P;
        f[k].bb += check(0, 1, num, num);
        f[k].bb %= P;
        return;
    }
    int i = (bleft + bright) >> 1;
    update(k, bleft, i, bright);
    if (t <= i) {
        insert(k + k, bleft, i, s, t, num);
    } else if (s > i) {
        insert(k + k + 1, i + 1, bright, s, t, num);
    } else {
        insert(k + k, bleft, i, s, i, num),
            insert(k + k + 1, i + 1, bright, i + 1, t, i + 1 - s + num);
    }
    f[k].value =
        (f[k + k].value + check(f[k + k].ba, f[k + k].bb, 1, i - bleft + 1)) %
        P;
    f[k].value += (f[k + k + 1].value +
                   check(f[k + k + 1].ba, f[k + k + 1].bb, 1, bright - i)) %
                  P;
    f[k].value %= P;
}

inline void calc(int k, int bleft, int bright, int s, int t) {
    if (bleft == s && bright == t) {
        ans += f[k].value + check(f[k].ba, f[k].bb, 1, bright - bleft + 1);
        ans %= P;
        return;
    }
    int i = (bleft + bright) >> 1;
    update(k, bleft, i, bright);
    if (t <= i) {
        calc(k + k, bleft, i, s, t);
    } else if (s > i) {
        calc(k + k + 1, i + 1, bright, s, t);
    } else {
        calc(k + k, bleft, i, s, i), calc(k + k + 1, i + 1, bright, i + 1, t);
    }
    f[k].value =
        (f[k + k].value + check(f[k + k].ba, f[k + k].bb, 1, i - bleft + 1)) %
        P;
    f[k].value += (f[k + k + 1].value +
                   check(f[k + k + 1].ba, f[k + k + 1].bb, 1, bright - i)) %
                  P;
    f[k].value %= P;
}

int main() {
    scanf("%d%d", &n, &m);
    v[0][1][1] = 1;
    v[0][1][2] = 0;
    v[0][2][1] = 0;
    v[0][2][2] = 1;
    a[1][2] = a[2][1] = a[2][2] = 1;
    a[1][1] = 0;
    memset(bq, 0, sizeof(bq));
    bq[0][1][1] = 1;
    bq[0][1][2] = 0;
    bq[0][2][1] = 0;
    bq[0][2][2] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 2; ++j) {
            for (int k = 1; k <= 2; ++k) {
                for (int l = 1; l <= 2; ++l) {
                    v[i][j][k] += v[i - 1][j][l] * a[l][k] % P, v[i][j][k] %= P;
                }
            }
        }
        for (int j = 1; j <= 2; ++j) {
            for (int k = 1; k <= 2; ++k) {
                bq[i][j][k] = (bq[i - 1][j][k] + v[i][j][k]) % P;
            }
        }
    }
    for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
    buildtree(1, 1, n);
    while (m--) {
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);
        if (type == 1) {
            insert(1, 1, n, x, y, 1);
        } else {
            ans = 0;
            calc(1, 1, n, x, y);
            printf("%d\n", ans);
        }
    }
}