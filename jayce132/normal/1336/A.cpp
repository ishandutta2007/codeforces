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

const int maxn=2e5+20;

vector<int>ed[maxn];
int n,k;

inline void init()
{
    n=read();k=read();
    REP(i,1,n-1)
    {
	int x=read(),y=read();
	ed[x].push_back(y);
	ed[y].push_back(x);
    }
}

int deep[maxn],sz[maxn],val[maxn];

void dfs(int u,int fa)
{
    for(int v:ed[u])
    {
	if(v==fa)continue;
	deep[v]=deep[u]+1;
	dfs(v,u);
	sz[u]+=sz[v];
    }
    val[u]=deep[u]-sz[u];
    sz[u]++;
}

inline void doing()
{
    dfs(1,0);
    ll ans=0;
    sort(val+1,val+n+1);
    DREP(i,n,n-k+1)ans+=val[i];
    printf("%lld\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}