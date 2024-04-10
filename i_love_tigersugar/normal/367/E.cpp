//This code is based on rng_58's solution
#include<bits/stdc++.h>
#define MAX   333
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
const int mod=(int)1e9+7;
int f[2][MAX][MAX];
int n,m,x;
void add(int &x,const int &y) {
    x=(x+y)%mod;
}
void process(void) {
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&x);
    if (n>m) {
        printf("0");
        exit(0);
    }
    x=x-1;
    f[0][0][0]=1;
    REP(i,m) {
        int cur=i%2;
        int next=(i+1)%2;
        REP(j,n+1) REP(k,n+1) f[next][j][k]=0;
        REP(j,n+1) REP(k,n+1) if (f[cur][j][k]>0) {
            if (i!=x) add(f[next][j][k],f[cur][j][k]);
            if (i!=x && j>k) add(f[next][j][k+1],f[cur][j][k]);
            add(f[next][j+1][k],f[cur][j][k]);
            add(f[next][j+1][k+1],f[cur][j][k]);
        }
    }
    int res=f[m%2][n][n];
    FOR(i,1,n) res=1LL*res*i%mod;
    printf("%d",res);
}
int main(void) {
    process();
    return 0;
}