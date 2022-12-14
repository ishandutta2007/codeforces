#include <stdio.h>
#include <vector>
#include <algorithm>
int x[200010],y[200010];
int count[200010];
std::vector<int> V[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	std::sort(x+1,x+a+1);
	
	int min = 1, max = a;
	int ans = a;
	while(min<=max)
	{
		int h = (min+max)/2;
		for(int i=0;i<=a;i++) count[i] = 0;
		
		for(int i=a;i>=1;i--)
		{
			count[i%h]++;
			if(count[i%h]>y[x[i]])
			{
				min = h+1;
				goto u;
			}
		}
		ans = h;
		max = h-1;
		u:;
	}
	printf("%d\n",ans);
	for(int j=a;j>=1;j--) V[j%ans].push_back(x[j]);
	for(int i=0;i<ans;i++)
	{
		printf("%d ",V[i].size());
		for(int j=0;j<V[i].size();j++) printf("%d ",V[i][j]);
		printf("\n");
	}
}