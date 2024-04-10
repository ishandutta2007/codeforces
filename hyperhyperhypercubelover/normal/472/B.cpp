#include<cstdio>
#include<algorithm>

int a[2000];

int main()
{
	int r=0;
	int i,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	std::sort(a,a+n);
	for(i=n-1;i>=0;i-=m)r+=a[i]-1;
    printf("%d",r*2);
}