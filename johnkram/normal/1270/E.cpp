#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1048576
struct node
{
	int i,d;
	bool operator<(const node& y)const
	{
		if(d==y.d)return i<y.i;
		return d<y.d;
	}
}a[1005];
struct node1
{
	int i,j;
	ll d;
	bool operator<(const node1& y)const
	{
		if(d!=y.d)return d<y.d;
		if(i!=y.i)return i<y.i;
		return j<y.j;
	}
}b[1000005];
int n,m,N,M,i,j,k,x[1005],y[1005],f[1005],d[1005],g[1005][1005],o[1005],q[1000005],he,ta,e[1005][1005];
vector<int> v[1005];
vector<node1> h[1000005];
bool c[1000005];
int get(int x)
{
	if(f[x]==x)return x;
	int r=get(f[x]);
	o[x]^=o[f[x]];
	return f[x]=r;
}
void merge(int x,int y)
{
	x=get(x);
	y=get(y);
	if(x==y)return;
	for(auto i:v[x])for(auto j:v[y])if(!c[g[i][j]])c[q[ta++]=g[i][j]]=1;
	for(auto j:v[y])v[x].push_back(j);
	v[y].clear();
	f[y]=x;
}
void dfs(int x,int c)
{
	d[x]=c;
	for(int i=1;i<=n;i++)if(e[x][i]&&!~d[i])dfs(i,!c);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
	for(i=1;i<=n;i++)
	{
		f[i]=i;
		v[i].push_back(i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			b[++N].i=i;
			b[N].j=j;
			b[N].d=(ll)(x[i]-x[j])*(x[i]-x[j])+(ll)(y[i]-y[j])*(y[i]-y[j]);
		}
	}
	sort(b+1,b+N+1);
	for(i=1;i<=N;i=j)for(M++,j=i;j<=N&&b[j].d==b[i].d;j++)h[g[b[j].i][b[j].j]=M].push_back(b[j]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[j].i=j;
			a[j].d=g[i][j];
		}
		sort(a+1,a+n+1);
		for(j=1;j<=n;j=k)for(k=j;k<=n&&a[j].d==a[k].d;k++)merge(a[k].i,a[j].i);
	}
	while(he!=ta)
	{
		i=q[he++];
		for(auto t:h[i])merge(t.i,t.j);
	}
	for(i=1;i<=M;i++)if(!c[i])
	{
		for(j=0;j<h[i].size();j++)if(get(h[i][j].i)==get(h[i][j].j))break;
		if(j==h[i].size())k=1;
		else k=o[h[i][j].i]^o[h[i][j].j];
		for(auto t:h[i])if(get(t.i)!=get(t.j))
		{
			o[get(t.j)]=o[t.i]^o[t.j]^k;
			f[f[t.j]]=get(t.i);
		}
	}
	for(i=1;i<=n;i++)
	{
		get(i);
		if(!o[i])m++;
	}
	printf("%d\n",m);
	for(i=1;i<=n;i++)if(!o[i])printf("%d ",i);
	return 0;
}