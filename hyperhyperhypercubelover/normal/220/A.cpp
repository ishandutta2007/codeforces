#include<cstdio>
#include<algorithm>

int a[200000];
int b[200000];

int main()
{
	int i,n,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	std::sort(b,b+n);
	for(i=0;i<n;i++)if(a[i]!=b[i])cnt++;
	puts(cnt>2?"NO":"YES");
}