#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
struct str{
	int x0;
	int y0;
	int start;
	int type;
	int index;
};
bool cmp(str a, str b)
{
	if(a.x0==b.x0)
	{
		return a.start<b.start;
	}
	return a.x0<b.x0;
}
std::vector<str> V;
std::set< std::pair<int,int> > S[5];
int check[200010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		V.push_back({b,c,1,d,i});
		V.push_back({c,c,2,d,i});
	}
	std::sort(V.begin(),V.end(),cmp);
	
	int ans = 0;
	for(int i=0;i<V.size();i++)
	{
		if(V[i].start==1) S[V[i].type].insert(std::make_pair(V[i].y0,V[i].index));
		else
		{
			if(check[V[i].index]) continue;
			check[V[i].index] = 1;
			S[V[i].type].erase(std::make_pair(V[i].y0,V[i].index));
			
			if(!S[3-V[i].type].empty())
			{
				std::set< std::pair<int,int> > ::iterator it = S[3-V[i].type].begin();
				check[it->second] = 1;
				S[3-V[i].type].erase(it);
				ans++;
			}
		}
	}
	
	printf("%d",a-ans);
}