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

#define BISHOP   'B'
#define ROCK   'R'
#define QUEEN 'Q'
#define KING   'K'

vector<pair<int, char> > row, col, addDiag, subDiag;

bool process(void) {
    int n, kx, ky; scanf("%d%d%d", &n, &kx, &ky);
    row.push_back(make_pair(ky, KING));
    col.push_back(make_pair(kx, KING));
    addDiag.push_back(make_pair(kx, KING));
    subDiag.push_back(make_pair(kx, KING));

    REP(love, n) {
        char s[5];
        int x, y;
        scanf("%s%d%d", s, &x, &y);
        if (x == kx) row.push_back(make_pair(y, s[0]));
        if (y == ky) col.push_back(make_pair(x, s[0]));
        if (x + y == kx + ky) addDiag.push_back(make_pair(x, s[0]));
        if (x - y == kx - ky) subDiag.push_back(make_pair(x, s[0]));
    }

    int id;
    sort(ALL(row));
    id = lower_bound(ALL(row), make_pair(ky, KING)) - row.begin();
    if (id - 1 >= 0 && row[id - 1].se != 'B') return true;
    if (id + 1 < row.size() && row[id + 1].se != 'B') return true;

    sort(ALL(col));
    id = lower_bound(ALL(col), make_pair(kx, KING)) - col.begin();
    if (id - 1 >= 0 && col[id - 1].se != 'B') return true;
    if (id + 1 < col.size() && col[id + 1].se != 'B') return true;

    sort(ALL(addDiag));
    id = lower_bound(ALL(addDiag), make_pair(kx, KING)) - addDiag.begin();
    if (id - 1 >= 0 && addDiag[id - 1].se != 'R') return true;
    if (id + 1 < addDiag.size() && addDiag[id + 1].se != 'R') return true;

    sort(ALL(subDiag));
    id = lower_bound(ALL(subDiag), make_pair(kx, KING)) - subDiag.begin();
    if (id - 1 >= 0 && subDiag[id - 1].se != 'R') return true;
    if (id + 1 < subDiag.size() && subDiag[id + 1].se != 'R') return true;

    return false;
}

int main(void) {
    cout << (process() ? "YES" : "NO") << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/