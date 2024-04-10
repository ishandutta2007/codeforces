#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   111

const int dx[] = {0, 1};
const int dy[] = {1, 0};

int n, l;
char board[MAX][MAX];
int cnt[MAX][MAX];

bool inside(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

void process(void) {
    scanf("%d%d", &n, &l);
    FOR(i, 1, n) scanf("%s", board[i] + 1);

    FOR(i, 1, n) FOR(j, 1, n) REP(d, 2) {
        bool ok = true;
        REP(k, l) {
            int x = i + k * dx[d];
            int y = j + k * dy[d];
            if (!inside(x, y) || board[x][y] != '.') ok = false;
        }
        if (ok) {
            REP(k, l) {
                int x = i + k * dx[d];
                int y = j + k * dy[d];
                cnt[x][y]++;
            }
        }
    }

    int best = 0;
    FOR(i, 1, n) FOR(j, 1, n) maximize(best, cnt[i][j]);
    FOR(i, 1, n) FOR(j, 1, n) if (best == cnt[i][j]) {
        printf("%d %d\n", i, j);
        return;
    }
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/