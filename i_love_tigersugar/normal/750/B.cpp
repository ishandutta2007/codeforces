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

const int length = 20000;
const string north = "North";
const string south = "South";
const string west = "West";
const string east = "East";

const string yes = "YES";
const string no = "NO";

bool solve(void) {
    int n; cin >> n;
    int cur = 0;
    REP(love, n) {
        int dis;
        string str;
        cin >> dis >> str;

        int next;
        if (str == west || str == east) next = cur;
        if (str == north) next = cur - dis;
        if (str == south) next = cur + dis;

        if (cur == 0 && str != south) return false;
        if (cur == length && str != north) return false;

        pair<int, int> range(cur, next);
        if (range.fi > range.se) swap(range.fi, range.se);

        if (range.fi < 0 && 0 < range.se && str != south) return false;
        if (range.fi < length && length < range.se && str != north) return false;

        cur = next;
    }

    return cur == 0;
}

int main(void) {
    cout << (solve() ? yes : no) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/