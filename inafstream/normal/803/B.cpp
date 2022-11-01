#include <bits\stdc++.h>
using namespace std;

int a[200005];

int main()
{
	int n,i;
	
	scanf("%d",&n);
	
	memset(a,127,sizeof(a));
	
	for (i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if (x==0) a[i]=0;
	}
	
	for (i=1;i<=n;i++) a[i]=min(a[i],a[i-1]+1);
	for (i=n;i>=1;i--) a[i]=min(a[i],a[i+1]+1);
	
	for (i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	
	return 0;
}