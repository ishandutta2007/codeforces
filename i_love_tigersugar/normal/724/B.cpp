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

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   222
const string yes = "YES";
const string no = "NO";

int m, n;

bool sorted(const vector<int> &v) {
    REP(i, n - 1) if (v[i] > v[i + 1]) return false;
    return true;
}

bool checkRow(vector<int> v) {
    if (sorted(v)) return true;
    REP(i, n) FOR(j, i + 1, n - 1) {
        swap(v[i], v[j]);
        if (sorted(v)) return true;
        swap(v[i], v[j]);
    }
    return false;
}

bool okRow(vector<vector<int> > board) {
    FORE(it, board) if (!checkRow(*it)) return false;
    return true;
}

bool ok(vector<vector<int> > board) {
    if (okRow(board)) return true;
    REP(i, n) FOR(j, i + 1, n - 1) {
        REP(k, m) swap(board[k][i], board[k][j]);
        if (okRow(board)) return true;
        REP(k, m) swap(board[k][i], board[k][j]);
    }
    return false;
}

void process(void) {
    scanf("%d%d", &m, &n);
    vector<vector<int> > board(m, vector<int>(n, 0));
    REP(i, m) REP(j, n) scanf("%d", &board[i][j]);
    cout << (ok(board) ? yes : no) << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/