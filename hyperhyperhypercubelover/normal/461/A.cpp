#include<cstdio>
#include<algorithm>

long long a[333333];

int main()
{
	long long r;
    int i,n;
    scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%I64d",&a[i]);
	std::sort(a,a+n);
	r=-a[n-1];
	for(i=1;i<n;i++)a[i]+=a[i-1];
	r+=2*a[n-1];
	for(i=0;i<n;i++)r+=a[n-1]-a[i];
    printf("%I64d\n",r);
}