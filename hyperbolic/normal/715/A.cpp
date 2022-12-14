#include <stdio.h>
// m = (k+1)k
// (k+1)k+ (k+1)b = (k+2)^2(k+1)^2
// k^2+4k+4 *k+1
// b = k^3 + 5k^2 + 7k + 4
long long int func(long long int k)
{
    return k*k*k + 5*k*k + 7*k + 4;
}
int main()
{
    int a;
    scanf("%d",&a);
    printf("2\n");
    for(int i=1;i<a;i++)
    {
        printf("%I64d\n",func(i));
    }
}