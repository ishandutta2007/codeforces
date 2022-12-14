#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> ans;
std::vector< std::pair<int,int> > V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		long long int b;
		scanf("%d%lld",&a,&b);
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			if(c<=b) V.push_back(std::make_pair(c,i));
		}
		if(V.empty()) printf("-1\n");
		else
		{
			std::sort(V.begin(),V.end());
			if(V.back().first>=(b+1)/2) printf("1\n%d\n",V.back().second);
			else
			{
				ans.clear();
				long long int sum = 0;
				for(int i=0;i<V.size();i++)
				{
					sum += V[i].first;
					ans.push_back(V[i].second);
					if(sum>=(b+1)/2)
					{
						printf("%d\n",ans.size());
						for(int j=0;j<ans.size();j++) printf("%d ",ans[j]);
						printf("\n");
						goto u;
					}
				}
				printf("-1\n");
				u:;
			}
		}
	}
}