#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
#define P 1000000007
int ans,i,j,k,n,m,h[MAXN],ne[MAXN<<1],p[MAXN<<1],f[MAXN],l[MAXN],e[MAXN][50];
ll a[MAXN],d[MAXN][50];
inline void ins(int x,ll y,int z)
{
	if(l[x]&&d[x][l[x]]==y)e[x][l[x]]+=z;
	else
	{
		d[x][++l[x]]=y;
		e[x][l[x]]=z;
	}
}
ll gcd(ll x,ll y)
{
	return y?gcd(y,x%y):x;
}
void dfs(int x)
{
	ins(x,a[x],1);
	int i,j;
	for(i=1;i<=l[x];i++)ans=(ans+(ll)d[x][i]*e[x][i])%P;
	for(i=h[x];i;i=ne[i])if(p[i]!=f[x])
	{
		f[p[i]]=x;
		for(j=1;j<=l[x];j++)ins(p[i],gcd(d[x][j],a[p[i]]),e[x][j]);
		dfs(p[i]);
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%lld",a+i);
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
	dfs(1);
	cout<<ans<<endl;
	return 0;
}