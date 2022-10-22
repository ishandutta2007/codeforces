#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,i,j,k,h[3005],ne[6005],p[6005],f[3005][3005],s[3005][3005];
ll ans,d[3005][3005];
void dfs(int r,int x)
{
	s[r][x]=1;
	for(int i=h[x];i;i=ne[i])if(p[i]!=f[r][x])
	{
		f[r][p[i]]=x;
		dfs(r,p[i]);
		s[r][x]+=s[r][p[i]];
	}
}
void work(int x,int y)
{
	if(~d[x][y])return;
	if(x>y)swap(x,y);
	int i;
	ll t=0;
	for(i=h[x];i;i=ne[i])if(p[i]!=f[y][x])
	{
		work(p[i],y);
		t=max(t,d[p[i]][y]);
	}
	for(i=h[y];i;i=ne[i])if(p[i]!=f[x][y])
	{
		work(x,p[i]);
		t=max(t,d[x][p[i]]);
	}
	d[x][y]=d[y][x]=t+s[x][y]*s[y][x];
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		p[++m]=k;
		ne[m]=h[j];
		h[j]=m;
		p[++m]=j;
		ne[m]=h[k];
		h[k]=m;
	}
	for(i=1;i<=n;i++)dfs(i,i);
	memset(d,-1,sizeof(d));
	for(i=2;i<=n;i++)
	{
		work(f[1][i],i);
		ans=max(ans,d[f[1][i]][i]);
	}
	cout<<ans<<endl;
	return 0;
}