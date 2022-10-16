#include<cstdio>
#define LV   707
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
double f[2][LV+7];
int n,k;
void process(void) {
    scanf("%d%d",&n,&k);
    FOR(i,1,n) FOR(j,1,n>LV?LV:n) f[i&1][j]=(j*f[i-1&1][j]+j*(j+3.0)/2.0+f[i-1&1][j+1])/k/(j+1)+f[i-1&1][j]*(k-1)/k;
    printf("%.13lf",f[n&1][1]*k);
}
int main(void) {
    process();
    return 0;
}