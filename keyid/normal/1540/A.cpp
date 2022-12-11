#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair<int,int> pii;

const int MAXN=100005;

int d[MAXN];

void solve()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&d[i]);
	sort(d+1,d+n);
	LL ans=d[n-1],sum=0;
	for (int i=1;i<n;i++)
	{
		if (d[i]>0)
			ans-=d[i];
		ans+=sum-(LL)d[i]*(i-1);
		sum+=d[i];
	}
	printf("%lld\n",ans);
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}