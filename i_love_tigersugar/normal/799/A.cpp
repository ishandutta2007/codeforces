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

const long long INF = (long long)1e15 + 7LL;

long long getTime(int n, int t, int k, int d) {
    long long L = d;
    long long R = INF;

    while (true) {
        if (L == R) return R;
        if (R - L == 1) return ((L / t + (L - d) / t) * k >= n) ? L : R;
        long long M = (L + R) >> 1;
        if ((M / t + (M - d) / t) * k >= n) R = M; else L = M + 1;
    }
}

bool solve(int n, int t, int k, int d) {
    long long first = 1LL * (n / k + (n % k > 0)) * t;
    long long second = getTime(n, t, k, d);

    return first > second;
}

int main(void) {
    int n, t, k, d;
    while (cin >> n >> t >> k >> d) cout << (solve(n, t, k, d) ? "YES" : "NO") << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/