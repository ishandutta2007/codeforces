#include <bits/stdc++.h>

using namespace std;

const int M = 3050;

short L[M][M], U[M][M], R[M][M], D[M][M];

int S[M][M];

inline void inc(short A[M][M], int x, int l, int r) {
    for (int i = l; i <= r; ++i) A[x][i]++;
}

inline void prepare(short A[M][M]) {
    for (int x = 0; x < M; ++x) {
        int s = 0;
        for (int i = 0; i < M; ++i) s += A[x][i], A[x][i] = s - A[x][i];
    }
}

inline void inc2(int A[M][M], int x1, int y1, int x2, int y2) {
    for (int x = x1; x <= x2; ++x)
        for (int y = y1; y <= y2; ++y) A[x][y]++;
}

inline void prepare2(int A[M][M]) {
    for (int x = 0; x < M; ++x)
        for (int y = 0; y < M; ++y)
            A[x][y] += ((x) ? A[x - 1][y] : 0) + ((y) ? A[x][y - 1] : 0) -
                       ((x && y) ? A[x - 1][y - 1] : 0);
    for (int x = M - 1; x > 0; --x)
        for (int y = M - 1; y > 0; --y) A[x][y] = A[x - 1][y - 1];
    for (int x = 0; x < M; ++x) A[x][0] = A[0][x] = 0;
}

inline short get(short A[M][M], int x, int l, int r) {
    return A[x][r] - A[x][l];
}

inline int get2(int A[M][M], int x1, int y1, int x2, int y2) {
    return A[x2][y2] - A[x1][y2] - A[x2][y1] + A[x1][y1];
}

const int N = 100500;

int pt = 0;
int X1[N], Y1[N], X2[N], Y2[N], num[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        inc(L, x1, y1, y2 - 1);
        inc(R, x2, y1, y2 - 1);
        inc(D, y1, x1, x2 - 1);
        inc(U, y2, x1, x2 - 1);
        inc2(S, x1, y1, x2 - 1, y2 - 1);
        X1[i] = x1, Y1[i] = y1, X2[i] = x2, Y2[i] = y2;
    }
    prepare(L);
    prepare(R);
    prepare(D);
    prepare(U);
    prepare2(S);
    int ax1 = -42, ay1 = -42, ax2 = -42, ay2 = -42;
    for (int i = 0; i < n && ax1 == -42; ++i) {
        int x = X1[i], y = Y1[i];
        for (int v = 1; x + v < M - 2 && y + v < M - 2; ++v) {
            int vs = get2(S, x, y, x + v, y + v);
            if (vs != v * v) break;
            short vl = get(L, x, y, y + v);
            if (vl != v) break;
            short vd = get(D, y, x, x + v);
            if (vd != v) break;
            short vr = get(R, x + v, y, y + v);
            if (vr != v) continue;
            short vu = get(U, y + v, x, x + v);
            if (vu != v) continue;
            ax1 = x, ay1 = y, ax2 = x + v, ay2 = y + v;
            break;
        }
    }
    if (ax1 == -42)
        puts("NO");
    else {
        for (int i = 0; i < n; ++i)
            if (X1[i] >= ax1 && Y1[i] >= ay1 && X2[i] <= ax2 && Y2[i] <= ay2)
                num[pt++] = i + 1;
        printf("YES %d\n", pt);
        for (int i = 0; i < pt; ++i) printf("%d%c", num[i], " \n"[i + 1 == pt]);
    }
    return 0;
}