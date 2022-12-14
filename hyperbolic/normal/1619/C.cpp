#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V1,V2,ans;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		ans.clear();
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		
		while(a)
		{
			V1.push_back(a%10);
			a/=10;
		}
		while(b)
		{
			V2.push_back(b%10);
			b/=10;
		}
		std::reverse(V1.begin(),V1.end());
		std::reverse(V2.begin(),V2.end());
		
		int p = V2.size()-1;
		for(int i=V1.size()-1;i>=0;i--)
		{
			if(p<0)
			{
				printf("-1\n");
				goto u;
			}
			if(V1[i]<=V2[p])
			{
				ans.push_back(V2[p]-V1[i]);
				p--;
			}
			else
			{
				if(p==0)
				{
					printf("-1\n");
					goto u;
				}
				else if(V2[p-1]==1)
				{
					ans.push_back(10+V2[p]-V1[i]);
					p-=2;
				}
				else
				{
					printf("-1\n");
					goto u;
				}
			}
		}
		while(p>=0)
		{
			ans.push_back(V2[p]);
			p--;
		}
		
		while(ans.back()==0) ans.pop_back();
		std::reverse(ans.begin(),ans.end());
		
		for(int i=0;i<ans.size();i++) printf("%d",ans[i]);
		printf("\n");
		u:;
	}
}