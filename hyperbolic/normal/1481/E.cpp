#include <stdio.h>
#include <algorithm>
#include <vector>

struct str{
	int first;
	int second;
	int count;	
};
bool cmp(str a, str b)
{
	return a.second<b.second;
}
std::vector<str> V;

int x[500010];
int left[500010],right[500010],count[500010];
int ans[500010],ans2[500010];
std::vector<int> V2[500010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int control = 0;
	for(int i=1;i<a;i++) if(x[i]!=x[i+1]) control = 1;
	if(control==0)
	{
		printf("0");
		return 0;
	}
	
	for(int i=1;i<=a;i++) V2[x[i]].push_back(i);
	for(int i=1;i<=a;i++) right[x[i]] = i;
	for(int i=a;i>=1;i--) left[x[i]] = i;
	for(int i=1;i<=a;i++) count[x[i]]++;
	for(int i=1;i<=a;i++) if(count[i]>0) V.push_back({left[i],right[i],count[i]});
	std::sort(V.begin(),V.end(),cmp);
	
	int p = 0;
	for(int i=1;i<=a;i++)
	{
		ans[i] = ans[i-1];
		if(V[p].second==i)
		{
			ans[i] = ans[i] > ans[V[p].first-1]+V[p].count? ans[i] : ans[V[p].first-1]+V[p].count;
			p++;
		}
	}
	for(int i=0;i<V.size();i++)
	{
		int S = V2[x[V[i].second]].size();
		for(int j=0;j<V2[x[V[i].second]].size();j++)
		{
			int t = ans[V2[x[V[i].second]][j]-1] + (S-j);
			ans2[V2[x[V[i].second]][j]] = ans2[V2[x[V[i].second]][j]]>t?ans2[V2[x[V[i].second]][j]]:t;
		}
	}
	int t = ans[a];
	for(int i=1;i<=a;i++) t = t>ans2[i]?t:ans2[i];
	printf("%d",a-t);
}