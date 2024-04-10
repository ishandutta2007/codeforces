#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
double p[MAX];
int n;
double choose(int l,int r) {
    double res=0.0;
    FOR(i,l,r) {
        double tmp=p[i];
        FOR(j,l,r) if (i!=j) tmp*=(1-p[j]);
        res+=tmp;
    }
    return (res);
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%lf",&p[i]);
    sort(p+1,p+n+1);
    double res=0.0;
    FOR(i,1,n) FOR(j,i,n) res=max(res,choose(i,j));
    printf("%.13lf",res);
}
int main(void) {
    init();
    return 0;
}