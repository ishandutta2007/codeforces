#include <bits/stdc++.h>

using namespace std;

const int CLOSE = -1;
const int OPEN = 1;

struct tsob {
    int x, t;
    tsob(int x, int t) : x(x), t(t) {}
    tsob() {}
};

inline bool operator<(const tsob &a, const tsob &b) { return a.x < b.x; }

struct tt {
    int lvl, x1, x2;
    tt(int lvl, int x1, int x2) : lvl(lvl), x1(x1), x2(x2) {}
    tt() {}
};

inline bool operator<(const tt &a, const tt &b) { return a.lvl < b.lvl; }

const int N = 100005;

int n, m, k;
int rx[N], ry[N], lenx[N], leny[N];

vector<tt> xs, ys;
vector<tsob> sobx[N], soby[N];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if (x1 == x2) {
            ys.push_back(tt(x1, y1, y2));
        } else {
            xs.push_back(tt(y1, x1, x2));
        }
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    int kx = 0;
    for (int i = 0; i < (int)xs.size(); ++i) {
        if (i == 0 || xs[i].lvl != xs[i - 1].lvl) {
            sobx[kx].resize(0);
            sobx[kx].push_back(tsob(xs[i].x1, OPEN));
            sobx[kx].push_back(tsob(xs[i].x2, CLOSE));
            ry[kx] = xs[i].lvl;
            kx++;
        } else {
            sobx[kx - 1].push_back(tsob(xs[i].x1, OPEN));
            sobx[kx - 1].push_back(tsob(xs[i].x2, CLOSE));
        }
    }
    int ky = 0;
    for (int i = 0; i < (int)ys.size(); ++i) {
        if (i == 0 || ys[i].lvl != ys[i - 1].lvl) {
            soby[ky].resize(0);
            soby[ky].push_back(tsob(ys[i].x1, OPEN));
            soby[ky].push_back(tsob(ys[i].x2, CLOSE));
            rx[ky] = ys[i].lvl;
            ky++;
        } else {
            soby[ky - 1].push_back(tsob(ys[i].x1, OPEN));
            soby[ky - 1].push_back(tsob(ys[i].x2, CLOSE));
        }
    }
    int answer = 0;
    if ((m - 1 - kx) % 2 == 1) answer ^= n;
    if ((n - 1 - ky) % 2 == 1) answer ^= m;
    for (int i = 0; i < kx; ++i) {
        sort(sobx[i].begin(), sobx[i].end());
        int curk = 0;
        int lastx = 0;
        lenx[i] = 0;
        for (int j = 0; j < (int)sobx[i].size(); ++j) {
            if (curk == 0) lenx[i] += sobx[i][j].x - lastx;
            curk += sobx[i][j].t;
            lastx = sobx[i][j].x;
        }
        lenx[i] += n - lastx;
        answer ^= lenx[i];
    }
    for (int i = 0; i < ky; ++i) {
        sort(soby[i].begin(), soby[i].end());
        int curk = 0;
        int lastx = 0;
        leny[i] = 0;
        for (int j = 0; j < (int)soby[i].size(); ++j) {
            if (curk == 0) leny[i] += soby[i][j].x - lastx;
            curk += soby[i][j].t;
            lastx = soby[i][j].x;
        }
        leny[i] += m - lastx;
        answer ^= leny[i];
    }
    if (answer == 0) {
        printf("SECOND\n");
        return 0;
    }
    printf("FIRST\n");
    for (int i = 0; i < kx; ++i) {
        int need = (answer ^ lenx[i]);
        if (need <= lenx[i]) {
            need = lenx[i] - need;
            int curk = 0;
            int lastx = 0;
            int curlen = 0;
            for (int j = 0; j < (int)sobx[i].size(); ++j) {
                if (curk == 0) curlen += sobx[i][j].x - lastx;
                if (curlen >= need) {
                    printf("%d %d %d %d\n", 0, ry[i],
                           sobx[i][j].x - (curlen - need), ry[i]);
                    return 0;
                }
                curk += sobx[i][j].t;
                lastx = sobx[i][j].x;
            }
            curlen += n - lastx;
            printf("%d %d %d %d\n", 0, ry[i], n - (curlen - need), ry[i]);
            return 0;
        }
    }
    for (int i = 0; i < ky; ++i) {
        int need = (answer ^ leny[i]);
        if (need <= leny[i]) {
            need = leny[i] - need;
            int curk = 0;
            int lastx = 0;
            int curlen = 0;
            for (int j = 0; j < (int)soby[i].size(); ++j) {
                if (curk == 0) curlen += soby[i][j].x - lastx;
                if (curlen >= need) {
                    printf("%d %d %d %d\n", rx[i], 0, rx[i],
                           soby[i][j].x - (curlen - need));
                    return 0;
                }
                curk += soby[i][j].t;
                lastx = soby[i][j].x;
            }
            curlen += m - lastx;
            printf("%d %d %d %d\n", rx[i], 0, rx[i], m - (curlen - need));
            return 0;
        }
    }
    int emptyx = -1;
    if (n > 1 && ky == 0) emptyx = 1;
    if (ky > 0 && rx[0] != 1) emptyx = 1;
    for (int i = 0; i < ky; ++i)
        if (rx[i] + 1 != rx[i + 1] && rx[i] + 1 != n) emptyx = rx[i] + 1;
    int need = (answer ^ m);
    if (need <= m && emptyx != -1) {
        printf("%d %d %d %d\n", emptyx, 0, emptyx, m - need);
        return 0;
    }
    int emptyy = -1;
    if (m > 1 && kx == 0) emptyy = 1;
    if (kx > 0 && ry[0] != 1) emptyy = 1;
    for (int i = 0; i < kx; ++i)
        if (ry[i] + 1 != ry[i + 1] && ry[i] + 1 != m) emptyy = ry[i] + 1;
    need = (answer ^ n);
    if (need <= n && emptyy != -1) {
        printf("%d %d %d %d\n", 0, emptyy, n - need, emptyy);
        return 0;
    }
    assert(false);
    return 0;
}