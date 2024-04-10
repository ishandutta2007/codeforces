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

#define MAX   55
const long long INF = (long long)1e18 + 7LL;

long long value[MAX], diff[MAX];
int n;

long long getDiff(int pos) {
    if (diff[pos] < INF) return diff[pos];
    if (pos > n) return 0;
    long long keepTurn = getDiff(pos + 1) - value[pos];
    long long leaveTurn = value[pos] - getDiff(pos + 1);
    return max(keepTurn, leaveTurn);
}

void process(void) {
    cin >> n;
    FOR(i, 1, n) cin >> value[i];
    memset(diff, 0x3f, sizeof diff);
    long long sum = 0;
    FOR(i, 1, n) sum += value[i];
    cout << (sum - getDiff(1)) / 2 << " ";
    cout << (sum + getDiff(1)) / 2 << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/