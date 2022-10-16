#include<bits/stdc++.h>
#define MAX   2222
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
bool r[MAX],c[MAX];
int nr,nc;
int n,m;
double f[MAX][MAX];
void init(void) {
    scanf("%d",&n);
    scanf("%d",&m);
    REP(i,m) {
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        r[x]=true;
        c[y]=true;
    }
    FOR(i,1,n) {
        if (r[i]) nr++;
        if (c[i]) nc++;
    }
}
void optimize(void) {
    f[n][n]=0.0;
    FORD(i,n,0) FORD(j,n,0) if (i<n || j<n)
        f[i][j]=1.0*(i*(n-j)*f[i][j+1]+(n-i)*j*f[i+1][j]+(n-i)*(n-j)*f[i+1][j+1]+n*n)/(n*n-i*j);
    printf("%.9lf",f[nr][nc]);
}
int main(void) {
    init();
    optimize();
    return 0;
}