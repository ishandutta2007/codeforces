#include<cstdio>

long long a[111111];

long long l[111111];
long long r[111111];

long long L[111111];
long long R[111111];

int main()
{
    long long i,j,n;
    scanf("%I64d",&n);
    for(i=1;i<n;i++)scanf("%d",&a[i]);
    for(i=1;i<n;i++)l[i]=a[i]>1?l[i-1]+a[i]/2*2:0;
    for(i=n-2;i>=0;i--)r[i]=a[i+1]>1?r[i+1]+a[i+1]/2*2:0;
    for(i=1;i<n;i++)L[i]=L[i-1]+(a[i]-1)/2*2+1>l[i]?L[i-1]+(a[i]-1)/2*2+1:l[i];
    for(i=n-2;i>=0;i--)R[i]=R[i+1]+(a[i+1]-1)/2*2+1>r[i]?R[i+1]+(a[i+1]-1)/2*2+1:r[i];
    j=0;
    for(i=0;i<n;i++)if(L[i]+R[i]>j)j=L[i]+R[i];
    printf("%I64d",j);
}