#include<bits/stdc++.h>
#define MAX   1000100
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
const long long INF=(long long)1e18+7LL;
long long pw3[MAX];
void precalc(void) {
    FOR(i,1,MAX-1) pw3[i]=1LL*i*i*i;
}
long long countWay(long long n) {
    long long res=0;
    FOR(k,2,MAX-1) res=min(res+n/pw3[k],INF);
    return (res);
}
long long process(long long req) {
    long long L=0;
    long long R=INF;
    while (true) {
        if (L==R) return (L);
        if (R-L==1) return (countWay(L)>=req?L:R);
        long long M=(L+R)>>1;
        if (countWay(M)>=req) R=M; else L=M+1;
    }
}
int main(void) {
    precalc();
    long long req; cin>>req;
    long long ans=process(req);
    cout<<(countWay(ans)==req?ans:-1LL)<<endl;
    return 0;
}