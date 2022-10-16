#include<bits/stdc++.h>
#define MAX   555
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int a[MAX];
int n,m;
inline void maximize(double &x,const double &y) {
    if (x<y) x=y;
}
void process(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    double best=0;
    REP(zz,m) {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        maximize(best,1.0*(a[u]+a[v])/c);
    }
    printf("%.13lf",best);
}
int main(void) {
    process();
    return 0;
}