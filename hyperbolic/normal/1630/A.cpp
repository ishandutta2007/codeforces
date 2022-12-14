#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > ans;
int check[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		if(b==a-1)
		{
			if(a==4) printf("-1\n");
			else
			{
				ans.push_back(std::make_pair(a-2,a-1));
				ans.push_back(std::make_pair(1,3));
				ans.push_back(std::make_pair(a-1-3,0));
				check[1] = 1, check[3] = 1;
				for(int i=1;i<a/2;i++)
				{
					if(check[i]==0)
					{
						ans.push_back(std::make_pair(i,a-1-i));
					}
				}
				check[1] = 0, check[3] = 0;
			}
			for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
		}
		else
		{
			ans.push_back(std::make_pair(b,a-1));
			if(b!=0) ans.push_back(std::make_pair(a-1-b,0));
			check[b] = 1, check[a-1-b] = 1;
			for(int i=1;i<a/2;i++)
			{
				if(check[i]==0)
				{
					ans.push_back(std::make_pair(i,a-1-i));
				}
			}
			check[b] = 0, check[a-1-b] = 0;
			
			for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
		}
	}
}