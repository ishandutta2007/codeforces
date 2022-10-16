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

const int mod = (int)1e9 + 7;

#define MAX   111
#define MAX_VALUE   20
#define MAX_BIT   5

int f[2][MASK(MAX_VALUE) + 3][MAX_BIT + 3];
bool goodMask[MASK(MAX_VALUE) + 3];
char s[MAX];
int value[MAX][MAX], len;

void init(void) {
    scanf("%d", &len);
    scanf("%s", s + 1);
    FOR(i, 1, len) FOR(j, i, len) FOR(k, i, j) {
        value[i][j] = (value[i][j] << 1) | (s[k] == '1');
        minimize(value[i][j], MAX_VALUE + 1);
    }

    FOR(i, 1, MAX_VALUE) goodMask[MASK(i) - 1] = true;
}

void add(int &x, const int &y) {
    x += y;
    if (x >= mod) x -= mod;
}
void process(void) {
    int res = 0;

    REP(pos, len) {
        int cur = pos & 1;
        int next = cur ^ 1;

        add(f[cur][0][0], 1);

        REP(mask, MASK(MAX_VALUE)) REP(numBit, MAX_BIT + 1) {
            if (numBit > 0 && (pos - numBit + 1 < 1 || value[pos - numBit + 1][pos] > MAX_VALUE)) break;

            if (f[cur][mask][numBit] == 0) continue;

            //AddCut
            int newValue = numBit == 0 ? s[pos + 1] - '0' : value[pos - numBit + 1][pos + 1];
            if (1 <= newValue && newValue <= MAX_VALUE) {
                int newMask = mask | MASK(newValue - 1);
                if (goodMask[newMask]) add(res, f[cur][mask][numBit]);

                add(f[next][newMask][0], f[cur][mask][numBit]);
            }

            //AddNonCut
            if (newValue <= MAX_VALUE) {
                int newNumBit = newValue == 0 ? 0 : numBit + 1;
                add(f[next][mask][newNumBit], f[cur][mask][numBit]);
            }

            f[cur][mask][numBit] = 0;
        }
    }

    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

 /*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/