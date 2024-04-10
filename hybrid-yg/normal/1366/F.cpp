#include<bits/stdc++.h>
using namespace std;
const int N=2005;
const int M=1000000007;
int n,m,i,j,k,q,head[N],Next[N*2],adj[N*2],leng[N*2],p;
int u,v,w;
long long dp[N][N],top,ans;
long double x[N];
struct str{
	long long k,b;
}a[N],sta[N];
void Push(int u,int v,int w)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
	leng[k]=w;
}
bool cmp(str a,str b)
{
	if(a.k==b.k)
		return a.b>b.b;
	return a.k<b.k;
}
long double xl(str a,str b)
{
	return ((long double)(b.b-a.b))/(a.k-b.k);
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d %d",&u,&v,&w);
		Push(u,v,w);
		Push(v,u,w);
	}
	for(i=0;i<=n;++i)
		for(j=0;j<=n;++j)
			dp[i][j]=-10000000000000000ll;
	dp[0][1]=0;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			for(k=head[j];k;k=Next[k])
				dp[i][j]=max(dp[i][j],dp[i-1][adj[k]]+leng[k]);
	for(i=1;i<=n&&i<=q;++i)
	{
		long long mx=0;
		for(j=1;j<=n;++j)
			mx=max(mx,dp[i][j]);
		ans=(ans+mx)%M;
	}
	int las=i;
	for(i=1;i<=n;++i)
	{
		int mx=0;
		for(j=head[i];j;j=Next[j])
			mx=max(mx,leng[j]);
		if(dp[n][i]>0)
			a[++p]=(str){mx,dp[n][i]-1ll*mx*n};
	}
	sort(a+1,a+1+p,cmp);
	for(i=1;i<=p;++i)
		if(a[i].k!=a[i-1].k)
		{
			while(top>1&&xl(sta[top],a[i])<xl(sta[top-1],sta[top]))
				--top;
			sta[++top]=a[i];
		}
	for(i=1;i<=top;++i)
		a[i]=sta[i];
	for(i=1;i<top;++i)
		x[i]=xl(a[i+1],a[i]);
	x[top]=q+1;
	for(i=1;i<=top&&las<=q;++i)
		if(x[i]<q)
		{
			int t=(int)x[i];
			if(x[i]>0&&t>las)
			{
				long long l=las*a[i].k+a[i].b;
				long long r=t*a[i].k+a[i].b;
				ans=(ans+(l+r)%M*(t-las+1)%M*500000004)%M;
				las=t+1;
			}
		}
		else
		{
			long long l=las*a[i].k+a[i].b;
			long long r=q*a[i].k+a[i].b;
			ans=(ans+(l+r)%M*(q-las+1)%M*500000004)%M;
			break;
		}
	cout<<(ans%M+M)%M;
}