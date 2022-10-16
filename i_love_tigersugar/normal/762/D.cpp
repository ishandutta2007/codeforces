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
const long long INF = (long long)1e18 + 7LL;

const int numRow = 3;

int numCol, a[numRow + 2][MAX];
long long f[MAX][MASK(numRow) + 7];

void init(void) {
    scanf("%d", &numCol);
    REP(i, numRow) FOR(j, 1, numCol) scanf("%d", &a[i][j]);
}

void optimize(void) {
    memset(f, -0x3f, sizeof f);

    f[0][0] = 0;
    REP(col, numCol) REP(mask, MASK(numRow)) if (f[col][mask] > -INF)
        REP(chs, MASK(numRow)) {
            if (col + 1 == 1 && !BIT(chs, 0)) continue;
            if (col + 1 == numCol && !BIT(chs, numRow - 1)) continue;

            long long newValue = 0;
            REP(i, numRow) if (BIT(chs, i)) newValue += a[i][col + 1];

            REP(colEdge, MASK(numRow - 1)) {
                int deg[numRow]; memset(deg, 0, sizeof deg);
                int needDeg[numRow];

                REP(i, numRow) needDeg[i] = BIT(chs, i) ? 2 : 0;
                if (col + 1 == 1) needDeg[0] = 1;
                if (col + 1 == numCol) needDeg[numRow - 1] = 1;

                REP(i, numRow) if (BIT(mask, i)) deg[i]++;
                REP(i, numRow - 1) if (BIT(colEdge, i)) {
                    deg[i]++; deg[i + 1]++;
                }

                bool ok = true;
                REP(i, numRow) if (deg[i] != needDeg[i] && deg[i] != needDeg[i] - 1) ok = false;

                if (!ok) continue;
                int newMask = 0;
                REP(i, numRow) if (deg[i] < needDeg[i]) newMask |= MASK(i);

                maximize(f[col + 1][newMask], f[col][mask] + newValue);
            }
        }

    cout << f[numCol][0] << endl;
}

int main(void) {
    init();
    optimize();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/