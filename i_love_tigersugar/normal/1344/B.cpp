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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

const char BLACK = '#';
const char WHITE = '.';

void answer(int x) {
    cout << x << endl;
    exit(EXIT_SUCCESS);
}

#define MAX   1111
int numRow, numCol;
char board[MAX][MAX];
bool vst[MAX][MAX];

void init(void) {
    scanf("%d%d", &numRow, &numCol);
    FOR(i, 1, numRow) scanf("%s", board[i] + 1);
}

bool inside(int x, int y) {
    return 1 <= x && x <= numRow && 1 <= y && y <= numCol;
}

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    vst[sx][sy] = true;
    q.push({sx, sy});

    while (!q.empty()) {
        int ux = q.front().fi;
        int uy = q.front().se;
        q.pop();
        REP(i, 4) {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if (inside(vx, vy) && board[vx][vy] == BLACK && !vst[vx][vy]) {
                vst[vx][vy] = true;
                q.push({vx, vy});
            }
        }
    }
}

void process(void) {
    // no black cells -> zero
    bool allWhite = true;
    FOR(i, 1, numRow) FOR(j, 1, numCol) if (board[i][j] == BLACK) allWhite = false;
    if (allWhite) answer(0);

    // black cells do not form a consecutive segment in rows or columns -> -1
    int allWhiteRow = 0, allWhiteCol = 0;
    FOR(i, 1, numRow) {
        int low = numCol + 1, high = 0, cnt = 0;
        FOR(j, 1, numCol) if (board[i][j] == BLACK) {
            minimize(low, j);
            maximize(high, j);
            cnt++;
        }
        if (low <= high && high - low + 1 != cnt) answer(-1);
        if (cnt == 0) allWhiteRow++;
    }
    FOR(j, 1, numCol) {
        int low = numRow + 1, high = 0, cnt = 0;
        FOR(i, 1, numRow) if (board[i][j] == BLACK) {
            minimize(low, i);
            maximize(high, i);
            cnt++;
        }
        if (low <= high && high - low + 1 != cnt) answer(-1);
        if (cnt == 0) allWhiteCol++;
    }

    // one all-white column but no all-white rows -> -1
    if (allWhiteRow > 0 && allWhiteCol == 0) answer(-1);
    if (allWhiteCol > 0 && allWhiteRow == 0) answer(-1);

    // others, count the number of connected component
    int numComp = 0;
    FOR(i, 1, numRow) FOR(j, 1, numCol) if (board[i][j] == BLACK && !vst[i][j]) {
        numComp++;
        bfs(i, j);
    }
    answer(numComp);
}

int main(void) {
    init();
    process();
    return 1;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/