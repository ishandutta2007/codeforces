#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=100005;

int n,m,a[MAXN];
LL sum[MAXN];
vector <int> ans;

inline bool check(int x)
{
	int p=upper_bound(a+1,a+n+1,x)-a-1;
	return (LL)(1+x)*x/2-sum[p]<=m;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=0,r=1000000000;
	while (l<=r)
	{
		int mid=l+r>>1;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	for (int i=1;i<=r;i++)
		if (a[lower_bound(a+1,a+n+1,i)-a]!=i)
			ans.push_back(i);
	printf("%u\n",ans.size());
	for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	return 0;
}