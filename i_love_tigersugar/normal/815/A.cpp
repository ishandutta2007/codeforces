#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   555
const int INF = (int)1e9 + 7;

int board[MAX][MAX], numRow, numCol, row[MAX], col[MAX];

void init(void) {
    scanf("%d%d", &numRow, &numCol);
    FOR(i, 1, numRow) FOR(j, 1, numCol) scanf("%d", &board[i][j]);
}

int test(int x, bool print) {
    row[1] = x, col[1] = board[1][1] - x;
    FOR(i, 2, numRow) row[i] = board[i][1] - col[1];
    FOR(i, 2, numCol) col[i] = board[1][i] - row[1];

    FOR(i, 1, numRow) if (row[i] < 0) return INF;
    FOR(i, 1, numCol) if (col[i] < 0) return INF;

    FOR(i, 1, numRow) FOR(j, 1, numCol) if (row[i] + col[j] != board[i][j]) return INF;

    int sum = 0;
    FOR(i, 1, numRow) sum += row[i];
    FOR(i, 1, numCol) sum += col[i];

    if (!print) return sum;

    printf("%d\n", sum);
    FOR(i, 1, numRow) REP(pmp, row[i]) printf("row %d\n", i);
    FOR(i, 1, numCol) REP(pmp, col[i]) printf("col %d\n", i);
    exit(EXIT_SUCCESS);
}

void process(void) {
    int res = INF;

    REP(i, board[1][1] + 1) minimize(res, test(i, false));
    if (res >= INF) printf("-1\n");

    REP(i, board[1][1] + 1) if (test(i, false) == res) test(i, true);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/