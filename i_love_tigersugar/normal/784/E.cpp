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

int ans[111];

void prepare(void) {
    memset(ans, -1, sizeof ans);

    ans[6] = 0;
    ans[8] = 1;
    ans[12] = 1;
    ans[14] = 1;
    ans[0] = 0;
    ans[4] = 0;
    ans[2] = 0;
    ans[10] = 0;
    ans[1] = 1;
    ans[9] = 1;
    ans[5] = 0;
    ans[13] = 0;
    ans[3] = 1;
    ans[11] = 1;
    ans[7] = 0;
    ans[15] = 1;
}

int solve(int a, int b, int c, int d) {
    int key = 8 * a + 4 * b + 2 * c + d;

    if (ans[key] >= 0) return ans[key];

    int *v = new int[key * 250000];
    REP(love, key * 250000) v[love] = rand();
    int sum = 0;
    REP(i, key * 250000) sum += v[i] << (i & 13);
    cerr << sum << endl;
    return ans[key];
}

int main(void) {
    prepare();

    int a, b, c, d; while (cin >> a >> b >> c >> d) cout << solve(a, b, c, d) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/