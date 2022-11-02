#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

const char dir[4] = {'U', 'R', 'D', 'L'};
const int C = 55;
const int N = 400010;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int64 INF = int64(1e17);

int n, b, q;
int xa[N], ya[N], xb[N], yb[N], arrd[N], wx[N], wy[N], wd[N], arr[N];
int pv[C][N];

int64 when[N], dist[N], qt[N];
int64 pt[C][N];

inline int mabs(int x) { return (x > 0 ? x : -x); }

void get_next_all() {
    for (int i = 1; i <= n + q; ++i) {
        int cx = wx[i], cy = wy[i];
        arr[i] = 0;
        when[i] = 0;
        while (cx >= 0 && cy >= 0 && cx <= b && cy <= b) {
            for (int j = 1; j <= n; ++j) {
                if (xa[j] <= cx && cx <= xb[j] || xb[j] <= cx && cx <= xa[j]) {
                    if (ya[j] <= cy && cy <= yb[j] ||
                        yb[j] <= cy && cy <= ya[j]) {
                        arr[i] = j;
                        break;
                    }
                }
            }
            if (arr[i] > 0) break;
            ++when[i];
            cx += dx[wd[i]];
            cy += dy[wd[i]];
        }
        if (arr[i] == 0) when[i] = INF;
    }
}

int main() {
    std::cin >> n >> b;
    for (int i = 1; i <= n; ++i) {
        std::cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
        if (yb[i] > ya[i]) {
            arrd[i] = 0;
        } else if (xb[i] > xa[i]) {
            arrd[i] = 1;
        } else if (yb[i] < ya[i]) {
            arrd[i] = 2;
        } else {
            arrd[i] = 3;
        }
        wx[i] = xb[i] + dx[arrd[i]];
        wy[i] = yb[i] + dy[arrd[i]];
        wd[i] = arrd[i];
    }
    scanf("%d", &q);
    for (int i = n + 1; i <= n + q; ++i) {
        char foo;
        std::cin >> wx[i] >> wy[i] >> foo >> qt[i];
        wd[i] = 0;
        for (int j = 0; j < 4; ++j) {
            if (foo == dir[j]) wd[i] = j;
        }
    }
    get_next_all();
    for (int i = 1; i <= n + q; ++i) {
        if (arr[i] == 0) {
            dist[i] = INF;
        } else {
            dist[i] = mabs(wx[i] - xb[arr[i]]) + mabs(wy[i] - yb[arr[i]]);
        }
    }
    arr[0] = 0;
    when[0] = INF;
    dist[0] = INF;
    for (int i = 0; i <= n; ++i) pv[0][i] = arr[i], pt[0][i] = dist[i] + 1;
    for (int j = 1; j <= 50; ++j)
        for (int i = 0; i <= n; ++i) {
            pv[j][i] = pv[j - 1][pv[j - 1][i]];
            pt[j][i] = pt[j - 1][i] + pt[j - 1][pv[j - 1][i]];
            if (pt[j][i] > INF) pt[j][i] = INF;
        }
    for (int i = n + 1; i <= n + q; ++i) {
        if (qt[i] <= dist[i]) {
            if (qt[i] <= when[i]) {
                int64 ax = wx[i] + dx[wd[i]] * qt[i];
                int64 ay = wy[i] + dy[wd[i]] * qt[i];
                if (ax < 0) ax = 0;
                if (ay < 0) ay = 0;
                if (ax > b) ax = b;
                if (ay > b) ay = b;
                printf("%d %d\n", (int)ax, (int)ay);
                continue;
            }
            int64 ax = wx[i] + dx[wd[i]] * when[i];
            int64 ay = wy[i] + dy[wd[i]] * when[i];
            ax += dx[arrd[arr[i]]] * (qt[i] - when[i]);
            ay += dy[arrd[arr[i]]] * (qt[i] - when[i]);
            if (ax < 0) ax = 0;
            if (ay < 0) ay = 0;
            if (ax > b) ax = b;
            if (ay > b) ay = b;
            printf("%d %d\n", (int)ax, (int)ay);
            continue;
        }
        qt[i] -= dist[i];
        int where = arr[i];
        for (int j = 50; j >= 0; --j) {
            if (pt[j][where] <= qt[i]) {
                qt[i] -= pt[j][where];
                where = pv[j][where];
            }
        }
        if (arr[where] == 0 || qt[i] <= when[where] + 1) {
            int64 ax = xb[where] + dx[arrd[where]] * qt[i];
            int64 ay = yb[where] + dy[arrd[where]] * qt[i];
            if (ax < 0) ax = 0;
            if (ay < 0) ay = 0;
            if (ax > b) ax = b;
            if (ay > b) ay = b;
            printf("%d %d\n", (int)ax, (int)ay);
            continue;
        }
        int ax = xb[where] + dx[arrd[where]] * (when[where] + 1);
        int ay = yb[where] + dy[arrd[where]] * (when[where] + 1);
        ax += dx[arrd[arr[where]]] * (qt[i] - (when[where] + 1));
        ay += dy[arrd[arr[where]]] * (qt[i] - (when[where] + 1));
        printf("%d %d\n", ax, ay);
    }
    return 0;
}