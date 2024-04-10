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

#define MAX   2002000
int next[MAX], rev[MAX], n;
bool vst[MAX];

void visitCircle(int s) {
    int u = s;
    while (true) {
        vst[u] = true;
        if (next[u] == s) return;
        u = next[u];
    }
}
void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &next[i]);
    FOR(i, 1, n) scanf("%d", &rev[i]);

    int numCyc = 0;
    FOR(i, 1, n) if (!vst[i]) {
        visitCircle(i);
        numCyc++;
    }

    int cntRev = 0;
    FOR(i, 1, n) if (rev[i]) cntRev++;

    printf("%d\n", (numCyc == 1 ? 0 : numCyc) + (cntRev % 2 == 0 ? 1 : 0));
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/