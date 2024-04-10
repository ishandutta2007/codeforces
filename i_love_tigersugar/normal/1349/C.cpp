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

#define MAX   1111
int numRow, numCol, numQuery;
char board[MAX][MAX];
int dist[MAX][MAX];

void init(void) {
    scanf("%d%d%d", &numRow, &numCol, &numQuery);
    FOR(i, 1, numRow) scanf("%s", board[i] + 1);
}

bool inside(int x, int y) {
    return 1 <= x && x <= numRow && 1 <= y && y <= numCol;
}

bool haveSame(int x, int y) {
    REP(i, 4) {
        int vx = x + dx[i], vy = y + dy[i];
        if (inside(vx, vy) && board[x][y] == board[vx][vy]) return true;
    }
    return false;
}

void bfs(void) {
    memset(dist, -1, sizeof dist);
    queue<pair<int, int>> q;
    FOR(i, 1, numRow) FOR(j, 1, numCol) if (haveSame(i, j)) {
        dist[i][j] = 0;
        q.push({i, j});
    }

    while (!q.empty()) {
        int ux = q.front().fi;
        int uy = q.front().se;
        q.pop();
        REP(i, 4) {
            int vx = ux + dx[i], vy = uy + dy[i];
            if (inside(vx, vy) && dist[vx][vy] < 0) {
                dist[vx][vy] = dist[ux][uy] + 1;
                q.push({vx, vy});
            }
        }
    }
}

char answer(int x, int y, long long p) {
    if (dist[x][y] < 0) return board[x][y];
    if (dist[x][y] >= p) return board[x][y];
    return (p - dist[x][y]) % 2 ? board[x][y] ^ '0' ^ '1' : board[x][y];
}

void process(void) {
    bfs();
    REP(love, numQuery) {
        int x, y;
        long long p;
        cin >> x >> y >> p;
        printf("%c\n", answer(x, y, p));
    }
}

int main(void) {
    init();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/