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

#define MAX   1111

int next[MAX], cycle[MAX], n;

long long gcd(long long a, long long b) {
    while (true) {
        if (a == 0) return b;
        if (b == 0) return a;
        if (a > b) a %= b; else b %= a;
    }
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int getCycle(int s) {
    int res = 0;
    int u = s;
    REP(love, MAX) {
        res++;
        u = next[u];
        if (u == s) return res;
    }
    return -1;
}

void process(void) {
    cin >> n;
    FOR(i, 1, n) cin >> next[i];

    FOR(i, 1, n) cycle[i] = getCycle(i);
    FOR(i, 1, n) if (cycle[i] < 0) {
        printf("-1\n");
        return;
    }

    long long res = 2;
    FOR(i, 1, n) res = lcm(res, cycle[i]);
    cout << res / 2 << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/