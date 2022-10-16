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

#define MAX   100100

const int SINGLE = 20;
const pair<int, int> tickets[2] = {make_pair(90, 50), make_pair(1440, 120)};

int t[MAX], f[MAX], n;

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &t[i]);

    FOR(i, 1, n) {
        f[i] = f[i - 1] + SINGLE;
        REP(j, 2) {
            int dur = tickets[j].fi;
            int cost = tickets[j].se;

            int k = lower_bound(t + 1, t + i + 1, t[i] - dur + 1) - t;
            minimize(f[i], f[k - 1] + cost);
        }
    }

    FOR(i, 1, n) printf("%d\n", f[i] - f[i - 1]);
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/