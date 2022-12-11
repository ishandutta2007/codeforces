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

const int maxn=1e5+20;

int n;
vector<int>ed[maxn];
int T,sz[maxn];

void pre_dfs(int u,int fa)
{
    for(int v:ed[u])
    {
	if(v==fa)continue;
	pre_dfs(v,u);
	sz[u]+=sz[v];
    }
}

inline void init()
{
    n=read();
    REP(i,1,n-1)
    {
	int u=read(),v=read();
	ed[u].push_back(v);
	ed[v].push_back(u);
    }
    REP(i,1,n)chkmax(T,SZ(ed[i]));
    pre_dfs(1,0);
}

#define pii pair<int,int>

vector<pii>ans;

int tag[maxn],tim;

void dfs(int u,int fa,int down,int up)
{
    ans.push_back(mkr(u,down));
    int now=down;
    vector<int>son,SX;
    for(int v:ed[u])
    {
	if(v==fa)continue;
	son.push_back(v);
    }
    int len=SZ(son),rest;
    if(len>up)
    {
	rest=len-up;
	REP(j,1,min(T-now,rest))
	{
	    int v=son.back();son.pop_back(); len--;
	    dfs(v,u,now+1,now);
	    ans.push_back(mkr(u,++now));
	}
    }
    ans.push_back(mkr(u,up-len)); now=up-len;
    for(int v:son)dfs(v,u,now+1,now),ans.push_back(mkr(u,++now));
    
    
}

inline void doing()
{
    ans.push_back(mkr(1,0));
    int now=0;
    for(int v:ed[1])
    {
	dfs(v,1,now+1,now);
	ans.push_back(mkr(1,++now));
    }
    printf("%d\n",SZ(ans));
    for(pii x:ans)printf("%d %d\n",x.fi,x.se);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}