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

#define MAX   777
const long long INF = (long long)1e14 + 7LL;

int a[MAX], n, q;
long long minVal[MAX];

void init(void) {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
}

int calcNeed(long long start) {
    priority_queue<int, vector<int>, greater<int> > q;
    int res = 0;
    FOR(i, 1, n) {
        start += a[i];
        q.push(a[i]);
        while (start < 0) {
            assert(!q.empty());
            start -= q.top(); q.pop();
            res++;
        }
    }
    return res;
}
long long findMinVal(int need) {
    long long L = minVal[need + 1];
    long long R = INF;
    while (true) {
        if (L == R) return R;
        if (R - L == 1) return (calcNeed(L) <= need ? L : R);
        long long M = (L + R) >> 1;
        if (calcNeed(M) <= need) R = M; else L = M + 1;
    }
}
void prepare(void) {
    FORD(i, n - 1, 0) minVal[i] = findMinVal(i);
    reverse(minVal, minVal + n + 1);
}
void process(void) {
    REP(love, q) {
        long long tmp; cin >> tmp;
        int id = upper_bound(minVal, minVal + n + 1, tmp) - minVal - 1;
        printf("%d\n", n - id);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/