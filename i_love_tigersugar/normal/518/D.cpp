#include<bits/stdc++.h>
#define MAX   2020
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int n,t;
double p;
double f[MAX][MAX];
void process(void) {
    scanf("%d%lf%d",&n,&p,&t);
    f[0][0]=1.0;
    FOR(i,1,t) FOR(j,0,i) {
        f[i][j]=0.0;
        if (j>0) f[i][j]+=p*f[i-1][j-1];
        if (i>j) f[i][j]+=(1-p)*f[i-1][j];
    }
    double res=0.0;
    FOR(i,1,t) res+=f[t][i]*min(i,n);
    printf("%.9lf\n",res);
}
int main(void) {
    process();
    return 0;
}