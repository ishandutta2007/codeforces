#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > ans,last,last2;
int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int p = 1;
	for(int i=a;i>=1;i--)
	{
		if(x[i]==1)
		{
			ans.push_back(std::make_pair(i,p));
			last.push_back(std::make_pair(i,p));
			p++;
		}
		else if(x[i]==2)
		{
			if(last.empty())
			{
				printf("-1");
				return 0;
			}
			else
			{
				std::pair<int,int> P = last.back();
				last.pop_back();
				last2.push_back(std::make_pair(i,P.second));
				ans.push_back(std::make_pair(i,P.second));
			}
		}
		else if(x[i]==3)
		{
			if(last2.empty())
			{
				if(last.empty())
				{
					printf("-1");
					return 0;
				}
				else
				{
					std::pair<int,int> P = last.back();
					last.pop_back();
					last2.push_back(std::make_pair(i,p));
					ans.push_back(std::make_pair(i,p));
					ans.push_back(std::make_pair(P.first,p));
					p++;
				}
			}
			else
			{
				std::pair<int,int> P = last2.back();
				last2.pop_back();
				last2.push_back(std::make_pair(i,p));
				ans.push_back(std::make_pair(i,p));
				ans.push_back(std::make_pair(P.first,p));
				p++;
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d\n",a-ans[i].second+1,ans[i].first);
}