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
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}

inline int read()
{
    int s=0,f=1; char ch=getchar();
    while(!('0'<=ch && ch<='9') && ch!='-')ch=getchar();
    if(ch=='-')ch=getchar(),f=-1;
    while('0'<=ch && ch<='9')s=s*10+ch-'0',ch=getchar();
    return ~f?s:-s;
}

const int maxn=1e5+20;
const int inf=0x3f3f3f3f;

int n,len;
int f[100][100];

vector<int>tmp[100];

inline int get(int x)
{
    int s=0;
    while(x)x/=10,s++;
    return s;
}

inline void init()
{
    n=read();
    REP(i,1,n-1)
    {
	char a[10],b[10];
	scanf("%s",a); scanf("%s",b);
	int al=strlen(a),bl=strlen(b);
	if(al>bl)swap(al,bl);
	f[al][bl]++;
    }
    len=get(n); int ten=1;
    REP(i,1,len)
    {
	REP(j,ten,min(ten*10-1,n))tmp[i].push_back(j);
	ten*=10;
    }
}

#define pii pair<int,int>

vector<pii >ans,Ans,YXans;
int db[100],fa[100];
int fin(int x){ return x==fa[x]?x:fa[x]=fin(fa[x]);}
inline void merge(int x,int y){ x=fin(x); y=fin(y); fa[y]=x; }

struct node {
    int v,next,w;
};
node e[maxn<<3];
int cnt=1,start[maxn];
inline void addedge(int u,int v,int w){ e[++cnt]=(node){v,start[u],w};start[u]=cnt;}
inline void Addedge(int u,int v,int w){ addedge(u,v,w); addedge(v,u,0);}
int S,T,id[100][100],tot,num[100];
int tonum[maxn];

int lev[maxn],cur[maxn];
inline bool bfs()
{
    static queue<int>q; while(!q.empty())q.pop();
    memset(lev,0,sizeof(int)*(tot+1));
    q.push(S); lev[S]=1;
    while(!q.empty())
    {
	int u=q.front();q.pop();
	EREP(i,u)
	{
	    int v=e[i].v;
	    if(!lev[v] && e[i].w)
	    {
		lev[v]=lev[u]+1;
		if(v==T)return 1;
		q.push(v);
	    }
	}
    }
    return 0;
}

int dfs(int u,int flow)
{
    if(u==T)return flow;
    int tag=0;
    for(int &i=cur[u];i;i=e[i].next)
    {
	int v=e[i].v;
	if(lev[v]==lev[u]+1 && e[i].w)
	{
	    int c=dfs(v,min(e[i].w,flow-tag));
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

inline int dinic()
{
    int ans=0;
    while(bfs())
    {
	memcpy(cur,start,sizeof(int)*(tot+1));
	ans+=dfs(S,inf);
    }
    return ans;
}

vector<pii >use;

void dfs1(int x,int y)
{
    if(x>len)
    {
	if(SZ(use)!=len-1)return;
	YXans.clear();
	REP(i,1,len)fa[i]=i;
	REP(i,0,len-2)
	{
	    int x=use[i].fi,y=use[i].se;
	    if(fin(x)==fin(y))return;
	    merge(x,y);
	    YXans.push_back(mkr(db[x],db[y]));
	}
	REP(i,0,len-2)
	{
	    int x=use[i].fi,y=use[i].se;
	    f[x][y]--; 
	}

	cnt=1; memset(start,0,sizeof(int)*(tot+1)); tot=0;
	S=++tot; T=++tot;
	REP(i,1,len)num[i]=++tot,Addedge(num[i],T,SZ(tmp[i])-1);
	int all=0;
	REP(i,1,len-1)REP(j,i+1,len)if(f[i][j])
	{
	    id[i][j]=++tot; all+=f[i][j];
	    Addedge(S,id[i][j],f[i][j]);
	    Addedge(id[i][j],num[i],f[i][j]);
	    Addedge(id[i][j],num[j],f[i][j]);
	}
	if(all!=dinic()){ REP(i,0,len-2)f[use[i].fi][use[i].se]++; return;}
	else {
	    REP(i,1,len-1)REP(j,i+1,len)if(f[i][j])
	    {
		int a=-1,b=-1;
		EREP(l,id[i][j])if(e[l].v!=S)
		{
		    int v=e[l].v;
		    if(v==num[i])a=f[i][j]-e[l].w;
		    if(v==num[j])b=f[i][j]-e[l].w;
		}
		REP(th,1,a)ans.push_back(mkr(tmp[i].back(),tmp[j].front())),tmp[i].pop_back();
		REP(th,1,b)ans.push_back(mkr(tmp[i].front(),tmp[j].back())),tmp[j].pop_back();
	    }
	    REP(i,0,SZ(ans)-1)printf("%d %d\n",ans[i].fi,ans[i].se);
	    REP(i,0,SZ(YXans)-1)printf("%d %d\n",YXans[i].fi,YXans[i].se);
	    exit(0);
	}

	
	
    }
    if(y>len)return dfs1(x+1,x+2),void();
    if(f[x][y] && SZ(use)<len-1)use.push_back(mkr(x,y)),dfs1(x,y+1),use.pop_back();
    dfs1(x,y+1);
   
}

inline void doing()
{
    REP(i,1,len)
    {
	if(f[i][i]>=SZ(tmp[i]))puts("-1"),exit(0);
	REP(j,1,f[i][i])ans.push_back(mkr(tmp[i].front(),tmp[i].back())),tmp[i].pop_back();
	db[i]=tmp[i].front();
    }
    dfs1(1,2);
    //REP(i,1,len-1)REP(j,i+1,len)if(f[i][j] && fin(i)!=fin(j))f[i][j]--,merge(i,j),ans.push_back(mkr(db[i],db[j]));
    puts("-1");
}

int main()
{
    init();
    doing();
    return 0;
}