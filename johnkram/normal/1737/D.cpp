#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
#define MAXM 250005
#define P 1000000007
const int oo=(1<<30)-1;
int t,i,j,k,n,m,u[MAXM],v[MAXM],w[MAXM],d[MAXN][MAXN];
ll ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			fill(d[i]+1,d[i]+n+1,oo);
			d[i][i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",u+i,v+i,w+i);
			d[u[i]][v[i]]=d[v[i]][u[i]]=1;
		}
		for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(d[i][j]>d[i][k]+d[k][j])d[i][j]=d[i][k]+d[k][j];
		ans=1LL<<60;
		for(i=1;i<=m;i++)
		{
			ans=min(ans,((ll)min(d[1][u[i]]+d[n][v[i]],d[1][v[i]]+d[n][u[i]])+1)*w[i]);
			for(j=1;j<=n;j++)ans=min(ans,((ll)min(d[u[i]][j],d[v[i]][j])+1+d[1][j]+d[n][j]+1)*w[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}