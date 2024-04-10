#include<bits/stdc++.h>
#define MAX   2228
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
const int mod=(int)1e9+7;
int f[MAX][MAX];
inline void add(int &x,const int &y) {
    x+=y;
    if (x>=mod) x-=mod;
}
void process(void) {
    int n,l;
    scanf("%d%d",&n,&l);
    FOR(i,1,n) add(f[1][i],1);
    FOR(i,1,l-1) FOR(j,1,n) if (f[i][j]>0)
        for (int k=j;k<=n;k=k+j) add(f[i+1][k],f[i][j]);
    int res=0;
    FOR(i,1,n) add(res,f[l][i]);
    printf("%d",res);
}
int main(void) {
    process();
    return 0;
}