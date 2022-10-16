#include<bits/stdc++.h>
#define MAX   2222
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
int a[MAX], cnt[MAX], n, m;
void init(void) {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", &a[i]);
}
void process(void) {
    int res = n / m;
    vector<int> canChange, needChange;
    FOR(i, 1, n) {
        if (a[i] > m) canChange.push_back(i);
        else if (++cnt[a[i]] > res) canChange.push_back(i);
    }
    FOR(i, 1, m) REP(love, res - cnt[i]) needChange.push_back(i);
    assert(needChange.size() <= canChange.size());
    REP(i, needChange.size()) a[canChange[i]] = needChange[i];
    printf("%d %d\n", res, (int)needChange.size());
    FOR(i, 1, n) printf("%d ", a[i]); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}