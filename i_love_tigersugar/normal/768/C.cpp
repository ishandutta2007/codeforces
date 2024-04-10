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

#define MAX   1111

int cnt[2][MAX];

int cntEven(int l, int r) {
    return l > r ? 0 : r / 2 - (l - 1) / 2;
}

void peform(int x, int cur, int next) {
    memset(cnt[next], 0, sizeof cnt[next]);

    int id = 1;
    REP(i, MAX) if (cnt[cur][i] > 0) {
        int numEven = cntEven(id, id + cnt[cur][i] - 1);
        int numOdd = cnt[cur][i] - numEven;
        cnt[next][i ^ x] += numOdd;
        cnt[next][i] += numEven;
        id += cnt[cur][i];
    }
}

void process(void) {
    int n, k, x; scanf("%d%d%d", &n, &k, &x);

    REP(love, n) {
        int x; scanf("%d", &x);
        cnt[0][x]++;
    }

    REP(love, k) peform(x, love % 2, (love % 2) ^ 1);

    FORD(i, MAX - 1, 0) if (cnt[k % 2][i] > 0) {
        printf("%d ", i);
        break;
    }
    REP(i, MAX) if (cnt[k % 2][i] > 0) {
        printf("%d\n", i);
        return;
    }
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/