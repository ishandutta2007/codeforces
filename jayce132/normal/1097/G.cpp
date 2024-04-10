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
#define SZ(A) ((int)a.size())
inline int read()
{
    int sum=0,p=1;char ch=getchar();
    while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
    if(ch=='-')p=-1,ch=getchar();
    while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum*p;
}

const int maxn=1e5+20;
const int mod=1e9+7;

vector<int>ed[maxn];
int S[220][220];

int n,k;

inline void init()
{
	n=read();k=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	S[1][1]=1;
	REP(i,2,k)REP(j,1,i)S[i][j]=(S[i-1][j-1]+(ll)S[i-1][j]*j)%mod;
}

int f[maxn][220];
int sz[maxn];
int g[220];

void dfs(int u,int fa)
{
	f[u][0]=1; sz[u]=0;
	for(int v:ed[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		DREP(a,min(sz[u],k),0)
		{
			DREP(b,min(sz[v],k-a),0)
			{
				int t=(ll)f[u][a]*f[v][b]%mod;
				//f[u][a+b+1]=(f[u][a+b+1]+t)%mod;
				f[u][a+b]=(f[u][a+b]+t)%mod;
			}
		}
			
		DREP(b,sz[v],0)f[u][b]=(f[u][b]+f[v][b])%mod;
		sz[u]+=sz[v];
		chkmin(sz[u],k);
	}
	if(u>1)
	{
		REP(j,0,sz[u])g[j+1]=(g[j+1]-f[u][j])%mod;
		DREP(a,sz[u],0)f[u][a+1]=(f[u][a+1]+f[u][a])%mod;
		sz[u]++; 
	}else REP(j,0,sz[u])g[j]=(g[j]+f[1][j])%mod;
}

inline void doing()
{
	dfs(1,0);
	int ans=0,xs=1;
	REP(j,0,min(sz[1],k))ans=(ans+(ll)S[k][j]*g[j]%mod*xs)%mod,xs=(ll)xs*(j+1)%mod;
	ans=(ans+mod)%mod;
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1097G.in","r",stdin);
    freopen("1097G.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}