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

#define MAX_N   1010
#define MAX_LEN   55

int numQuest, maxLook, limit, length;
bool haveA[MAX_N], haveB[MAX_N];
short *f[MAX_N][MAX_LEN][MAX_LEN];

void init(void) {
    scanf("%d%d%d", &numQuest, &limit, &length);

    int t; scanf("%d", &t);
    REP(love, t) {
        int x; scanf("%d", &x); haveA[x] = true;
    }

    scanf("%d", &t);
    REP(love, t) {
        int x; scanf("%d", &x); haveB[x] = true;
    }
}

void optimize(void) {
    while (maxLook * length < numQuest) maxLook++;

    REP(i, numQuest + 1) REP(j, length) REP(k, length)
        f[i][j][k] = new short[2 * maxLook + 1];

    REP(pos, numQuest + 1) REP(fillA, length) REP(fillB, length) REP(used, 2 * maxLook + 1)
        f[pos][fillA][fillB][used] = -1;

    f[0][0][0][0] = 0;

    REP(pos, numQuest) REP(fillA, length) REP(fillB, length) REP(used, 2 * maxLook + 1)
        if (f[pos][fillA][fillB][used] >= 0) {
            int cur = f[pos][fillA][fillB][used];
            maximize(f[pos + 1][max(fillA - 1, 0)][max(fillB - 1, 0)][used], cur);

            if (haveA[pos + 1]) {
                int cost = pos + fillA >= pos + 1 ? 0 : 1;
                int newFillA = pos + fillA >= pos + 1 ? max(fillA - 1, 0) : length - 1;
                if (used + cost <= 2 * maxLook)
                    maximize(f[pos + 1][newFillA][max(fillB - 1, 0)][used + cost], cur + 1);
            }

            if (haveB[pos + 1]) {
                int cost = pos + fillB >= pos + 1 ? 0 : 1;
                int newFillB = pos + fillB >= pos + 1 ? max(fillB - 1, 0) : length - 1;
                if (used + cost <= 2 * maxLook)
                    maximize(f[pos + 1][max(fillA - 1, 0)][newFillB][used + cost], cur + 1);
            }
        }

//    REP(pos, numQuest + 1) REP(fillA, length) REP(fillB, length) REP(used, 2 * maxLook + 1)
//        if (f[pos][fillA][fillB][used] >= pos)
//            printf("F %d %d %d %d = %d\n", pos, fillA, fillB, used, f[pos][fillA][fillB][used]);

    int res = 0;
    REP(used, min(limit, 2 * maxLook) + 1) REP(fillA, length) REP(fillB, length)
        maximize(res, f[numQuest][fillA][fillB][used]);
    printf("%d\n", res);
}

int main(void) {
    init();
    optimize();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/