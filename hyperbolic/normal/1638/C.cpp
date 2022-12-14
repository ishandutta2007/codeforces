#include <stdio.h>
#include <algorithm>

std::pair<int,int> x[100010];
int y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			y[i] = b;
			x[i] = std::make_pair(b,i);
		}
		
		std::sort(x+1,x+a+1);
		
		int t = a+1, ans = 0, min = 12345678;
		for(int i=a;i>=1;i--)
		{
			if(x[i].second<=t)
			{
				if(x[i].first<=min) ans++;
				
				for(int j=x[i].second;j<t;j++) min = min<y[j]?min:y[j];
				t = x[i].second;
			}
		}
		printf("%d\n",ans);
	}
}