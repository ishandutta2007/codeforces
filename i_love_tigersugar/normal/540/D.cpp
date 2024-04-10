#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
double f[MAX][MAX][MAX];
double calc(int r,int s,int p,int mode) {
    REP(i,MAX) REP(j,MAX) REP(k,MAX) f[i][j][k]=0.0;
    FOR(i,1,MAX-1) {
        if (mode==1) f[i][0][0]=1.0;
        else if (mode==2) f[0][i][0]=1.0;
        else f[0][0][i]=1.0;
    }
    REP(i,r+1) REP(j,s+1) REP(k,p+1) if (i*j>0 || j*k>0 || k*i>0) {
        int all=i*j+j*k+k*i;
        if (i*j>0) f[i][j][k]+=f[i][j-1][k]*i*j/all;
        if (j*k>0) f[i][j][k]+=f[i][j][k-1]*j*k/all;
        if (k*i>0) f[i][j][k]+=f[i-1][j][k]*k*i/all;
    }
    return (f[r][s][p]);
}
int main(void) {
    int r,s,p;
    scanf("%d%d%d",&r,&s,&p);
    printf("%.12lf %.12lf %.12lf\n",calc(r,s,p,1),calc(r,s,p,2),calc(r,s,p,3));
    return 0;
}