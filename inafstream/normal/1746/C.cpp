#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n,m,a[100005],ans[100005];

void solve()
{
	scanf("%d",&n);

	rep(i,n)
	{
		scanf("%d",&a[i]);
		ans[n+1-a[i]]=i;
	}
	
	rep(i,n)
	{
		printf("%d ",ans[i]);
	}
	puts("");
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