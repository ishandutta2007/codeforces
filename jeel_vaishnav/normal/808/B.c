#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
int n,k;
scanf("%d%d",&n,&k);
long long int a[n];
for(int i=0;i<n;i++)
    scanf("%I64d",&a[i]);
int i=0,j=n-1;
long long int mul=1;
double ans=0;
while(i<=j)
    {
    if(i==j)
        ans+=mul*a[i];
    else
        {
        ans+=mul*(a[i]+a[j]);
        if(mul<n-k+1&&mul<k)
        mul++;
    }
    i++;
    j--;
}
    //printf("%lf\n",ans);
    ans/=(n-k+1);
    printf("%lf",ans);
return 0;
}