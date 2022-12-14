#include <stdio.h>
#include <vector>

std::vector<int> V[100010];
std::vector< std::pair<int,int> > ans;
int limit;

int func(int k, int prev, int start)
{
	int P = start;
	int E = V[k].size();
	if(prev!=0) E--;
	
	ans.push_back( std::make_pair(k,start) );
	if(start==limit && limit>1)
	{
		ans.push_back( std::make_pair(k,P-E-1) );
		start = start - E-1;
	}
	
	int s = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		s++;
		func(V[k][i],k,start+1);
		start++;
		ans.push_back( std::make_pair(k,start) );
		if(start==limit&& limit>1)
		{
			ans.push_back( std::make_pair(k,P -E-1+s) );
			start = P - E-1+s;
		}
	}
	if(start!=P-1) ans.push_back( std::make_pair(k, P-1) );
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	limit = V[1].size();
	for(int i=2;i<=a;i++) limit = limit>V[i].size()?limit:V[i].size();
	
	func(1,0,0);
	printf("%d\n",ans.size()-1);
	for(int i=0;i<ans.size()-1;i++)
	{
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
}