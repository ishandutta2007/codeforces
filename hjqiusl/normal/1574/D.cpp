//QwQcOrZ yyds!!!
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
//#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
//#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[15];
vector<int>W[N];
int m,x[15];
int tot;
unordered_map<int,int>son[N];
struct node
{
	int val,p[11];
	void init() {val=0,memset(p,0,sizeof(p));}
};
inline void insert()
{
	re int now=1;
	for (int i=1;i<=n;i++)
	{
		if (son[now].count(x[i]))
		{
			now=son[now][x[i]];
		} else
			son[now][x[i]]=++tot,
			now=son[now][x[i]];
	}
}
inline node checkmx(node x,node y)
{
//	node res;
	if (x.val<y.val) return y;
	return x;
}
node dfs(int k,int dep,int V)
{
	if (!k)
	{
		re node g;g.init();
		for (int i=dep+1;i<=n;i++) g.p[i]=a[i],g.val+=W[i][a[i]-1];
		g.p[dep]=V;
		g.val+=W[dep][V-1];
		return g;
	}
	if (dep==n) 
	{
		re node g;g.init();
		return g;
	}
	re node g;g.init();
	for (int i=a[dep+1];i>=1;i--)
		if (son[k].count(i))
		{
			g=checkmx(g,dfs(son[k][i],dep+1,i));
		}
		else 
		{
			g=checkmx(g,dfs(0,dep+1,i));
			break;
		}
	if (k==1) return g;
	if (g.val==0) return g;
	g.p[dep]=V;
	g.val+=W[dep][V-1];
	return g;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		for (int j=1;j<=a[i];j++) W[i].push_back(read());
	}
	m=read();
	tot=1;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)	
		{
			x[j]=read();
		}
		insert();
	}
	node ans=dfs(1,0,0);
	for (int i=1;i<=n;i++) writesp(ans.p[i]);
}
/*
2
4 1 2 3 4
2 1 2
3
4 2
4 1
3 2
*/