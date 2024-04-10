#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
#define REP(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;

int n,m;

struct mst
{
	int a,b,c;
}e[200005];
bool cmp(mst x,mst y)
{
	return x.c>y.c;
}


int f[200005][19],lg[200005],ff[200005];
int qmx(int l,int r)
{
	int t=lg[r-l+1];
	return max(f[l][t],f[r-(1<<t)+1][t]);
}

int fa[200005],sz[200005],tp[200005],son[200005],dfn[200005],tag,mp[200005],dep[200005];
vector<pair<int,int> > adj[200005];
void dfs1(int x,int fa)
{
	::fa[x]=fa;sz[x]=1;
	REP(adj[x],it)if(it->first!=fa)
	{
		dep[it->first]=dep[x]+1;
		ff[it->first]=it->second;
		dfs1(it->first,x);
		sz[x]+=sz[it->first];
		if(!son[x]||sz[son[x]]<sz[it->first])son[x]=it->first;
	}
}
void dfs2(int x,int t)
{
	mp[dfn[x]=++tag]=x;tp[x]=t;
	if(son[x])dfs2(son[x],t);
	REP(adj[x],it)if(it->first!=fa[x]&&it->first!=son[x]){dfs2(it->first,it->first);}
}
int lca(int x,int y)
{
	while(tp[x]!=tp[y]){if(dep[tp[x]]<dep[tp[y]])swap(x,y);x=fa[tp[x]];}
	return mp[min(dfn[x],dfn[y])];
}
int qry(int x,int y)
{
	int ans=0;
	while(tp[x]!=tp[y])
	{
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		ans=max(ans,qmx(dfn[tp[x]],dfn[x]));
		x=fa[tp[x]];
	}
	if(x!=y) ans=max(ans,qmx(min(dfn[x],dfn[y])+1,max(dfn[x],dfn[y])));
	return ans;
}

int a[200005];

struct state
{
	set<int> s;
	int mxe;
	int in;
}s[200005];
int faa[200005];
int find(int x)
{
	if(faa[x]==x)return x;
	return faa[x]=find(faa[x]);
}
void merge(int x,int y)
{
	x=find(x);y=find(y);
	if(x==y) return;
	if(s[x].s.size()>s[y].s.size()) swap(x,y);
	faa[x]=y;
	
	if(s[x].mxe>s[y].mxe)
	{
		swap(s[x],s[y]);
		return;
	}
	if(s[x].mxe<s[y].mxe)
	{
		return;
	}
	
	s[y].in=max(s[y].in,s[x].in);
	REP(s[x].s,it)
	{
		set<int>::iterator pos=s[y].s.upper_bound(*it);
		if(pos==s[y].s.end()) s[y].in=max(s[y].in,qry(mp[*it],mp[*s[y].s.begin()])); else s[y].in=max(s[y].in,qry(mp[*it],mp[*pos]));
		if(pos==s[y].s.begin()) s[y].in=max(s[y].in,qry(mp[*it],mp[*s[y].s.rbegin()])); else s[y].in=max(s[y].in,qry(mp[*it],mp[*(--pos)]));
		s[y].s.insert(*it);
	}
}

int ans[200005],ans2[200005],v[200005],c[200005],ord[200005];
bool cmpq(int x,int y)
{
	return c[x]>c[y];
}

int main()
{
	int i;
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n-1)
	{
		int a,b,c,t;
		scanf("%d%d%d%d",&a,&b,&c,&t);
		adj[a].push_back(make_pair(b,t));
		adj[b].push_back(make_pair(a,t));
		e[i]=(mst){a,b,c};
	}
	sort(e+1,e+n,cmp);
	
	dfs1(1,0);
	dfs2(1,1);
	
	int j;
	rep(i,n) lg[i]=(i==1?0:lg[i/2]+1);
	rep(i,n) f[i][0]=ff[mp[i]];
	rep(j,lg[n])
	{
		rep(i,n-(1<<j)+1)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	
	rep(i,m)
	{
		scanf("%d%d",&c[i],&v[i]);ord[i]=i;
	}
	sort(ord+1,ord+m+1,cmpq);
	
	rep(i,n)
	{
		faa[i]=i;
		s[i].s.insert(dfn[i]);
		s[i].mxe=a[i];
		s[i].in=0;
	}
	
	j=1;
	rep(i,m)
	{
		while(j<n&&e[j].c>=c[ord[i]])
		{
			merge(e[j].a,e[j].b);
			j++;
		}
		
		int x=find(v[ord[i]]);
		ans[ord[i]]=s[x].mxe;
		ans2[ord[i]]=max(s[x].in,qry(mp[*s[x].s.begin()],v[ord[i]]));
	}
	
	rep(i,m)
	{
		printf("%d %d\n",ans[i],ans2[i]);
	}
	return 0;
}