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
#define MAX   111

int nextFree[MAX];
int n, q;

void process(void) {
    scanf("%d%d", &n, &q);
    REP(love, q) {
        int start, need, dur; scanf("%d%d%d", &start, &need, &dur);
        vector<int> isFree;
        FOR(i, 1, n) if (nextFree[i] <= start && isFree.size() < need)
            isFree.push_back(i);
        if (isFree.size() < need) {
            printf("-1\n");
            continue;
        }
        int sum = 0;
        FORE(it, isFree) {
            sum += *it;
            nextFree[*it] = start + dur;
        }
        printf("%d\n", sum);
    }
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/