#include<cstdio>
#include<algorithm>

int a[100000];
int b[100000];

int main()
{
	int r=0;
	int i,n,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(i=0;i<m;i++)scanf("%d",&b[i]);
	std::sort(a,a+n);
	std::sort(b,b+m);
	for(i=0;i<m;i++)if(i%(a[0]+2)<a[0])r+=b[m-i-1];
	printf("%d",r);
}