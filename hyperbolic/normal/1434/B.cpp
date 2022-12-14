#include <stdio.h>
#include <vector>
#include <set>
int check[200010];
std::vector< std::pair<int,int> > query;
std::vector<int> St;
std::set<int> S;
char x[10];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=2*a;i++)
	{
		scanf("%s",x+1);
		if(x[1]=='+')
		{
			St.push_back(i);
			query.push_back(std::make_pair(1,i));
		}
		else
		{
			int b;
			scanf("%d",&b);
			if(St.empty())
			{
				printf("NO");
				return 0;
			}
			check[St.back()] = b;
			St.pop_back();
			query.push_back(std::make_pair(2,b));
		}
	}
	
	for(int i=0;i<query.size();i++)
	{
		if(query[i].first==1) S.insert(check[query[i].second]);
		else
		{
			int k = *(S.begin());
			if(k!=query[i].second)
			{
				printf("NO");
				return 0;
			}
			S.erase(k);
		}
	}
	printf("YES\n");
	for(int i=0;i<query.size();i++)
	{
		if(query[i].first==1) printf("%d ",check[query[i].second]);
	}
}