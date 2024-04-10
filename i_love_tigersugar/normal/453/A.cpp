#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
int m,n;
double pw(double x,int k) {
    double res=1.0;
    double mul=x;
    while (k>0) {
        if (k&1) res=res*mul;
        mul=mul*mul;
        k=k>>1;
    }
    return (res);
}
int main(void) {
    int m,n;
    scanf("%d%d",&m,&n);
    double res=0;
    FOR(i,1,m) res+=i*(pw(1.0*i/m,n)-pw(1.0*(i-1)/m,n));
    printf("%.9lf",res);
    return 0;
}