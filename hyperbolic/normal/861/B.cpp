#include <stdio.h>
#include <algorithm>

std::pair<int,int> P[1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		P[i] = std::make_pair(c,d);
	}
	
	int ans = -1;
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if((P[j].first-1)/i+1!=P[j].second)
			{
				goto u;
			}
		}
		
		if(ans==-1) ans = (a-1)/i+1;
		else if(ans!=(a-1)/i+1)
		{
			printf("-1");
			return 0;
		}
		u:;
	}
	printf("%d",ans);
}