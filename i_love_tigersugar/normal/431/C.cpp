#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
const int mod=(int)1e9+7;
int f[MAX][MAX][2];
int n,m,d;
inline void add(int &x,const int &y) {
    x+=y;
    if (x>=mod) x-=mod;
}
void process(void) {
    scanf("%d%d%d",&n,&m,&d);
    add(f[0][0][0],1);
    REP(i,n) REP(j,n) REP(k,2) if (f[i][j][k]>0)
        FOR(l,1,m) if (j+l<=n) add(f[i+1][j+l][k||(l>=d)],f[i][j][k]);
    int res=0;
    FOR(i,1,n) add(res,f[i][n][1]);
    printf("%d",res);
}
int main(void) {
    process();
    return 0;
}