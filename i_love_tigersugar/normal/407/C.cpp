//This solution is based on rng_58's solution
#include<bits/stdc++.h>
#define MAX   100100
#define MAXK   111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
const int mod=(int)1e9+7;
int f[MAX][MAXK];
int a[MAX];
int inv[MAXK];
int n,q;
int inverse(int x) {
    int res=1;
    int mul=x;
    int k=mod-2;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k=k>>1;
    }
    return (res);
}
void init(void) {
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,103) inv[i]=inverse(i);
}
void process(void) {
    REP(zz,q) {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        r++;
        f[l][k]=(f[l][k]+1)%mod;
        int v=1;
        FORD(i,k,0) {
            f[r][i]=(f[r][i]-v+mod)%mod;
            v=1LL*v*(r-l+k-i)%mod;
            v=1LL*v*inv[1+k-i]%mod;
        }
    }
    FOR(i,1,n) FORD(j,103,0) {
        if (i>1) f[i][j]=(f[i][j]+f[i-1][j])%mod;
        if (j<103) f[i][j]=(f[i][j]+f[i][j+1])%mod;
    }
    FOR(i,1,n) {
        if (i>1) printf(" ");
        printf("%d",(a[i]+f[i][0])%mod);
    }
}
int main(void) {
    init();
    process();
    return 0;
}