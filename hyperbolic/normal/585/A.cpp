#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> ans;
long long int x[4010],y[4010],z[4010];
int check[4010];
std::priority_queue<int, std::vector<int>, std::greater<int> > Q;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
	
	for(int i=1;i<=a;i++)
	{
		if(check[i]) continue;
		ans.push_back(i);
		int p = 0;
		for(int j=i+1;j<=a;j++)
		{
			if(check[j]) continue;
			if(p>x[i]) break;
			
			z[j] -= (x[i]-p);
			p++;
			if(z[j]<0)
			{
				check[j] = 1;
				Q.push(j);
			}
		}
		while(!Q.empty())
		{
			int k = Q.top();
			Q.pop();
			for(int j=k+1;j<=a;j++)
			{
				if(check[j]) continue;
				z[j] -= y[k];
				if(z[j]<0)
				{
					check[j] = 1;
					Q.push(j);
				}
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
}