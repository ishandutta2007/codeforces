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

#define MAX   200200
const int INF = (int)1e9 + 7;
const char ch[] = "ab?";

int n, m;
char s[MAX];
int countMark[MAX], countChar[2][2][MAX];
int matchCost[MAX], maxMatch[MAX], minCost[MAX];

void init(void) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    scanf("%d", &m);
}

bool canMatch(int pos) {
    if (pos + m - 1 > n) return false;
    int L = pos, R = pos + m - 1;
    if (countChar[1][L % 2][R] > countChar[1][L % 2][L - 1]) return false;
    if (countChar[0][1 - L % 2][R] > countChar[0][1 - L % 2][L - 1]) return false;
    return true;
}

void process(void) {
    FOR(i, 1, n) {
        countMark[i] = countMark[i - 1];
        if (s[i] == '?') countMark[i]++;
        REP(j, 2) REP(k, 2) countChar[j][k][i] = countChar[j][k][i - 1];
        REP(j, 2) if (ch[j] == s[i]) countChar[j][i & 1][i]++;
    }

    FOR(i, 1, n) matchCost[i] = canMatch(i) ? countMark[i + m - 1] - countMark[i - 1] : INF;
    FORD(i, n, 1) {
        maxMatch[i] = maxMatch[i + 1];
        if (matchCost[i] < INF) maximize(maxMatch[i], maxMatch[i + m] + 1);
    }

    FORD(i, n, 1) {
        minCost[i] = INF;
        if (maxMatch[i] == 0) minCost[i] = 0;
        else {
            if (maxMatch[i] == maxMatch[i + 1]) minimize(minCost[i], minCost[i + 1]);
            if (maxMatch[i] == maxMatch[i + m] + 1) minimize(minCost[i], matchCost[i] + minCost[i + m]);
        }
    }
    printf("%d\n", minCost[1]);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/