#include<bits/stdc++.h>
#define MAX   2000200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int mod=(int)1e9+7;
int cnt[MAX],frac[MAX],finv[MAX];
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
int comb(int n,int k) {
    if (k>n) return (0);
    return (1LL*frac[n]*finv[k]%mod*finv[n-k]%mod);
}
void process(void) {
    frac[0]=finv[0]=1;
    FOR(i,1,MAX-1) {
        frac[i]=1LL*frac[i-1]*i%mod;
        finv[i]=inverse(frac[i]);
    }
    cnt[0]=1;
    int n;
    scanf("%d",&n);
    FOR(i,1,2*n) {
        int num1=comb(i-1,n)*2%mod;
        int num2=(cnt[i-1]-num1+mod)%mod;
        cnt[i]=(2LL*num2+num1)%mod;
    }
    int sum=0;
    REP(i,2*n+1) sum=(sum+cnt[i])%mod;
    printf("%d\n",sum);
}
int main(void) {
    process();
    return 0;
}