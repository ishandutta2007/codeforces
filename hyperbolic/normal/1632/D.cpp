#include <stdio.h>
#include <vector>
#include <algorithm>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int x[200010],ans[200010];
std::vector< std::pair<int,int> > V,temp;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	ans[0] = 0;
	int last = 0,L,R;
	for(int i=1;i<=a;i++)
	{
		if(x[i]==1)
		{
			ans[i] = ans[i-1]+1;
			V.clear();
			last = i;
			continue;
		}
		
		for(int j=0;j<V.size();j++) V[j].first = gcd(V[j].first,x[i]);
		V.push_back(std::make_pair(x[i],i));
		
		temp.clear();
		temp.push_back(V.back());
		V.pop_back();
		while(!V.empty())
		{
			if(V.back().first!=temp.back().first) temp.push_back(V.back());
			V.pop_back();
		}
		for(int i=0;i<temp.size();i++) V.push_back(temp[i]);
		std::reverse(V.begin(),V.end());
		
		ans[i] = ans[i-1];
		int p = (int)V.size()-2;
		for(int j=p;j>=0;j--)
		{
			int L = i-V[j+1].second+1, R = i-V[j].second;
			
			if(L<=V[j+1].first&&V[j+1].first<=R)
			{
				ans[i] = ans[i-1]+1;
				V.clear();
				last = i;
				goto u;
			}
		}
		
		L = i-V[0].second+1, R = i-last;
		if(L<=V[0].first&&V[0].first<=R)
		{
			ans[i] = ans[i-1]+1;
			V.clear();
			last = i;
		}
		u:;
	}
	
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}