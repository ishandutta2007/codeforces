#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
int t,n,m,i,j,k,ans;
ll s[MAXN],d;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)for(s[i]=0,j=1;j<=m;j++)
		{
			scanf("%d",&k);
			s[i]+=(ll)j*k;
		}
		if(s[1]!=s[2])
		{
			d=s[n];
			i=1+(s[1]==s[n]);
		}
		else for(d=s[1],i=3;i<=n;i++)if(s[i]!=s[1])break;
		printf("%d %lld\n",i,s[i]-d);
	}
	return 0;
}