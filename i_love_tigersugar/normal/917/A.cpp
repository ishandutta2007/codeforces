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

#define MAX   5050

char str[MAX];
int n;

int countStart(int l) {
    int res = 0, deg = 0, cntRem = 0;
    FOR(i, l, n) {
        if (str[i] == '(') {
            deg++;
        } else if (str[i] == ')') {
            deg--;
            if (deg < 0) {
                if (cntRem == 0) return res;
                cntRem--; deg += 2;
            }
        } else if (str[i] == '?') {
            if (deg > 0) {
                deg--; cntRem++;
            } else {
                deg++;
            }
        }
        if (deg == 0) res++;
    }
    return res;
}

int solve(string s) {
    n = s.size();
    FOR(i, 1, n) str[i] = s[i - 1];

    int res = 0;
    FOR(i, 1, n) res += countStart(i);
    return res;
}

int main(void) {
    string s; while (cin >> s) cout << solve(s) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/