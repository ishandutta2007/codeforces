#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n,m,a[2005];

void solve()
{
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	if(n==1){puts("0");return;}

	int ans=a[n]-a[1];
	for(int i=1;i<=n-1;i++)
	{
		ans=max(ans,a[i]-a[i+1]);
	}
	for(int i=2;i<=n-1;i++)
	{
		ans=max(ans,a[n]-a[i]);
		ans=max(ans,a[i]-a[1]);
	}
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}