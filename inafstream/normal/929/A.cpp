#include <bits\stdc++.h>

using namespace std;

int ans=0,lst;

int g[111111];

int main()
{
	int n,d;
	
	scanf("%d%d",&n,&d);
	
	int i;
	for (i=1;i<=n;i++) scanf("%d",&g[i]);
	
	int lst=g[1];
	
	for (i=2;i<=n;i++)
	{
		if (g[i]-lst>d)
		{
			ans++;
			lst=g[i-1];
		}
		
		if (g[i]-lst>d)
		{
			puts("-1");
			
			return 0;
		}
	}
	
	printf("%d\n",ans+1);
	
	return 0;
}