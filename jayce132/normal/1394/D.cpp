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
const ll inf=1ll<<40;

int n,t[maxn],h[maxn];
vector<int>ed[maxn];

inline void init()
{
    n=read();
    REP(i,1,n)t[i]=read();
    REP(i,1,n)h[i]=read();
    REP(i,1,n-1)
    {
	int u=read(),v=read();
	ed[u].push_back(v);
	ed[v].push_back(u);
    }
}

ll dp[maxn][2];

void dfs(int u,int fa)
{
    for(int v:ed[u])
    {
	if(v==fa)continue;
	dfs(v,u);
    }
    static ll f[2];
    f[0]=f[1]=-inf;
    REP(op,0,1)
    {
	if(op==0)
	{
	    if((h[u]<=h[fa]));else continue;
	}
	if(op==1 )
	{
	    if((h[u]>=h[fa]));else continue;
	}
	dp[fa][op]=-inf; dp[fa][op^1]=0;
	ll res=0;
	REP(p,0,1)
	{
	    ll ans=0;
	    static ll st[maxn]; int top=0;
	    for(int v:ed[u])
	    {
		ll a=dp[v][0]+(p==0)*t[u],b=dp[v][1]+(p==1)*t[u];
		ans+=p==0?b:a;
		st[++top]=p==0?a-b:b-a;
	    }
	    sort(st+1,st+top+1,[](ll a,ll b){ return a>b;});
	    REP(i,1,top>>1)ans+=max(st[i],0ll);
	    chkmax(res,ans);
	}
	chkmax(res,-inf);
	f[op]=res;
    }
    dp[u][0]=f[0]; dp[u][1]=f[1];
}

inline void doing()
{
    dfs(1,0);
    ll num=0;
    REP(i,1,n)num+=(ll)t[i]*SZ(ed[i]);
    printf("%lld\n",num-max(dp[1][0],dp[1][1]));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1394d.in","r",stdin);
    freopen("1394d.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}