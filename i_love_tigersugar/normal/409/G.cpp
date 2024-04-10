#include<cstdio>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
inline double nextDouble(void) {
    double x;
    scanf("%lf",&x);
    return (x);
}
int main(void) {
    int n=nextDouble();
    double res=5.0;
    REP(zz,n) res+=nextDouble()*0.0+nextDouble()/n;
    printf("%.5lf",res);
    return 0;
}