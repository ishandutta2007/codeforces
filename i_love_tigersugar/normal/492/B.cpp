#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int a[MAX],n,len;
void process(void) {
    double res=0.0;
    scanf("%d%d",&n,&len);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    res=max(res,1.0*a[1]);
    res=max(res,1.0*len-a[n]);
    FOR(i,1,n-1) res=max(res,(a[i+1]-a[i])/2.0);
    printf("%.13lf",res);
}
int main(void) {
    process();
    return 0;
}