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

const char YES[] = "YES";
const char NO[] = "NO";

#define MAX   200200
int perm[MAX];
char str[MAX];
int n;

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &perm[i]);
    scanf("%s", str + 1);
    vector<int> sta, fin;
    FOR(i, 1, n - 1) if (str[i] == '1') {
        if (i == 1 || str[i - 1] == '0') sta.push_back(i);
        if (i == n - 1 || str[i + 1] == '0') fin.push_back(i);
    }
    assert(sta.size() == fin.size());
    REP(i, sta.size()) {
        int L = sta[i], R = fin[i] + 1;
        sort(perm + L, perm + R + 1);
    }
    FOR(i, 1, n) if (perm[i] != i) {
        printf("%s\n", NO);
        return;
    }
    printf("%s\n", YES);
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/