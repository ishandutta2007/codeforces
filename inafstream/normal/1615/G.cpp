#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

namespace match
{
	int k,i,j,g[605][605],fa[605],x,y,typ[605],pre[605],lk[605],ans,vis[605],ti,t,tot;
	queue<int> qx;
	int fnd_flower_root(int x)
	{
		if (fa[x]==x) return x;
		return fa[x]=fnd_flower_root(fa[x]);
	}
	int lca(int x,int y)
	{
		ti++;
		for (;;)
		{
			if (x)
			{
				x=fnd_flower_root(x);
				if (vis[x]==ti) return x;
				vis[x]=ti;
				x=pre[lk[x]];
			}
			swap(x,y);
		}
	}
	void merge_flower(int x,int y,int t)
	{
		while (fnd_flower_root(x)!=t)
		{
			pre[x]=y;
			y=lk[x];
			typ[y]=1;
			qx.push(y);
			if (fnd_flower_root(x)==x) fa[x]=t;
			if (fnd_flower_root(y)==y) fa[y]=t;
			x=pre[y];
		}
	} 
	bool flower_try(int x)
	{
		while (!qx.empty()) qx.pop();
		int i;
		rep(i,tot)
		{
			fa[i]=i;
			pre[i]=typ[i]=0;
		}
		typ[x]=1;
		qx.push(x);
		while (!qx.empty())
		{
			int x=qx.front();qx.pop();
			rep(i,tot) if (g[x][i])
			{
				if (fnd_flower_root(x)==fnd_flower_root(i)||typ[i]==2) continue;
				if (typ[i]==0)
				{
					pre[i]=x;
					if (!lk[i])
					{
						int j=i;
						while (j)
						{
							int t=lk[pre[j]];
							lk[j]=pre[j];lk[pre[j]]=j;
							j=t;
						}
						return 1;
					}
					typ[i]=2;typ[lk[i]]=1;qx.push(lk[i]);
				}
				else
				{
					int t=lca(x,i);
					merge_flower(x,i,t);
					merge_flower(i,x,t);
				}
			}
		}
		return 0;
	}
	void doit()
	{
		int i;
		rep(i,tot)
		{
			if (!lk[i]) ans+=flower_try(i);
		}
	}
}

const int N=300005,M=605;

int n,a[N];
int vis[N],fa[N],cyc[N];
int X[N],Y[N];
vector<int> G[N];
int pl[N],pr[N],cnt;
int find(int x){if(fa[x]==x)return x;return fa[x]=find(fa[x]);}
void merge(int x,int y,int id)
{
	int mx=x,my=y; 
	x=find(x);y=find(y);
	if(x!=y)
	{
		if(cyc[x]+cyc[y]!=2) cyc[y]|=cyc[x],fa[x]=y,X[id]=mx,Y[id]=my,G[my].push_back(id),G[mx].push_back(id);
	}
	else if(!cyc[x])
	{
		cyc[x]=1,fa[x]=y,X[id]=mx,Y[id]=my,G[my].push_back(id),G[mx].push_back(id);
	}
}

void push1(int id,int col)
{
	assert(!vis[col]);
	vis[col]=1;
	if(a[pl[id]-1]==col) a[pl[id]]=col;
	else if(a[pr[id]+1]==col) a[pr[id]]=col;
	else assert(false);
}


int vis2[M];
int dfs1(int x,int fa)
{
	if(vis2[x]) return 0;
	vis2[x]=1;
	bool f=0;
	for(int y:G[x]) if(y!=fa)
	{
		int z=X[y]^Y[y]^x;
		if(vis[z]) continue;
		if(!vis2[z])
		{
			if(dfs1(z,y))
			{
				f=1;
				push1(y,x);
			}
			else push1(y,z);
		}
		else
		{
			f=1;
			push1(y,x);
		}
	}
	return f;
}

void push2(int id,int col)
{
	assert(pl[id]!=1);
	assert(pr[id]!=n);
	if(!vis[a[pl[id]-1]]&&find(a[pl[id]-1])==col) vis[a[pl[id]]=a[pl[id]-1]]=1,dfs1(a[pl[id]],0);
	else if(!vis[a[pr[id]+1]]&&find(a[pr[id]+1])==col) vis[a[pr[id]]=a[pr[id]+1]]=1,dfs1(a[pr[id]],0);
	else assert(false);
}

void solve()
{
	int i;
	scanf("%d",&n);rep(i,n)scanf("%d",&a[i]);
	rep(i,n-1) if(a[i]&&a[i]==a[i+1]) vis[a[i]]=1;
	int fir=-1,lst=-1;
	rep(i,n)
	{
		if(a[i]==0)
		{
			if(lst==i-1) lst=i;
			else
			{
				if(fir!=-1) cnt++,pl[cnt]=fir,pr[cnt]=lst;
				fir=lst=i;
			}
		}
	}
	if(fir!=-1) cnt++,pl[cnt]=fir,pr[cnt]=lst;
	
	rep(i,600) fa[i]=i,cyc[i]=0;
	
	rep(i,cnt) 
	{
		int typ=((pr[i]-pl[i]+1)&1);
		if(typ==1)
		{
			int x=0,y=0;
			if(pl[i]!=1&&!vis[a[pl[i]-1]]) x=a[pl[i]-1];
			if(pr[i]!=n&&!vis[a[pr[i]+1]]) y=a[pr[i]+1];
			if(!x&&!y) continue;
			if(!x||!y) x=y=(x|y);
			merge(x,y,i);
		}
	}
	
	rep(i,600) if(fa[i]==i&&cyc[i])
	{
		dfs1(i,0);
	}
	
	match::tot=600;
	rep(i,cnt)
	{
		int typ=((pr[i]-pl[i]+1)&1);
		if(typ==0)
		{
			int x=0,y=0;
			if(pl[i]!=1&&!vis[a[pl[i]-1]]) x=a[pl[i]-1];
			if(pr[i]!=n&&!vis[a[pr[i]+1]]) y=a[pr[i]+1];
			if(!x||!y) continue;
			if(x==y) continue;
			match::g[find(x)][find(y)]=match::g[find(y)][find(x)]=i;
		}
	}
	
	match::doit();
	
	rep(i,600)if(match::lk[i]>i)
	{
		push2(match::g[i][match::lk[i]],i);
		push2(match::g[i][match::lk[i]],match::lk[i]);
	}
	
//	rep(i,600) if(!cyc[find(i)]&&vis[find(i)]) dfs1(i,0);
	rep(i,600) if(!cyc[find(i)]&&!vis[find(i)]) dfs1(i,0);
	
	int t=1;
	rep(i,n)
	{
		if(a[i]==0)
		{
			while(vis[t]) t++;
			vis[t]=1;a[i]=t;
			if(i!=n&&a[i+1]==0)
			{
				a[i+1]=t;
			}
		}
	}
	
//	set<int> s;
//	rep(i,n) assert(a[i]!=0);
//	rep(i,n-1) if(a[i]==a[i+1]) s.insert(a[i]);
//	cout<<s.size()<<endl;

	rep(i,n) printf("%d ",a[i]);
}

int main()
{
	int t=1;
//	scanf("%d",&t);
	while(t--) solve();
	return 0;
}