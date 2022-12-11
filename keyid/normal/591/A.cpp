#include <cstdio>

int main()
{
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    printf("%.9f",a*b/(b+c));
    return 0;
}