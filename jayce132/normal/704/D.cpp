#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
inline int read()
{
    int sum=0,p=1;char ch=getchar();
    while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
    if(ch=='-')p=-1,ch=getchar();
    while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum*p;
}

const int maxn=5e5+20;
const int inf=0x3f3f3f3f;

struct node {
    int v,next,w;
};
node e[maxn<<3];
int cnt=1,start[maxn];
inline void addedge(int u,int v,int w){ e[++cnt]=(node){v,start[u],w};start[u]=cnt;}
inline void Addedge(int u,int v,int w){ addedge(u,v,w);addedge(v,u,0);}

int n,m,R,B;
int x[maxn],y[maxn];

int tot,S,T,Sn,Tn;

map<int,int>mpx,mpy;
map<int,int>mpxid,mpyid;
map<int,int>mpxnum,mpynum;
map<int,int>::iterator it;
int rkx[maxn],tpx,rky[maxn],tpy;

int sx[maxn],should;

inline void Add(int u,int v,int l,int r)
{
    if(l>r)puts("-1"),exit(0);
    sx[v]+=l; sx[u]-=l;
    Addedge(u,v,r-l);
}

inline void build()
{
    REP(i,1,tot)if(sx[i]>0)Addedge(Sn,i,sx[i]),should+=sx[i];
    else Addedge(i,Tn,-sx[i]);
}

int num[maxn],ok;

inline void init()
{
    n=read();m=read();
    R=read();B=read();
    REP(i,1,n)x[i]=read(),y[i]=read();
    S=++tot; T=++tot; Sn=++tot; Tn=++tot;
    REP(i,1,m)
    {
	int op=read(),x=read(),d=read();
	if(op==1)rkx[++tpx]=x; else rky[++tpy]=x;
	map<int,int>*mp=op==1?&mpx:&mpy;
	if(!mp->count(x))(*mp)[x]=d;
	else chkmin((*mp)[x],d);
    }
    sort(rkx+1,rkx+tpx+1); tpx=unique(rkx+1,rkx+tpx+1)-rkx-1;
    sort(rky+1,rky+tpy+1); tpy=unique(rky+1,rky+tpy+1)-rky-1;
    for(it=mpx.begin();it!=mpx.end();it++)mpxid[it->fi]=++tot;
    for(it=mpy.begin();it!=mpy.end();it++)mpyid[it->fi]=++tot;
    REP(i,1,n)
    {
	if(mpx.count(x[i]))mpxnum[x[i]]++;
	if(mpy.count(y[i]))mpynum[y[i]]++;
    }
    REP(i,1,tpx)
    {
	int l=mpxnum[rkx[i]]-mpx[rkx[i]]+1>>1,r=mpxnum[rkx[i]]+mpx[rkx[i]]>>1;
	chkmax(l,0);  chkmin(r,mpxnum[rkx[i]]);
	Add(S,mpxid[rkx[i]],l,r);
    }
    REP(i,1,tpy)
    {
	int l=mpynum[rky[i]]-mpy[rky[i]]+1>>1,r=mpynum[rky[i]]+mpy[rky[i]]>>1;
	chkmax(l,0);  chkmin(r,mpynum[rky[i]]);
	Add(mpyid[rky[i]],T,l,r);
    }

    REP(i,1,n)
    {
	num[i]=++tot;
	if(!mpx.count(x[i]) && !mpy.count(y[i]))num[i]=-1,++ok;
	else if(mpx.count(x[i]) && mpy.count(y[i]))
	    Addedge(mpxid[x[i]],num[i],1),Addedge(num[i],mpyid[y[i]],1);
	else if(mpx.count(x[i]))Addedge(mpxid[x[i]],num[i],1),Addedge(num[i],T,1);
	else Addedge(S,num[i],1),Addedge(num[i],mpyid[y[i]],1);
    }
    Addedge(T,S,inf);
    build();
}

int lev[maxn],cur[maxn];

int _S,_T;

inline bool bfs()
{
    static queue<int>q; while(!q.empty())q.pop();
    memset(lev,0,sizeof(int)*(tot+1)); lev[_S]=1;
    q.push(_S);
    while(!q.empty())
    {
	int u=q.front();q.pop();
	EREP(i,u)
	{
	    int v=e[i].v;
	    if(!lev[v] && e[i].w)
	    {
		lev[v]=lev[u]+1;
		q.push(v);
		if(v==_T)return 1;
	    }
	}
    }
    return 0;
}

int dfs(int u,int flow)
{
    if(u==_T)return flow;
    int tag=0;
    for(int &i=cur[u];i;i=e[i].next)
    {
	int v=e[i].v;
	if(lev[v]==lev[u]+1 && e[i].w)
	{
	    int c=dfs(v,min(flow-tag,e[i].w));
	    if(c)
	    {
		e[i].w-=c;
		e[i^1].w+=c;
		tag+=c;
		if(tag==flow)return tag;
	    }
	}
    }
    return tag;
}

inline int max_flow(int S,int T)
{
    _S=S; _T=T;
    int ans=0;
    while(bfs())
    {
	memcpy(cur,start,sizeof(int)*(tot+1));
	ans+=dfs(_S,inf);
    }
    return ans;
}

inline void doing()
{
    int ned=max_flow(Sn,Tn);
    //cerr<<ned<<endl;
    if(ned!=should)puts("-1"),exit(0);
    int x=max_flow(S,T);
    //cerr<<x<<endl;
    ll ans=1ll*(x+ok)*min(R,B)+1ll*(n-x-ok)*max(R,B);
    printf("%lld\n",ans);
    REP(u,1,n)
    {
	int goal=mpyid.count(y[u])?mpyid[y[u]]:T;
	if(num[u]!=-1)
	{
	    EREP(i,num[u])if(e[i].v==goal)
	    {
		if(e[i].w==1)printf("%c",R>B?'r':'b');
		else printf("%c",R>B?'b':'r');
	    }
	}else printf("%c",R>B?'b':'r');
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("captain.in","r",stdin);
    freopen("captain.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}