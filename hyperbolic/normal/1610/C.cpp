#include <stdio.h>
#include <queue>
#include <vector>

std::vector<int> event[200010];
std::pair<int,int> x[200010],y[200010];
std::priority_queue<int> Q;

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
			int b,c;
			scanf("%d%d",&b,&c);
			x[i] = std::make_pair(b,c);
		}
		
		int ans = 0;
		int min = 1, max = a;
		while(min<=max)
		{
			int h = (min+max)/2;
			while(!Q.empty()) Q.pop();
			for(int i=1;i<=h;i++) event[i].clear();
			
			for(int i=1;i<=a;i++)
			{
				int L = h-x[i].first;
				int R = x[i].second+1;
				R = R<i?R:i;
				L = L>i+h-a?L:i+h-a;
				y[i] = std::make_pair(L,R);
			}
			
			int C = 0;
			for(int i=1;i<=a;i++) if(y[i].first<=C+1&&C+1<=y[i].second) C++;
			
			if(C>=h)
			{
				ans = h;
				min = h+1;
			}
			else max = h-1;
		}
		printf("%d\n",ans);
	}
}