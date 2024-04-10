#include<bits/stdc++.h>
#define MAX   1001000
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
const int mod=(int)1e9+7;
bool notprime[MAX];
int eul[MAX],sg[MAX],s[MAX],sl[MAX],sl2[MAX];
void eratosthene(void) {
    FOR(i,1,MAX-1) eul[i]=i;
    FOR(i,2,MAX-1) if (!notprime[i])
        for (int j=i;j<MAX;j=j+i) {
            notprime[j]=true;
            eul[j]/=i;
            eul[j]*=i-1;
        }
    FOR(i,1,MAX-1) for (int j=i;j<MAX;j=j+i) sg[j]=(sg[j]+1LL*i*eul[j/i])%mod;
}
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
void precount(void) {
    FOR(i,1,MAX-1) {
        int f=(1LL*i*(i+1)%mod*(2*i+1)%mod*inverse(3)%mod-3LL*i*i%mod+mod+2*sg[i]%mod)%mod;
        s[i]=(s[i-1]+f)%mod;
        sl[i]=(sl[i-1]+1LL*f*i)%mod;
        sl2[i]=(sl2[i-1]+1LL*f*i%mod*i%mod)%mod;
    }
}
int answer(int m,int n) {
    if (m>n) return (answer(n,m));
    return ((sl2[m]-1LL*(m+n+2)*sl[m]%mod+(1LL*m*n%mod+m+n+1)*s[m]%mod+mod)%mod);
}
void process(void) {
    int t;
    scanf("%d",&t);
    REP(zz,t) {
        int m,n;
        scanf("%d%d",&m,&n);
        printf("%d\n",answer(m,n));
    }
}
int main(void) {
    eratosthene();
    precount();
    process();
    return 0;
}