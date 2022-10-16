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

#define GREATER   ">"
#define EQUAL   "="
#define LESS   "<"
string ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    string ans; cin >> ans;
    return ans;
}

pair<int, int> sorted(int a, int b, int x, int y) {
    if (ask(x, y) == GREATER) swap(x, y);
    int idMin = ask(a, x) == GREATER ? x : a;
    int idMax = ask(b, y) == GREATER ? b : y;
    return make_pair(idMin, idMax);
}

void process(void) {
    int n; cin >> n;
    int idMax, idMin;
    if (n % 2 != 0) idMin = idMax = 1;
    else {
        if (ask(1, 2) == GREATER) {
            idMax = 1;
            idMin = 2;
        } else {
            idMax = 2;
            idMin = 1;
        }
    }
    for (int i = n % 2 == 0 ? 3 : 2; i <= n; i = i + 2) {
        pair<int, int> res = sorted(idMin, idMax, i, i + 1);
        idMin = res.fi;
        idMax = res.se;
     }
     cout << "! " << idMin << " " << idMax << endl;
}

int main(void) {
    int t; cin >> t;
    REP(love, t) process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/