#include <stdio.h>
#include <vector>

std::vector<int> V[300010];
int height[300010];
void init(int k, int prev, int h)
{
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		init(V[k][i],k,h+1);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		init(1,0,1);
		
		int ans = a;
		for(int i=2;i<=a;i++)
		{
			if(V[i].size()==1) ans = ans<2*height[i]-1?ans:2*height[i]-1;
			else if(V[i].size()==2) ans = ans<2*height[i]?ans:2*height[i];
		}
		if(V[1].size()==1) ans = ans<2?ans:2;
		
		printf("%d\n",a-ans);
	}
}