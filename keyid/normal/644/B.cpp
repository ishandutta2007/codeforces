#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=200005;

int d[MAXN];
LL ans[MAXN];
queue <int> q;

int main()
{
	int n,b;
	scanf("%d%d",&n,&b);
	b++;
	LL now;
	for (int i=0,t;i<n;i++)
	{
		scanf("%d%d",&t,&d[i]);
		while (!q.empty()&&now+d[q.front()]<=t)
		{
			now+=d[q.front()];
			ans[q.front()]=now;
			q.pop();
		}
		if (q.empty()) now=t;
		if (q.size()==b) ans[i]=-1;
		else q.push(i);
	}
	while (!q.empty())
	{
		now+=d[q.front()];
		ans[q.front()]=now;
		q.pop();
	}
	for (int i=0;i<n;i++) printf("%I64d ",ans[i]);
	return 0;
}