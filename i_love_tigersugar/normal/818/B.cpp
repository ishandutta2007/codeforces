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
int n, m, perm[MAX], res[MAX];

void process(void) {
    if (scanf("%d%d", &n, &m) != 2) exit(0);
    REP(i, m) scanf("%d", &res[i]);
    REP(i, m) res[i];

    memset(perm, -1, sizeof perm);

    REP(i, m - 1) {
        int value = res[i + 1] - res[i];
        if (value < 1) value += n;

        if (perm[res[i]] >= 0 && perm[res[i]] != value) {
            printf("-1\n");
            return;
        }
        perm[res[i]] = value;
    }

    set<int> rem;
    FOR(i, 1, n) rem.insert(i);
    FOR(i, 1, n) if (perm[i] >= 0) {
        if (!rem.erase(perm[i])) {
            printf("-1\n");
            return;
        }
    }

    FOR(i, 1, n) if (perm[i] < 0) {
        perm[i] = *rem.begin();
        rem.erase(rem.begin());
    }

    FOR(i, 1, n) printf("%d ", perm[i]); printf("\n");
}

int main(void) {
    while (true) process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/