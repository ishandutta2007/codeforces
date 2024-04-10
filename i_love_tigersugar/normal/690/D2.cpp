#include<bits/stdc++.h>
#define MAX   700700
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
const int mod=(int)1e6+3;
int frac[MAX],finv[MAX];
int inverse(int x) {
    int res=1;
    int mul=x;
    int k=mod-2;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
void prepare(void) {
    frac[0]=finv[0]=1;
    FOR(i,1,MAX-1) frac[i]=1LL*frac[i-1]*i%mod;
    FOR(i,1,MAX-1) finv[i]=inverse(frac[i]);
}
int comb(int k,int n) {
    if (k>n) return (0);
    return (1LL*frac[n]*finv[k]%mod*finv[n-k]%mod);
}
int solve(int n,int c) {
    int res=0;
    FOR(i,1,n) res=(res+comb(c-1,i+c-1))%mod;
    return (res);
}
int main(void) {
    prepare();
    int n,c; scanf("%d%d",&n,&c);
    printf("%d\n",solve(n,c));
    return 0;
}