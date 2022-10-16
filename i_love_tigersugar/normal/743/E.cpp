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

#define MAX   1024
#define VAL   8

#define MASK_FOUR(i) MASK(2 * (i))
#define BIT_FOUR(x, i) (((x) >> (2 * (i))) & 3)

int a[MAX], next[MAX][VAL + 3][MAX], nextPos[MAX][VAL + 3], n;
int f[MASK_FOUR(VAL) + 3];
bool valid[MASK_FOUR(VAL) + 3];

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) a[i]--;
}

void prepare(void) {
    REP(i, VAL) nextPos[n][i] = n + 1;
    FORD(i, n - 1, 0) {
        REP(j, VAL) nextPos[i][j] = nextPos[i + 1][j];
        nextPos[i][a[i + 1]] = i + 1;
    }

    REP(j, VAL) REP(k, MAX) next[n][j][k] = n + 1;
    FORD(i, n - 1, 0) REP(j, VAL) {
        next[i][j][1] = nextPos[i][j];
        FOR(k, 2, MAX - 1) next[i][j][k] = nextPos[i][j] <= n ? next[nextPos[i][j]][j][k - 1] : n + 1;
    }

    REP(i, MASK_FOUR(VAL)) {
        valid[i] = true;
        REP(j, VAL) if (BIT_FOUR(i, j) == 3) valid[i] = false;
    }
}

int maxSeq(int length) {
    memset(f, 0x3f, sizeof f);

    int res = -1;

    f[0] = 0;
    REP(i, MASK_FOUR(VAL)) if (valid[i] && f[i] <= n) {
        bool done = true;
        int value = 0;

        REP(j, VAL) {
            if (BIT_FOUR(i, j) == 2) value++;
            if (BIT_FOUR(i, j) == 0) {
                done = false;

                REP(k, 2) {
                    int tmp = length + k == 0 ? f[i] : next[f[i]][j][length + k];
                    minimize(f[i | ((k + 1) << (2 * j))], tmp);
                }
            }
        }

        if (done) maximize(res, VAL * length + value);
    }
    return res;
}

void process(void) {
    int res = -1;
    REP(i, n / 8 + 1) maximize(res, maxSeq(i));
    printf("%d\n", res);
}

int main(void) {
    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/