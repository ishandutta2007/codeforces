#include<cstdio>

int a[40];

int f(int t){return t?f(t/2)+t%2:0;}

int main()
{
	int i,n,t;
	long long r=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		a[f(t)]++;
	}
	for(i=0;i<40;i++)r+=1LL*a[i]*(a[i]-1)/2;
	printf("%I64d",r);
}