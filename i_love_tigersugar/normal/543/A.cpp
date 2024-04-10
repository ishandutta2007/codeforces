#include<bits/stdc++.h>
#define MAX   555
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int n,m,b,mod,a[MAX];
int f[2][MAX][MAX];
void init(void) {
    scanf("%d%d%d%d",&n,&m,&b,&mod);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void add(int &x,const int &y) {
    x+=y;
    if (x>=mod) x-=mod;
}
void optimize(void) {
    f[0][0][0]=1;
    int res=0;
    REP(i,n+1) {
        int cur=i&1;
        int next=(i&1)^1;
        REP(j,m+1) REP(k,b+1) if (f[cur][j][k]>0) {
            //printf("F %d %d %d = %d\n",i,j,k,f[cur][j][k]);
            if (i==n) {
                if (j==m) add(res,f[cur][j][k]);
            } else add(f[next][j][k],f[cur][j][k]);
            if (i>0 && j<m && k+a[i]<=b) add(f[cur][j+1][k+a[i]],f[cur][j][k]);
            f[cur][j][k]=0;
        }
    }
    printf("%d\n",res);
}
int main(void) {
    init();
    optimize();
    return 0;
}