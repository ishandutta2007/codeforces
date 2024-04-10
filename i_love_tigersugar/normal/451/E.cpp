#include<bits/stdc++.h>
#define MAX   33
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
typedef long long ll;
const int mod=(int)1e9+7;
int frac[MAX],finv[MAX];
ll s,f[MAX];
int n;
int pw(int x,int k) {
    int res=1;
    int mul=x;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
int comb(ll n,int k) {
    if (n<k) return (0);
    int res=1;
    REP(i,k) {
        int tmp=(n-i)%mod;
        res=1LL*res*tmp%mod;
    }
    return (1LL*res*finv[k]%mod);
}
int bitcount(int x) {
    int res=0;
    REP(i,n) if (BIT(x,i)) res++;
    return (res%2);
}
ll sum(int x) {
    ll res=0;
    REP(i,n) if (BIT(x,i)) res+=f[i]+1;
    return (res);
}
int count(int n,ll s) {
    if (s<0) return (0);
    return (comb(s+n-1,n-1));
}
void init(void) {
    cin>>n>>s;
    REP(i,n) cin>>f[i];
    frac[0]=1;
    finv[0]=pw(frac[0],mod-2);
    FOR(i,1,n) {
        frac[i]=1LL*frac[i-1]*i%mod;
        finv[i]=pw(frac[i],mod-2);
    }
    int res=0;
    REP(i,1<<n) {
        if (bitcount(i)) res=(res-count(n,s-sum(i))+mod)%mod;
        else res=(res+count(n,s-sum(i)))%mod;
    }
    printf("%d",res);
}
int main(void) {
    init();
    return 0;
}