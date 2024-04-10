// Hydro submission #628cc58637e0de7afd369b68@1653392775949
#include<cstdio>
#define db double
#define gc getchar
#define pc putchar
#define U unsigned
#define ll long long
#define ld long double
#define ull unsigned long long
#define Tp template<typename _T>
#define Me(a,b) memset(a,b,sizeof(a))
Tp _T mabs(_T a){ return a>0?a:-a; }
Tp _T mmax(_T a,_T b){ return a>b?a:b; }
Tp _T mmin(_T a,_T b){ return a<b?a:b; }
Tp void mswap(_T &a,_T &b){ _T tmp=a; a=b; b=tmp; return; }
Tp void print(_T x){ if(x<0) pc('-'),x=-x; if(x>9) print(x/10); pc((x%10)+48); return; }
#define EPS (1e-7)
#define INF (0x7fffffff)
#define LL_INF (0x7fffffffffffffff)
#define maxn 300039
#define maxm 300039
#define MOD 1000000007
#define Type int
#ifndef ONLINE_JUDGE
//#define debug
#endif
using namespace std;
Type read(){
	char c=gc(); Type s=0; int flag=0;
	while((c<'0'||c>'9')&&c!='-') c=gc(); if(c=='-') c=gc(),flag=1;
	while('0'<=c&&c<='9'){ s=(s<<1)+(s<<3)+(c^48); c=gc(); }
	if(flag) return -s; return s;
}
int n,m,u,v,c[maxn],head[maxn],nex[maxm],to[maxm],kkk;
#define add(x,y) nex[++kkk]=head[x]; head[x]=kkk; to[kkk]=y
int dfn[maxn],low[maxn],cnt,vis[maxn],st[maxn],top,scc[maxn],num;
int minx[maxn],miny[maxn]; ll ans,sum;
void dfs(int x){
	dfn[x]=low[x]=++cnt; st[++top]=x; vis[x]=1; int i;
	for(i=head[x];i;i=nex[i]){
		if(!dfn[to[i]]) dfs(to[i]);
		if(vis[to[i]]) low[x]=mmin(low[x],low[to[i]]);
	}
	if(dfn[x]==low[x]){
		vis[x]=0; scc[x]=++num;
		while(st[top]!=x) scc[st[top]]=num,vis[st[top]]=0,top--; top--;
	} return;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(); int i; for(i=1;i<=n;i++) c[i]=read(); m=read();
	for(i=1;i<=m;i++){ u=read(); v=read(); add(u,v); } for(i=1;i<=n;i++) if(!dfn[i]) dfs(i);
	for(i=1;i<=num;i++) minx[i]=INF; ans=0; sum=1;
	for(i=1;i<=n;i++)
		if(c[i]<minx[scc[i]]) minx[scc[i]]=c[i],miny[scc[i]]=1;
		else if(c[i]==minx[scc[i]]) miny[scc[i]]++;
	for(i=1;i<=num;i++) ans+=minx[i],sum=sum*miny[i]%MOD;
	print(ans),pc(' '),print(sum%MOD); return 0;
}