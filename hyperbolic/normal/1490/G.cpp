#include <stdio.h>
#include <map>
#include <vector>

std::map<long long int,int> check;
long long int y[200010];
int x[200010];
std::vector<long long int> ans;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		check.clear();
		
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) y[i] = y[i-1] + x[i];
		long long int last = 0;
		check[0] = 0;
		for(int i=1;i<=a;i++)
		{
			if(last<y[i])
			{
				last = y[i];
				check[y[i]] = i;
			}
		}
		
		long long int max = y[1];
		for(int i=1;i<=a;i++) max = max>y[i]?max:y[i];
		
		for(int i=1;i<=b;i++)
		{
			int c;
			scanf("%d",&c);
			if(y[a]<=0)
			{
				std::map<long long int,int> ::iterator it = check.lower_bound(c);
				if(it==check.end()) ans.push_back(0);
				else ans.push_back(it->second);
			}
			else
			{
				if(c<=max)
				{
					std::map<long long int,int> ::iterator it = check.lower_bound(c);
					ans.push_back(it->second);
				}
				else
				{
					long long int t = (c-max)/y[a];
					if(y[a]*t+max<c) t++;
					std::map<long long int,int> ::iterator it = check.lower_bound(c-y[a]*t);
					ans.push_back(it->second + (t*a));
				}
			}
		}
		for(int i=0;i<ans.size();i++) printf("%lld ",ans[i]-1);
		printf("\n");
	}
}