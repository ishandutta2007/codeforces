#include <bits/stdc++.h>

using namespace std;

int n,m,i,j,ans,mi;
int a[500005];

int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	
	if (n==1)
	{
		puts("-1");
		return 0;
	}
	if (n==2&&a[2]==a[1])
	{
		puts("-1");
		return 0;
	}
	
	mi=1;
	for (i=2;i<=n;i++) if (a[i]<a[mi]) mi=i;
	
	printf("1\n%d\n",mi);
	
	return 0;
}