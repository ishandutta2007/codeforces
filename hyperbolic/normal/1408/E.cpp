#include <stdio.h>
#include <vector>
#include <algorithm>

struct str{
	int first;
	int second;
	int value;
};
bool cmp(str a, str b)
{
	return a.value<b.value;
}
std::vector<str> edge;

int x[100010],y[100010];
int next[100010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=c;j++)
		{
			int d;
			scanf("%d",&d);
			edge.push_back({i,a+d,x[i]+y[d]});
		}
	}
	for(int i=1;i<=a+b;i++) next[i] = i;
	std::sort(edge.begin(),edge.end(),cmp);
	
	long long int ans = 0;
	for(int i=edge.size()-1;i>=0;i--)
	{
		int s = edge[i].first;
		int t = edge[i].second;
		s = find(s);
		t = find(t);
		if(s==t) ans += edge[i].value;
		else
		{
			next[s] = t;
		}
	}
	printf("%lld",ans);
}