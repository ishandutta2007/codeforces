#include<cstdio>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
inline int nextint(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
inline double nextdouble(void) {
    double x;
    scanf("%lf",&x);
    return (x);
}
int main(void) {
    double res=0.0;
    double len=0.0;
    REP(zz,nextint()) {
        double p=nextdouble();
        res+=p*(2*len+1);
        len=p*(len+1);
    }
    printf("%.9lf",res);
    return 0;
}