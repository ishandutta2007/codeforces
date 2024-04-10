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

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   2020
const int MOD = (int)1e9 + 7;

int numRow, numCol;
char board[MAX][MAX];
int range[MAX][MAX][2], limit[MAX][MAX][2];
int numWay[MAX][MAX][2], sumRow[MAX][MAX][2], sumCol[MAX][MAX][2];

void init(void) {
    scanf("%d%d", &numRow, &numCol);
    FOR(i, 1, numRow) scanf("%s", board[i] + 1);
    if (board[1][1] == 'R' || board[numRow][numCol] == 'R') {
        cout << 0 << endl;
        exit(EXIT_SUCCESS);
    }
    if (numRow == 1 && numCol == 1) {
        cout << 1 << endl;
        exit(EXIT_SUCCESS);
    }
}

void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}
int sum(int x, int y) {
    return x + y >= MOD ? x + y - MOD : x + y;
}
int diff(int x, int y) {
    return x < y ? x - y + MOD : x - y;
}

#define DOWN   0
#define RIGHT  1

void optimize(void) {
    FOR(i, 1, numRow) {
        int cntRock = 0;
        FORD(j, numCol, 1) {
            range[i][j][RIGHT] = numCol - cntRock;
            if (board[i][j] == 'R') cntRock++;
        }
        int k = numCol;
        FORD(j, numCol, 1) {
            while (k >= 1 && range[i][k][RIGHT] >= j) k--; k++;
            limit[i][j][RIGHT] = k;
        }
    }
    FOR(j, 1, numCol) {
        int cntRock = 0;
        FORD(i, numRow, 1) {
            range[i][j][DOWN] = numRow - cntRock;
            if (board[i][j] == 'R') cntRock++;
        }
        int k = numRow;
        FORD(i, numRow, 1) {
            while (k >= 1 && range[k][j][DOWN] >= i) k--; k++;
            limit[i][j][DOWN] = k;
        }
    }

    FOR(i, 2, numRow) {
        if (i <= range[1][1][DOWN]) numWay[i][1][DOWN] = 1;
        sumCol[i][1][DOWN] = sum(sumCol[i - 1][1][DOWN], numWay[i][1][DOWN]);
        sumRow[i][1][DOWN] = numWay[i][1][DOWN];
    }
    FOR(j, 2, numCol) {
        if (j <= range[1][1][RIGHT]) numWay[1][j][RIGHT] = 1;
        sumRow[1][j][RIGHT] = sum(sumRow[1][j - 1][RIGHT], numWay[1][j][RIGHT]);
        sumCol[1][j][RIGHT] = numWay[1][j][RIGHT];
    }

    FOR(i, 2, numRow) FOR(j, 2, numCol) {
        int k = limit[i][j][RIGHT];
//        printf("Limit (%d, %d, RIGHT) = %d\n", i, j, k);
        numWay[i][j][RIGHT] = diff(sumRow[i][j - 1][DOWN], sumRow[i][k - 1][DOWN]);

        k = limit[i][j][DOWN];
//        printf("Limit (%d, %d, DOWN) = %d\n", i, j, k);
        numWay[i][j][DOWN] = diff(sumCol[i - 1][j][RIGHT], sumCol[k - 1][j][RIGHT]);

        REP(k, 2) {
            sumRow[i][j][k] = sum(sumRow[i][j - 1][k], numWay[i][j][k]);
            sumCol[i][j][k] = sum(sumCol[i - 1][j][k], numWay[i][j][k]);
        }
    }

//    FOR(i, 1, numRow) FOR(j, 1, numCol) {
//        if (numWay[i][j][RIGHT] > 0) printf("(%d, %d, RIGHT) = %d\n", i, j, numWay[i][j][RIGHT]);
//        if (numWay[i][j][DOWN] > 0) printf("(%d, %d, DOWN) = %d\n", i, j, numWay[i][j][DOWN]);
//    }

    printf("%d\n", sum(numWay[numRow][numCol][RIGHT], numWay[numRow][numCol][DOWN]));
}

int main(void) {
    init();
    optimize();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/