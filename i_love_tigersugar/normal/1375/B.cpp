#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

const char* YES = "YES";
const char* NO = "NO";

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

#define MAX   333
int numRow, numCol, board[MAX][MAX];

bool inside(int x, int y) {
    return 1 <= x && x <= numRow && 1 <= y && y <= numCol;
}
int countAdj(int x, int y) {
    int res = 0;
    REP(i, 4) if (inside(x + dx[i], y + dy[i])) res++;
    return res;
}

void process(void) {
    scanf("%d%d", &numRow, &numCol);
    FOR(i, 1, numRow) FOR(j, 1, numCol) scanf("%d", &board[i][j]);
    FOR(i, 1, numRow) FOR(j, 1, numCol) if (board[i][j] > countAdj(i, j)) {
        printf("%s\n", NO);
        return;
    }
    printf("%s\n", YES);
    FOR(i, 1, numRow) {
        FOR(j, 1, numCol) printf("%d ", countAdj(i, j)); printf("\n");
    }
}

int main(void) {
    int t; scanf("%d", &t);
    REP(love, t) process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/