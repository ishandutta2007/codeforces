#include<cstdio>
#include<algorithm>

int a[10000000];

int main()
{
	int i,j,n;
	scanf("%d",&n);
    for(i=1;i<=n;i++)a[i]=i;
    for(i=2;i<=n;i++)for(j=n/i*i+2*i-1;j>i;j-=i)a[std::min(j,n+i-1)]=a[j-i];
    for(i=1;i<=n;i++)printf("%d ",a[i+n-1]);
}