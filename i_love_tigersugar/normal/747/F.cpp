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
#define MAX   175

const int base = 16;
const long long INF = (long long)1e18 + 7LL;

long long comb[MAX][MAX];
long long f[MAX][MAX];
int cnt[MAX], lim;
long long pos;

void prepare(void) {
    REP(i, MAX) comb[0][i] = 1;
    FOR(i, 1, MAX - 1) FOR(j, 1, MAX - 1) {
        if (i == j) comb[i][j] = 1;
        if (i < j) {
            comb[i][j] = comb[i][j - 1] + comb[i - 1][j - 1];
            minimize(comb[i][j], INF);
        }
    }
}

char getDigit(int x) {
    return x < 10 ? x + '0' : x - 10 + 'a';
}
long long product(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return INF / a <= b ? INF : a * b;
}
long long cntWay(int length) {
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    REP(i, base) REP(j, length + 1) if (f[i][j] > 0) REP(k, cnt[i] + 1) if (j + k <= length) {
        f[i + 1][j + k] += product(f[i][j], comb[k][j + k]);
        minimize(f[i + 1][j + k], INF);
    }

    return f[base][length];
}

long long cntWayDigit(int dig) {
    long long res = 0;
    FOR(i, 1, base - 1) if (cnt[i] > 0) {
        cnt[i]--;
        res += cntWay(dig - 1);
        cnt[i]++;
    }
    return res;
}

void process(long long p, int l) {
    pos = p; lim = l;
    REP(i, base) cnt[i] = lim;

    int numDigit = 1;
    while (true) {
        long long tmp = cntWayDigit(numDigit);
        if (pos > tmp) {
            pos -= tmp;
            numDigit++;
        } else break;
    }

    string digits;
    REP(love, numDigit) {
        FOR(i, love == 0 ? 1 : 0, base - 1) if (cnt[i] > 0) {
            cnt[i]--;
            long long tmp = cntWay(numDigit - love - 1);
            if (tmp >= pos) {
                digits.push_back(getDigit(i));
                break;
            } else {
                pos -= tmp;
                cnt[i]++;
            }
        }
    }

    cout << digits << endl;
}

int main(void) {
    prepare();
    long long pos;
    int lim;
    cin >> pos >> lim;
    process(pos, lim);
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/