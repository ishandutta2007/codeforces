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

bool solve(int x1, int y1, int x2, int y2, int dx, int dy) {
    if ((x1 - x2) % dx != 0) return false;
    if ((y1 - y2) % dy != 0) return false;

    int nx = Abs(x1 - x2) / dx;
    int ny = Abs(y1 - y2) / dy;

    return (nx - ny) % 2 == 0;
}

int main(void) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int x, y; cin >> x >> y;
    cout << (solve(x1, y1, x2, y2, x, y) ? "YES" : "NO") << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/