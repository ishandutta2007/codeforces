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
#define MAX   100100

int k, n, a, b;

void process(void) {
    cin >> n >> k >> a >> b;

    REP(x, MAX) if (0 <= x && x <= a && a <= 1LL * k * x)
        FOR(y, x - 1, x + 1) if (0 <= y && y <= b && b <= 1LL * k * y) {
            vector<int> segX, segY;
            REP(i, x) segX.push_back(a / x + (i < a % x));
            REP(i, y) segY.push_back(b / y + (i < b % y));

            int cntX = 0, cntY = 0;
            bool mode = x >= y;
            REP(love, x + y) {
                if (mode) {
                    REP(love, segX[cntX]) printf("G");
                    cntX++;
                } else {
                    REP(love, segY[cntY]) printf("B");
                    cntY++;
                }
                mode ^= 1;
            }
            printf("\n");
            return;
        }
    cout << "NO" << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/