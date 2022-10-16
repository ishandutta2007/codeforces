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

#define MAX (int)1e8 + 3

signed char cnt[MAX];

const int INF = (int)1e9;

int solve(int n) {
    if (n >= INF / 2) {
        if (n <= INF - 2) return (INF - 2) / 2 - (INF - 2 - n);
        if (n == INF - 1) return (INF - 2) / 2;
        if (n == INF) return (INF - 2) / 2 + 1;
    }

    if (n < 5) return n * (n - 1) / 2;

    int pw10 = INF, dig = 9;
    while (n < pw10 / 2) {
        pw10 /= 10; dig--;
    }

//    cerr << pw10 << " " << dig << endl;

    int div = n / pw10, mod = n % pw10;

//    cerr << div << " " << mod << endl;

    REP(i, pw10) cnt[i] = div + (i <= mod); cnt[0]--;
//    REP(i, pw10) cerr << (int)cnt[i] << " "; cerr << endl;

    int res = 0;
    int i = 0, j = pw10 - 1;
    while (i < j) {
        res += cnt[i] * cnt[j];
        i++; j--;
    }
    return res;
}

int main(void) {
    int n; while (cin >> n) cout << solve(n) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/