#include<bits/stdc++.h>
using namespace std;
#define MAXN 3005
#define ll long long
ll ans,l;
int n,m,N,i,j,k,s[MAXN],a[MAXN][MAXN],b[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&j,&k);
		a[j][++s[j]]=k;
	}
	for(i=1;i<=m;i++)sort(a[i]+1,a[i]+s[i]+1,greater<int>());
	ans=1LL<<60;
	for(i=1;i<=n;i++)
	{
		for(j=2,l=N=0;j<=m;j++)
		{
			for(k=1;k<i&&k<=s[j];k++)b[++N]=a[j][k];
			for(;k<=s[j];k++)l+=a[j][k];
		}
		sort(b+1,b+N+1);
		for(j=1;j<=i+N-n;j++)l+=b[j];
		ans=min(ans,l);
	}
	cout<<ans<<endl;
	return 0;
}