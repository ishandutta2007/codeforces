#include <stdio.h>
#include <map>
#include <vector>

std::map<int,int> M,M2;
std::vector< std::pair<int,int> > ans;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		M[c]++;
		M2[c]++;
		M[d]--;
	}
	
	int S = 0;
	int s,t;
	for(std::map<int,int> ::iterator it = M.begin(); it!=M.end(); it++)
	{
		int S2 = S;
		S += (it->second);
		if(S2<b && S>=b) s = it->first;
		else if(S2>=b && S<b)
		{
			t = it->first;
			ans.push_back({s,t});
		}
		else if(S<b && S2<b && S2+M2[it->first]>=b) ans.push_back({it->first,it->first});
	}
	
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
}