#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1<<(i))
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
int l[13],r[13],n;
int intersect(int x,int y,int u,int v) {
    if (max(x,u)>min(y,v)) return (0);
    return (min(y,v)-max(x,u)+1);
}
void process(void) {
    scanf("%d",&n);
    REP(i,n) scanf("%d%d",&l[i],&r[i]);
    double total=1.0;
    REP(i,n) total*=r[i]-l[i]+1;
    double res=0.0;
    FOR(val,1,10000) {
        double cnt=0.0;
        FOR(equ,1,MASK(n)-1) REP(fst,n) if (!BIT(equ,fst)) {
            double tmp=1.0;
            REP(i,n) {
                if (BIT(equ,i)) tmp*=intersect(l[i],r[i],val,val);
                else if (i==fst) tmp*=intersect(l[i],r[i],val+1,100000);
                else tmp*=intersect(l[i],r[i],0,val-1);
            }
            cnt+=tmp;
        }
        REP(equ,MASK(n)) if (__builtin_popcount(equ)>1) {
            double tmp=1.0;
            REP(i,n) {
                if (BIT(equ,i)) tmp*=intersect(l[i],r[i],val,val);
                else tmp*=intersect(l[i],r[i],0,val-1);
            }
            cnt+=tmp;
        }
        res+=cnt/total*val;
    }
    printf("%.11lf\n",res);
}
int main(void) {
    process();
    return 0;
}