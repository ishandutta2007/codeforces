// Hydro submission #6327c0e16de4317b0a26db1c@1663550130173
#include<bits/stdc++.h>
const int N=22e4,G=N*4,K=3,inf=(1u<<31)-1; 
using namespace std;
int n,m,mn[K][G],mx[K][G],cc[K][G],lz[K][G];
struct shirt
{
	int c,q;
	bool operator < (shirt b) const
	{
		return q==b.q?c<b.c:b.q<q;
	}
	void read()
	{
		cin>>c>>q;
	}
}e[N];
void cg(int k,int u,int x,int y)
{
	if(mx[k][u])
		mx[k][u]-=x,mn[k][u]-=x,
		lz[k][u]+=x,cc[k][u]+=y;
}
void down(int k,int u)
{
	if(lz[k][u]||cc[k][u])
		cg(k,u*2,lz[k][u],cc[k][u]),
		cg(k,u*2|1,lz[k][u],cc[k][u]),
		lz[k][u]=cc[k][u]=0;
}
void upd(int k,int u)
{
	mx[k][u]=max(mx[k][u*2],mx[k][u*2|1]),
	mn[k][u]=min(mn[k][u*2],mn[k][u*2|1]);
}
void add(int k,int u,int l,int r,int x,int y)
{
	if(l==r)
		mx[k][u]=mn[k][u]=y;
	else
	{
		int mid=(l+r)/2;
		down(k,u);
		if(x<=mid)add(k,u*2,l,mid,x,y);
		else add(k,u*2|1,mid+1,r,x,y); 
		upd(k,u);
	}
}
void mus(int k,int u,int l,int r,int y)
{
	if(mx[k][u]>=y)
	{
		if(mn[k][u]-y>=(1<<(k*10)))cg(k,u,y,1);
		else if(l==r)
		{
			if(mx[k][u]>y)add(__lg(mx[k][u]-y)/10,1,1,m,l,mx[k][u]-y);
			mx[k][u]=0,mn[k][u]=inf,++cc[k][u];
		}
		else
		{
			int mid=(l+r)/2;
			down(k,u),
			mus(k,u*2,l,mid,y),
			mus(k,u*2|1,mid+1,r,y),
			upd(k,u);
		}
	}
}
void tvl(int u,int l,int r)
{
	if(l==r)
	{
		int res=0;
		for(int i=0;i<K;++i)
			res+=cc[i][u];
		cout<<res<<' ';
	}
	else
	{
		for(int i=0;i<K;++i)
			down(i,u);
		int mid=(l+r)/2;
		tvl(u*2,l,mid),
		tvl(u*2|1,mid+1,r);
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;++i)e[i].read();
	sort(e,e+n);
	cin>>m;
	for(int i=0;i<K;++i)
		fill(mn[i],mn[i]+4*m+4,inf);
	for(int i=1,x;i<=m;++i)
		cin>>x,add(__lg(x)/10,1,1,m,i,x);
	for(int i=0;i<n;++i)
		for(int j=0;j<K;++j)
			mus(j,1,1,m,e[i].c);
	tvl(1,1,m);
	return 0;
}