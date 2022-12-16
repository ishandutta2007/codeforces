#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=500005,M=998244353;
int t,i,j,n,u,v,head[N],Next[N*2],adj[N*2],num[N*2],k;
long long f[N][3],g[N],pre[N],suf[N];
void Push(int u,int v,int w)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
	num[k]=w;
}
struct str{
	int x,s;
}p[N];
bool cmp(str a,str b)
{
	return a.s<b.s;
}
void dfs(int i,int fa,int fn)
{
	int j,k=0;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
			dfs(adj[j],i,num[j]);
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
			p[++k]=(str){adj[j],num[j]};
	sort(p+1,p+1+k,cmp);
	p[k+1].s=6666666;
	pre[0]=suf[k+1]=1;
	for(j=1;j<=k;++j)
		pre[j]=pre[j-1]*(g[p[j].x]+f[p[j].x][2])%M;
	for(j=k;j>=1;--j)
		suf[j]=suf[j+1]*(f[p[j].x][0]+f[p[j].x][1])%M;
	for(j=0;j<=k;++j)
		if(fn>p[j].s&&fn<p[j+1].s)
			g[i]=pre[j]*suf[j+1]%M;
	for(j=0;j<k;++j)
	{
		f[i][1]=(f[i][1]+pre[j]*suf[j+2]%M*(f[p[j+1].x][0]+f[p[j+1].x][1]-f[p[j+1].x][2]))%M;
		if(fn>p[j+1].s)
			f[i][2]=(f[i][2]+pre[j]*suf[j+2]%M*(f[p[j+1].x][0]+f[p[j+1].x][1]-f[p[j+1].x][2]))%M;
	}
	f[i][0]=1;
	for(j=1;j<=k;++j)
		f[i][0]=f[i][0]*(g[p[j].x]+f[p[j].x][2])%M;
	//cout<<i<<' '<<f[i][0]<<' '<<f[i][1]<<' '<<f[i][2]<<' '<<g[i]<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v,i);
		Push(v,u,i);
	}
	dfs(1,0,0);
	cout<<((f[1][0]+f[1][1])%M+M)%M<<endl;
}