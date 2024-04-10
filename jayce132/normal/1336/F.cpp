#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
    int s=0,f=1; char ch=getchar();
    while(!isdigit(ch) && ch!='-')ch=getchar();
    if(ch=='-')ch=getchar(),f=-1;
    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
    return ~f?s:-s;
}

const int maxn=1.5e5+20;
vector<int>ed[maxn],to[maxn],tol[maxn];

int n,m,k,dfn[maxn],low[maxn],times,top[maxn],son[maxn],sz[maxn],deep[maxn],fa[maxn],id[maxn];

int s[maxn],t[maxn],sat[maxn];

void dfs(int u)
{
    for(int v:ed[u])
    {
	if(v==fa[u])continue;
	deep[v]=deep[u]+1;
	fa[v]=u;
	dfs(v);
	sz[u]+=sz[v];
	if(sz[son[u]]<sz[v])son[u]=v;
    }
    sz[u]++;
}

void dfs1(int u)
{
    dfn[u]=++times; id[times]=u;
    if(son[u])top[son[u]]=top[u],dfs1(son[u]);
    for(int v:ed[u])
    {
	if(v==fa[u] || v==son[u])continue;
	top[v]=v;
	dfs1(v);
    }
    low[u]=times;
}

inline int lca(int u,int v)
{
    while(top[u]!=top[v])
    {
	if(deep[top[u]]>deep[top[v]])swap(u,v);
	v=fa[top[v]];
    }
    if(deep[u]>deep[v])swap(u,v);
    return u;
}

inline int Up(int u,int k)
{
    assert(k>=0);
    int dep=deep[u]-k;
    while(deep[top[u]]>dep)
    {
	u=fa[top[u]];
    }
    return id[dfn[u]-deep[u]+dep];
}

int ad[maxn],ms[maxn];
ll ans,ans1;

void dfs2(int u)
{
    ans+=(ll)(ad[u])*(ad[u]-1)>>1;
    for(int v:ed[u])
    {
	if(v==fa[u])continue;
	dfs2(v);
	if(ad[u] && ad[v])
	    ans+=(ll)ad[u]*ad[v];
	ad[u]+=ad[v];
    }
    ad[u]-=ms[u];
}

inline void init()
{
    n=read();m=read();k=read();
    REP(i,1,n-1)
    {
	int u=read(),v=read();
	ed[u].push_back(v);
	ed[v].push_back(u);
    }
    deep[1]=1; top[1]=1;
    dfs(1); dfs1(1);
    REP(i,1,m)
    {
	s[i]=read(); t[i]=read();
	sat[i]=lca(s[i],t[i]);
	tol[sat[i]].push_back(i);
	if(deep[s[i]]>=deep[sat[i]]+k)
	    ad[s[i]]++,ms[Up(s[i],deep[s[i]]-deep[sat[i]]-k)]++;
	if(deep[t[i]]>=deep[sat[i]]+k)
	    ad[t[i]]++,ms[Up(t[i],deep[t[i]]-deep[sat[i]]-k)]++;
    }
    dfs2(1);
    cerr<<ans<<endl;
}

int rk[maxn<<1],tp;
vector<int>Ed[maxn];

inline bool cmp(int x,int y){ return dfn[x]<dfn[y];}

int RT;

struct node {
    int s,ls,rs;
};
node c[maxn<<6];
int ctot,rt[maxn];

void modify(int x,int d,int &o,int l,int r)
{
    if(!o)o=++ctot;
    c[o].s+=d;
    if(l==r)return;
    int mid=l+r>>1;
    if(x<=mid)modify(x,d,c[o].ls,l,mid);
    else modify(x,d,c[o].rs,mid+1,r);
}

int Merge(int x,int y)
{
    if(!x || !y)return x|y;
    c[x].s+=c[y].s;
    c[x].ls=Merge(c[x].ls,c[y].ls);
    c[x].rs=Merge(c[x].rs,c[y].rs);
    return x;
}

int query(int ql,int qr,int o,int l,int r)
{
    if(!o || ql>qr)return 0;
    if(ql<=l && r<=qr)return c[o].s;
    int mid=l+r>>1,ans=0;
    if(ql<=mid)ans+=query(ql,qr,c[o].ls,l,mid);
    if(qr>mid)ans+=query(ql,qr,c[o].rs,mid+1,r);
    return ans;
}

vector<int>rem[maxn];

inline bool In(int u,int v){ return dfn[u]<=dfn[v] && dfn[v]<=low[u];}

void dfs3(int u)
{
    rt[u]=0;
    for(int id:to[u])
    {
	int x=s[id]^t[id]^u;

	if(deep[u]-deep[RT]>=k)ans-=1ll*SZ(rem[u])*1;
	int downk=k-(deep[u]-deep[RT]);chkmax(downk,0);
	if(deep[x]-deep[RT]>=downk)
	{
	    int y=Up(x,deep[x]-deep[RT]-downk);
	    ans1+=query(dfn[y],low[y],rt[u],1,n);
	}

	
	modify(dfn[x],1,rt[u],1,n);
	rem[u].push_back(x);
    }
    for(int v:Ed[u])
    {
	dfs3(v);
	if(deep[u]-deep[RT]>=k)ans-=1ll*SZ(rem[u])*SZ(rem[v]);
	if(SZ(rem[u])<SZ(rem[v]))
	{
	    rem[u].swap(rem[v]);
	    swap(rt[u],rt[v]);
	}
	for(int x:rem[v])
	{
	    int downk=k-(deep[u]-deep[RT]);chkmax(downk,0);
	    if(deep[x]-deep[RT]>=downk)
	    {
		int y=Up(x,deep[x]-deep[RT]-downk);
		ans1+=query(dfn[y],low[y],rt[u],1,n);
	    }
	    rem[u].push_back(x);
	}
	rt[u]=Merge(rt[u],rt[v]);
    }
}

inline void doing()
{
    for(RT=1;RT<=n;RT++)
    {
	tp=0;
	for(int id:tol[RT])
	{
	    rk[++tp]=s[id];
	    rk[++tp]=t[id];
	    to[s[id]].push_back(id);
	    to[t[id]].push_back(id);
	}
	sort(rk+1,rk+tp+1,cmp);
	tp=unique(rk+1,rk+tp+1)-rk-1;
	REP(i,1,tp-1)rk[++tp]=lca(rk[i],rk[i+1]);
	sort(rk+1,rk+tp+1,cmp);
	tp=unique(rk+1,rk+tp+1)-rk-1;
	if(!tp)continue;
	stack<int>stac; stac.push(rk[1]);
	REP(i,2,tp)
	{
	    while(!In(stac.top(),rk[i]))stac.pop();
	    Ed[stac.top()].push_back(rk[i]);
	    stac.push(rk[i]);
	}
	dfs3(RT);

	//clear:Ed,to
	REP(i,1,tp)Ed[rk[i]].clear(),to[rk[i]].clear(),rem[rk[i]].clear();
	memset(c,0,sizeof(node)*(ctot+1)); ctot=0;
    }
    ans1>>=1;
    
    cerr<<ans<<endl;
    cerr<<ans1<<endl;
    printf("%lld\n",ans+ans1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("f.in","r",stdin);
    freopen("f.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}