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
#define NC   26

int prev[MAX][NC], next[MAX][NC];
int matchLeft[MAX], matchRight[MAX];
char toMatch[MAX], toErase[MAX];
int lenMatch, lenErase;

void init(void) {
    scanf("%s", toMatch + 1);
    lenMatch = strlen(toMatch + 1);
    scanf("%s", toErase + 1);
    lenErase = strlen(toErase + 1);
}

void prepare(void) {
    REP(i, NC) next[lenMatch][i] = lenMatch + 1;
    FORD(i, lenMatch - 1, 0) {
        REP(j, NC) next[i][j] = next[i + 1][j];
        next[i][toMatch[i + 1] - 'a'] = i + 1;
    }

    REP(i, NC) prev[1][i] = 0;
    FOR(i, 2, lenMatch + 1) {
        REP(j, NC) prev[i][j] = prev[i - 1][j];
        prev[i][toMatch[i - 1] - 'a'] = i - 1;
    }

    FOR(i, 1, lenErase)
        matchLeft[i] = matchLeft[i - 1] <= lenMatch ? next[matchLeft[i - 1]][toErase[i] - 'a'] : lenMatch + 1;

    matchRight[lenErase + 1] = lenMatch + 1;
    FORD(i, lenErase, 1)
        matchRight[i] = matchRight[i + 1] >= 1 ? prev[matchRight[i + 1]][toErase[i] - 'a'] : 0;
}

bool canErase(int l, int r) {
    return l <= r && matchLeft[l - 1] <= lenMatch && matchRight[r + 1] >= 1 && matchLeft[l - 1] < matchRight[r + 1];
}

int findBest(int l) {
    if (matchLeft[l - 1] > lenMatch) return -1;

    int L = l;
    int R = lenErase;

    while (true) {
        if (L == R) return R;
        if (R - L == 1) return canErase(l, L) ? L : R;

        int M = (L + R) >> 1;
        if (canErase(l, M)) R = M; else L = M + 1;
    }
}

void process(void) {
    if (matchLeft[lenErase] <= lenMatch) {
        printf("%s\n", toErase + 1);
        return;
    }

    pair<int, int> best(1, lenErase);

    FOR(i, 1, lenErase) {
        int j = findBest(i);
        if (j >= i && best.se - best.fi + 1 > j - i + 1) best = make_pair(i, j);
    }

    if (best.fi == 1 && best.se == lenErase) printf("-");
    else {
        FOR(i, 1, best.fi - 1) printf("%c", toErase[i]);
        FOR(i, best.se + 1, lenErase) printf("%c", toErase[i]);
    }

    printf("\n");
}

int main(void) {
    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/