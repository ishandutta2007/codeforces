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

#define MAX   5050
const int MOD = (int)1e9 + 7;

char s[MAX];
int next[MAX][26];
int f[MAX][MAX], n;

void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}
void process(void) {
    scanf("%d", &n);
    scanf("%s", s + 1);

    REP(i, 26) next[n + 1][i] = n + 1;
    FORD(i, n, 0) {
        REP(j, 26) next[i][j] = next[i + 1][j];
        if (i > 0) next[i][s[i] - 'a'] = i;
    }

    f[0][0] = 1;
    REP(i, n) REP(j, n + 1) if (f[i][j] > 0) REP(k, 26) if (next[j][k] <= n)
        add(f[i + 1][next[j][k]], f[i][j]);

    int res = 0;
    FOR(j, 1, n) add(res, f[n][j]);
    printf("%d\n", res);
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/