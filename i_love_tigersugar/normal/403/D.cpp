#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define add(x,y) x=(x+(y)%mod)%mod
using namespace std;
const int mod=(int)1e9+7;
int frac[1111];
int g[55][1111];
int f[2][1010][1010];
int s[55][1010][1010];
void optimize(void) {
    frac[0]=1;
    FOR(i,1,1007) frac[i]=1LL*i*frac[i-1]%mod;
    g[0][0]=1;
    FOR(i,1,50) FOR(j,1,1007) FOR(k,1,j) add(g[i][j],g[i-1][j-k]);
    FOR(i,0,1007) {
        f[1][i][i]=1;
        FOR(j,0,1007) s[1][i][j]=j>0?(s[1][i][j-1]+f[1][i][j])%mod:f[1][i][j];
    }
    FOR(i,2,50) FOR(j,0,1007) FOR(k,0,1007) {
        if (j>=k) f[i&1][j][k]=s[i-1][j-k][k-1]; else f[i&1][j][k]=0;
        s[i][j][k]=k>0?(s[i][j][k-1]+f[i&1][j][k])%mod:f[i&1][j][k];
    }
}
void answer(void) {
    int n,k;
    scanf("%d%d",&n,&k);
    if (k*(k-1)/2>n-k) printf("0\n");
    else {
        int res=0;
        FOR(i,0,n+1) {
            int tmp=1LL*s[k][i][i]*g[k+1][n+1-i]%mod;
            add(res,tmp);
        }
        res=1LL*res*frac[k]%mod;
        printf("%d\n",res);
    }
}
int main(void) {
    optimize();
    int t;
    scanf("%d",&t);
    REP(zz,t) answer();
    return 0;
}