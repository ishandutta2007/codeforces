#include <stdio.h>
int x[110],check[110];
long long int ans = 1;
long long int gcd(long long int a, long long int b)
{
    return a?gcd(b%a,a):b;
}
long long int lcm(long long int a, long long int b)
{
    return a/gcd(a,b)*b;
}
int func(int k, int target)
{
    check[k] = 1;
    if(check[x[k]]==0) return func(x[k],target)+1;
    else
    {
        if(x[k]==target) return 1;
        else return -1234567;
    }
}
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=1;i<=a;i++) scanf("%d",&x[i]);
    for(int i=1;i<=a;i++)
    {
        if(check[i]==0)
        {
            long long int s = func(i,i);
            if(s<0)
            {
                printf("-1");
                return 0;
            }
            else
            {
                if(s%2==0) ans = lcm(s/2,ans);
                else ans = lcm(s,ans);
            }
        }
    }
    printf("%I64d",ans);
}