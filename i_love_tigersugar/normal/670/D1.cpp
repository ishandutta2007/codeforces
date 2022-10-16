#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
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
const long long INF=(long long)2e9+7;
long long req[MAX],have[MAX],allow;
int n;
void init(void) {
    cin>>n>>allow;
    FOR(i,1,n) cin>>req[i];
    FOR(i,1,n) cin>>have[i];
}
bool ok(long long x) {
    long long rem=allow;
    FOR(i,1,n) {
        rem-=max(0LL,req[i]*x-have[i]);
        if (rem<0) return (false);
    }
    return (true);
}
long long process(void) {
    long long L=0;
    long long R=INF;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (ok(R)?R:L);
        long long M=(L+R)>>1;
        if (ok(M)) L=M; else R=M-1;
    }
}
int main(void) {
    init();
    cout<<process()<<endl;
    return 0;
}