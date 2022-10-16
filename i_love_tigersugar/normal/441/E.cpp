#include<bits/stdc++.h>
#define MAX   269
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define MASK(x) (1<<(x))
#define BIT(x,i) (((x)>>(i))&1)
double f[2][MAX][MAX][2];
int n,x,p;
int bit2(int x) {
    int res=0;
    while (!BIT(x,0)) {
        res++;
        x>>=1;
    }
    return (res);
}
void process(void) {
    scanf("%d%d%d",&x,&n,&p);
    int fb=BIT(x,8);
    int bc=0;
    while (x>=MASK(8) && BIT(x,bc+8)==fb) bc++;
    f[0][x&(MASK(8)-1)][bc][fb]=1.0;
    REP(i,n) {
        int cur=i&1;
        int next=cur^1;
        REP(j,MAX) REP(k,MAX) REP(l,2) f[next][j][k][l]=0.0;
        REP(j,MAX) REP(k,MAX) REP(l,2) if (f[cur][j][k][l]>0.0) {
            f[next][(j<<1)&(MASK(8)-1)][1+(BIT(j,7)==l)*k][BIT(j,7)]+=p/100.0*f[cur][j][k][l];
            if (j<MASK(8)-1) f[next][j+1][k][l]+=(100.0-p)/100.0*f[cur][j][k][l];
            else {
                if (l) f[next][0][k][0]+=(100.0-p)/100.0*f[cur][j][k][l];
                else f[next][0][1][1]+=(100.0-p)/100.0*f[cur][j][k][l];
            }
        }
    }
    double res=0.0;
    REP(i,MAX) REP(j,MAX) REP(k,2) if (f[n&1][i][j][k]>0.0) {
        int bc=i>0?bit2(i):(k==0)*j+8;
        res+=f[n&1][i][j][k]*bc;
    }
    printf("%.7lf",res);
}
int main(void) {
    process();
    return 0;
}