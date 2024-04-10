#include<bits/stdc++.h>
#define MAX   3000300
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
int cntVal[MAX],n;
long long cntWay[MAX];
void init(void) {
    scanf("%d",&n);
    REP(love,n) {
        int x; scanf("%d",&x);
        cntVal[x]++;
    }
}
void prepare(void) {
    FOR(i,1,MAX-1) FOR(j,i+1,MAX-1) {
        if (1LL*i*j>=MAX) break;
        cntWay[i*j]+=2LL*cntVal[i]*cntVal[j];
    }
    FOR(i,1,MAX-1) if (1LL*i*i<MAX) cntWay[i*i]+=1LL*cntVal[i]*(cntVal[i]-1);
    FOR(i,1,MAX-1) cntWay[i]+=cntWay[i-1];
}
long long answer(int p) {
    return (1LL*n*(n-1)-cntWay[p-1]);
}
void process(void) {
    int q; scanf("%d",&q);
    REP(love,q) {
        int p; scanf("%d",&p);
#ifdef ONLINE_JUDGE
        printf("%I64d\n",answer(p));
#else
        cout<<answer(p)<<"\n";
#endif // ONLINE_JUDGE
    }
}
int main(void) {
    init();
    prepare();
    process();
    return 0;
}