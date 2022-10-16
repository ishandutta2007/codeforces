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

#define MAX   1000100
int n, value, color[MAX], cnt[MAX];

void init(void) {
    if (scanf("%d%d", &n, &value) != 2) exit(EXIT_SUCCESS);
    FOR(i, 1, n) scanf("%d", &color[i]);
    memset(cnt, 0, sizeof cnt);
}

void process(void) {
    set<pair<int, int> > s;
    FOR(i, 1, MAX - 1) s.insert(make_pair(cnt[i], i));

    FOR(i, 1, n) {
        int c = color[i];
        cnt[c]++;
        if (!s.erase(make_pair(cnt[c] - 1, c))) continue;
        s.insert(make_pair(cnt[c], c)).se;

        while (!s.empty() && s.begin()->fi < cnt[value]) s.erase(s.begin());
    }

    FORE(it, s) if (it->se != value) {
        printf("%d\n", it->se);
        return;
    }

    printf("-1\n");
}

int main(void) {
    while (true) {
        init();
        process();
    }

    return 1;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/