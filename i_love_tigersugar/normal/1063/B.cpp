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

#define MAX   2020
#define OBSTACLE   '*'
const int INF = (int)1e9 + 7;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

int numRow, numCol, startRow, startCol, limLeft, limRight;
char board[MAX][MAX];
int minLeft[MAX][MAX];

void init(void) {
    scanf("%d%d", &numRow, &numCol);
    scanf("%d%d", &startRow, &startCol);
    scanf("%d%d", &limLeft, &limRight);
    FOR(i, 1, numRow) scanf("%s", board[i] + 1);
}

bool canGo(int x, int y) {
    if (x < 1 || x > numRow || y < 1 || y > numCol) return false;
    return board[x][y] != OBSTACLE;
}

void bfs(void) {
    deque<pair<int, int> > dq;
    memset(minLeft, 0x3f, sizeof minLeft);

    minLeft[startRow][startCol] = 0;
    dq.push_back(make_pair(startRow, startCol));

    while (!dq.empty()) {
        int row = dq.front().fi;
        int col = dq.front().se;
        dq.pop_front();

        REP(dir, 4) {
            int newRow = row + dx[dir];
            int newCol = col + dy[dir];
            if (!canGo(newRow, newCol)) continue;

            int cost = dir > 0 ? 0 : 1;
            if (minimize(minLeft[newRow][newCol], minLeft[row][col] + cost)) {
                if (cost > 0) dq.push_back(make_pair(newRow, newCol));
                else dq.push_front(make_pair(newRow, newCol));
            }
        }
    }
}

void process(void) {
    int res = 0;
    FOR(i, 1, numRow) FOR(j, 1, numCol) if (canGo(i, j) && minLeft[i][j] < INF) {
        int needLeft = minLeft[i][j];
        int needRight = max(minLeft[i][j] + j - startCol, 0);
        if (needLeft <= limLeft && needRight <= limRight) res++;
    }
    printf("%d\n", res);
}

int main(void) {
    init();
    bfs();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/