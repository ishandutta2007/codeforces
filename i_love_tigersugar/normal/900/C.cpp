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

int perm[MAX], n, score[MAX];
bool isRecord[MAX];

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &perm[i]);

    set<int> s;
    FOR(i, 1, n) {
        if (s.empty() || perm[i] > *s.rbegin()) {
            isRecord[perm[i]] = true;
        } else if (s.size() == 1) {
            score[*s.rbegin()]++;
        } else {
            __typeof(s.begin()) it = s.end(); it--; it--;
            if (perm[i] > *it) score[*s.rbegin()]++;
        }
        s.insert(perm[i]);
    }

    int bestScore = -MAX;
    int bestPos = 1;
    FOR(i, 1, n) {
        int tmpScore = score[i];
        if (isRecord[i]) tmpScore--;
        if (tmpScore > bestScore) {
            bestScore = tmpScore;
            bestPos = i;
        } else if (tmpScore == bestScore) minimize(bestPos, i);
    }
    printf("%d\n", bestPos);
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/