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

#define MAX   111
const int INF = (int)1e9 + 7;

char digits[MAX];
int numPart[MAX];
int len, base;

int value(int l, int r) {
    string s;
    FOR(i, l, r) s.push_back(digits[i]);

    if (s == "0") return 0;
    if (s[0] == '0') return INF;

    long long res = 0;
    FORE(it, s) {
        res = 10 * res + *it - '0';
        minimize(res, INF);
    }
    return res;
}

void process(void) {
    scanf("%d", &base);
    scanf("%s", digits + 1);
    len = strlen(digits + 1);

    if (len == 1 && digits[1] == '0') {
        printf("0\n");
        return;
    }

    memset(numPart, 0x3f, sizeof numPart);
    numPart[len + 1] = 0;
    FORD(i, len, 1) FOR(j, i, len) if (value(i, j) < base)
        minimize(numPart[i], numPart[j + 1] + 1);

    long long res = 0;

    int j = 1;
    FOR(i, 1, numPart[1]) {
        FOR(k, j, len) if (value(j, k) < base && numPart[k + 1] == numPart[1] - i) {
            res = res * base + value(j, k);
            j = k + 1;
            break;
        }
    }

    cout << res << endl;
}

int main(void) {
    process();
    return 0;
}


/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/