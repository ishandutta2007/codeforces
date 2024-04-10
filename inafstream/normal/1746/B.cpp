#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n,m,a[100005];

int b[100005],c[100005];

void solve()
{
	scanf("%d",&n);

	rep(i,n)
	{
		scanf("%d",&a[i]);
	}

	b[0]=c[n+1]=0;
	rep(i,n) b[i]=b[i-1]+(a[i]==1);
	per(i,n) c[i]=c[i+1]+(a[i]==0);

	int ans=n;
	rep(i,n+1)
	{
		ans=min(ans,max(b[i-1],c[i]));
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