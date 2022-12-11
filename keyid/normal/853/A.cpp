#include <bits/stdc++.h>
using namespace std;

const int MAXN=300005;

typedef long long LL;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

priority_queue <pii> q;
int c[MAXN],tme[MAXN];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for (int i=1;i<=k;i++)
		q.push(mp(c[i],i));
	for (int i=k+1;i<=k+n;i++)
	{
		if (i<=n)
			q.push(mp(c[i],i));
		tme[q.top().sc]=i;
		q.pop();
	}
	LL ans=0;
	for (int i=1;i<=n;i++)
		ans+=(LL)(tme[i]-i)*c[i];
	printf("%lld\n",ans);
	for (int i=1;i<=n;i++)
		printf("%d ",tme[i]);
	return 0;
}