#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<int> save[1000010];
int x[2010];
int check[2010];
std::vector< std::pair<int,int> > ans;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=2*a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+2*a+1);
		
		for(int i=1;i<=2*a-1;i++)
		{
			for(int j=1;j<=2*a;j++) save[x[j]].push_back(j);
			ans.clear();
			for(int j=1;j<=2*a;j++) check[j] = 0;
			
			check[i] = 1;
			ans.push_back(std::make_pair(x[i],x[2*a]));
			int p = x[2*a];
			for(int j=2*a-1;j>=1;j--)
			{
				if(check[j]) continue;
				save[x[j]].pop_back();
				
				if(p-x[j]<=0) goto v;
				else if(save[p-x[j]].size()>0)
				{
					check[save[p-x[j]].back()] = 1;
					save[p-x[j]].pop_back();
					ans.push_back(std::make_pair(p-x[j],x[j]));
					p = x[j];
				}
				else goto v;
			}
			
			printf("YES\n");
			printf("%d\n",ans[0].first+ans[0].second);
			for(int j=0;j<ans.size();j++) printf("%d %d\n",ans[j].first,ans[j].second);
			for(int j=1;j<=2*a;j++) save[x[j]].clear();
			goto u;
			
			v:;
			for(int j=1;j<=2*a;j++) save[x[j]].clear();
		}
		printf("NO\n");
		u:;
	}
}