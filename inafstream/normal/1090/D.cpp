#include <bits/stdc++.h>

using namespace std;

long long n,m,x,y,i,j;
set<pair<long long,long long> > s;

int main()
{
	scanf("%I64d%I64d",&n,&m);
	
	if ((n-1)*n/2<=m)
	{
		puts("NO");
		return 0;
	}
	
	while (m--)
	{
		scanf("%I64d%I64d",&x,&y);
		
		if (x>y) swap(x,y);
		s.insert(make_pair(x,y));
	}
	
	for (i=1;i<=n;i++)
	{
		for (j=i+1;j<=n;j++)
		{
			if (!s.count(make_pair(i,j)))
			{
				x=i;y=j;
				
				puts("YES");
				long long c=2;
				for (i=1;i<=n;i++)
				{
					if (i==x) printf("1 ");
					else if (i==y) printf("2 ");
					else printf("%d ",++c);
				}
				puts("");
				
				c=2;
				for (i=1;i<=n;i++)
				{
					if (i==x) printf("1 ");
					else if (i==y) printf("1 ");
					else printf("%d ",++c);
				}
				
				return 0;
			}
		}
	}
	
	return -1;
}