#include<bits/stdc++.h>
using namespace std;
#define MAXN 1048576
#define oo 1000000001
#define ll long long
bool g[MAXN];
ll ans;
int n,m,N,M,Q,q,i,j,k,l,h[MAXN],ne[MAXN],p[MAXN],w[MAXN],f[MAXN],d[MAXN],s[MAXN],son[MAXN],top[MAXN],x[MAXN],y[MAXN],z[MAXN],a[MAXN],b[MAXN],c[MAXN],e[MAXN],o[MAXN];
int get(int x)
{
	if(f[x]==x)return x;
	return f[x]=get(f[x]);
}
void dfs(int x)
{
	s[x]=1;
	for(int i=h[x];i;i=ne[i])if(p[i]!=f[x])
	{
		f[p[i]]=x;
		d[p[i]]=d[x]+1;
		c[p[i]]=w[i];
		dfs(p[i]);
		s[x]+=s[p[i]];
		if(s[p[i]]>s[son[x]])son[x]=p[i];
	}
}
void work(int x)
{
	b[a[x]=++N]=x;
	if(son[x])
	{
		top[son[x]]=top[x];
		work(son[x]);
	}
	for(int i=h[x];i;i=ne[i])if(p[i]!=son[x]&&p[i]!=f[x])
	{
		top[p[i]]=p[i];
		work(p[i]);
	}
}
void fix(int R,int l,int r,int l1,int r1,int x)
{
	if(l1<=l&&r<=r1)
	{
		e[R]=min(e[R],x);
		return;
	}
	int mid=l+r>>1;
	if(l1<=mid)fix(R<<1,l,mid,l1,r1,x);
	if(r1>mid)fix(R<<1|1,mid+1,r,l1,r1,x);
}
void ask(int R,int l,int r,int x)
{
	x=min(x,e[R]);
	if(l==r)
	{
		c[b[l]]=min(c[b[l]],x);
		if(g[b[l]])if(c[b[l]]==oo)
		{
			puts("-1");
			exit(0);
		}
		else ans+=c[b[l]];
		return;
	}
	int mid=l+r>>1;
	ask(R<<1,l,mid,x);
	ask(R<<1|1,mid+1,r,x);
}
int main()
{
	scanf("%d%d%d",&n,&M,&q);
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&j,&k);
		f[get(j)]=get(k);
		p[++m]=k;
		ne[m]=h[j];
		w[m]=oo;
		h[j]=m;
		p[++m]=j;
		ne[m]=h[k];
		w[m]=oo;
		h[k]=m;
	}
	while(q--)
	{
		scanf("%d%d%d",&j,&k,&l);
		if(get(j)==get(k))
		{
			x[++Q]=j;
			y[Q]=k;
			z[Q]=l;
		}
		else
		{
			f[get(j)]=get(k);
			p[++m]=k;
			ne[m]=h[j];
			w[m]=l;
			h[j]=m;
			p[++m]=j;
			ne[m]=h[k];
			w[m]=l;
			h[k]=m;
		}
	}
	f[1]=0;
	dfs(1);
	top[1]=1;
	work(1);
	for(i=2;i<=n;i++)if(c[i]==oo)g[i]=1;
	memset(e,127,sizeof(e));
	memset(o,127,sizeof(o));
	for(i=1;i<=Q;i++)
	{
		for(j=x[i],k=y[i];top[j]!=top[k];j=f[top[j]])
		{
			if(d[top[j]]<d[top[k]])j^=k^=j^=k;
			o[a[j]]=min(o[a[j]],z[i]);
		}
		if(d[j]>d[k])j^=k^=j^=k;
		if(j!=k)fix(1,1,n,a[j]+1,a[k],z[i]);
	}
	for(i=n,j=oo;i;i--)
	{
		j=min(j,o[i]);
		c[b[i]]=min(c[b[i]],j);
		if(top[b[i]]==b[i])j=oo;
	}
	ask(1,1,n,oo);
	cout<<ans<<endl;
	return 0;
}