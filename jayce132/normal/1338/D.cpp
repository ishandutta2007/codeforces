#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
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

const int maxn=5e5+20;

int n;
vector<int>ed[maxn];

int f[maxn][2];

inline void init()
{
    n=read();
    REP(i,1,n-1)
    {
	int u=read(),v=read();
	ed[u].push_back(v);
	ed[v].push_back(u);
    }
}

int ans;

void dfs(int u,int fa)
{
    int g[4]={0}; g[1]=1;
    int mx=0,son=0;
    for(int v:ed[u])if(v!=fa)dfs(v,u),son++;
    for(int v:ed[u])
    {
	if(v==fa)continue;
	chkmax(ans,max(f[v][0],f[v][1])+mx+son-2+(fa>0));
	chkmax(mx,max(f[v][0],f[v][1]));
	chkmax(ans,g[1]+f[v][0]);
	g[2]++;
	chkmax(g[2],g[0]+max(f[v][0],f[v][1]));
	g[0]++; 
	chkmax(g[1],1+f[v][0]);
    }
    f[u][0]=max(g[0],g[2]);
    f[u][1]=g[1];
}

inline void doing()
{
    int rt=1;
    //REP(i,1,n)if(SZ(ed[i])==1){ rt=i; break;}
    dfs(rt,0);
    chkmax(ans,max(f[rt][0],f[rt][1]));
    printf("%d\n",ans);
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