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

const int maxn=2e5+20;

int n,q;
int fa[maxn],son[maxn],ed[maxn][2],deep[maxn];
int faw[maxn][27];

struct Union {
	int fa[maxn];
	inline void Init(){ REP(i,1,n)fa[i]=i;}
	inline int fin(int x){ return x==fa[x]?x:fa[x]=fin(fa[x]);}
	inline void merge(int x,int y){ x=fin(x); y=fin(y); fa[y]=x;}

	inline int operator ()(int x){ return fin(x);}
	
}A;

int f[maxn][27],ok[maxn],dep[maxn],sum[maxn];

void dfs(int u)
{
	if(!ed[u][0] && !ed[u][1])return ok[u]=1,void();
	REP(j,0,26)f[u][j]=0;
	ok[u]=1;
	REP(i,0,1)
	{
		int v=ed[u][i];
		dfs(v); ok[u]&=ok[v]; 
		REP(j,0,26)chkmax(f[u][j],f[v][j]+faw[v][j]);
	}
	REP(j,1,26)sum[u]+=f[u][j];
	if(sum[u]>f[u][0])ok[u]&=0;
}

char FAW[maxn];

inline void init()
{
	n=read();q=read();
	A.Init();
	REP(i,2,n)
	{
		fa[i]=read();ed[fa[i]][son[fa[i]]]=i; son[fa[i]]++;
		char ch; scanf("%c",&ch); FAW[i]=ch;
		faw[i][0]++;
		if(ch!='?')faw[i][ch-'a'+1]++;
		deep[i]=deep[fa[i]]+1;
	}
	int fi=-1;
	REP(i,1,n)if(!son[i])
	{
		if(fi==-1 || fi==deep[i])fi=deep[i];
		else { REP(j,1,q)puts("Fou");exit(0);}
	}
	REP(i,2,n)
	{
		if(fa[i]>1 && son[fa[i]]==1)
		{
			int ff=fa[i];
			A.merge(i,ff);
			fa[i]=fa[ff];
			REP(j,0,26)faw[i][j]+=faw[ff][j];
			ed[fa[i]][ed[fa[i]][1]==ff]=i;
		}
	}
	dfs(1);
}

inline void update(int x,int ch,int d)
{
	faw[A(x)][ch]+=d;
	int u=fa[A(x)];
	while(u)
	{
		//REP(j,0,26)f[u][j]=0;
		sum[u]-=f[u][ch];
		f[u][ch]=0;
		ok[u]=1;
		REP(i,0,1)
		{
			int v=ed[u][i];
			ok[u]&=ok[v]; 
			chkmax(f[u][ch],f[v][ch]+faw[v][ch]);
		}
		sum[u]+=f[u][ch];
		if(sum[u]>f[u][0])ok[u]&=0;
		u=fa[u];
	}
}

inline void doing()
{
	REP(i,1,q)
	{
		int x=read();char ch;
		scanf("%c",&ch);
		if(FAW[x]!='?')update(x,FAW[x]-'a'+1,-1);
		FAW[x]=ch; if(ch!='?')update(x,ch-'a'+1,1);
		
		
		if(ok[1]){
			int wh=f[1][0];REP(j,1,26)wh-=f[1][j];
			ll ans=0;
			REP(j,1,26)ans+=(f[1][j]+wh)*j;
			printf("Shi %lld\n",ans);
		}
		else puts("Fou");
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}