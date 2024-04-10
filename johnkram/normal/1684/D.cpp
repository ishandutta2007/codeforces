#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int n,m,i,a[MAXN],b[MAXN];
ll s,ans,j;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		s=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			s+=a[i];
			b[i]=a[i]+i;
		}
		sort(b+1,b+n+1,greater<int>());
		ans=0;
		for(i=1,j=0;i<=m;i++)
		{
			j+=b[i]+i-1-n;
			ans=max(ans,j);
		}
		printf("%lld\n",s-ans);
	}
	return 0;
}