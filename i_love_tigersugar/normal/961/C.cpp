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
    void minimize(X &x, const Y &y) {
        if (x > y) x = y;
    }
template<class X, class Y>
    void maximize(X &x, const Y &y) {
        if (x < y) x = y;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   1111

char boards[4][MAX][MAX];
int n;

void init(void) {
    scanf("%d", &n);
    REP(k, 4) REP(i, n) scanf("%s", boards[k][i]);
}

int countDiff(const vector<int> &perm, char odd, char even) {
    int res = 0;
    REP(boardRow, 2) REP(boardCol, 2) {
        int curBoard = perm[boardRow * 2 + boardCol];
        REP(row, n) REP(col, n) {
            int i = boardRow * n + row;
            int j = boardCol * n + col;
            char exp = (i + j) % 2 ? odd : even;
            if (boards[curBoard][row][col] != exp) res++;
        }
    }
    return res;
}

void process(void) {
    int res = MAX * MAX;

    int arr[] = {0, 1, 2, 3};
    vector<int> ids(arr, arr + 4);
    do {
        minimize(res, countDiff(ids, '0', '1'));
        minimize(res, countDiff(ids, '1', '0'));
    } while (next_permutation(ALL(ids)));

    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/