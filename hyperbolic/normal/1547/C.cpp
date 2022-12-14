#include <stdio.h>
#include <vector>

std::vector<int> ans;

int x[310],y[310];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=b;i++) scanf("%d",&x[i]);
		for(int i=1;i<=c;i++) scanf("%d",&y[i]);
		
		int p1 = 1, p2 = 1;
		while(p1<=b || p2<=c)
		{
			if(p1>b)
			{
				if(y[p2]==0) ans.push_back(y[p2]), a++, p2++;
				else
				{
					if(y[p2]>a)
					{
						printf("-1\n");
						goto u;
					}
					else ans.push_back(y[p2]),p2++;
				}
			}
			else if(p2>c)
			{
				if(x[p1]==0) ans.push_back(x[p1]), a++, p1++;
				else
				{
					if(x[p1]>a)
					{
						printf("-1\n");
						goto u;
					}
					else ans.push_back(x[p1]),p1++;
				}
			}
			else
			{
				if(x[p1]==0) ans.push_back(x[p1]), a++, p1++;
				else if(y[p2]==0) ans.push_back(y[p2]), a++, p2++;
				else
				{
					if(x[p1]<=a) ans.push_back(x[p1]),p1++;
					else if(y[p2]<=a) ans.push_back(y[p2]),p2++;
					else
					{
						printf("-1\n");
						goto u;
					}
				}
			}
		}
		
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
		u:;
	}
}