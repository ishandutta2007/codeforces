#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
int x[150010];
std::vector<long long int> ans;

struct str{
	long long int first;
	int second;
};
bool operator<(str a, str b)
{
	if(a.first==b.first) return a.second>b.second;
	return a.first>b.first;
}
std::priority_queue<str> Q;

long long int check[150010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) Q.push({x[i],i});
	
	while(!Q.empty())
	{
		if(Q.size()==1)
		{
			check[Q.top().second] = Q.top().first;
			break;
		}
		else
		{
			str P1,P2;
			P1 = Q.top();
			Q.pop();
			P2 = Q.top();
			Q.pop();
			if(P1.first!=P2.first)
			{
				check[P1.second] = P1.first;
				Q.push(P2);
			}
			else Q.push({2*P2.first,P2.second});
		}
	}
	for(int i=1;i<=a;i++) if(check[i]>0) ans.push_back(check[i]);
	
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%lld ",ans[i]);
}