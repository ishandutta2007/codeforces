#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
	int n;
	scanf("%d",&n);
	LL ans=0;
	priority_queue <int,vector<int>,greater<int>> q;
	for (int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);
		if (!q.empty()&&q.top()<p)
		{
			ans+=p-q.top();
			q.pop();
			q.push(p);
		}
		q.push(p);
	}
	printf("%lld\n",ans);
	return 0;
}