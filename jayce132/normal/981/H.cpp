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
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=(1<<18)+20;
const int MAX=1<<18;
const int mod=998244353;
inline int power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=(ll)ans*a%mod;
		b>>=1;
		a=(ll)a*a%mod;
	}
	return ans;
}

int jc[maxn],jcn[maxn],inv[maxn],W[maxn];
inline void prepare()
{
	jc[0]=jc[1]=jcn[0]=jcn[1]=inv[1]=1;
	REP(i,2,MAX)jc[i]=(ll)i*jc[i-1]%mod,inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod,jcn[i]=(ll)jcn[i-1]*inv[i]%mod;
	W[0]=1; W[1]=power(3,(mod-1)/MAX);
	REP(i,2,MAX-1)W[i]=(ll)W[i-1]*W[1]%mod;
}

inline int C(int n,int m){ return 1ll*jc[n]*jcn[m]%mod*jcn[n-m]%mod;}

inline void FFT(vector<int>&p,int n,int op)
{
	static int rev[maxn];
	int l=0;
	while(1<<l<n)l++;
	REP(i,1,n-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<l-1);
	REP(i,1,n-1)if(i<rev[i])swap(p[i],p[rev[i]]);
	for(int i=1;i<n;i<<=1)
		for(int j=0,w=(MAX/(i<<1));j<n;j+=i<<1)
			for(int k=0;k<i;k++)
			{
				int x=p[j+k],y=(ll)W[w*k]*p[i+j+k]%mod;
				p[j+k]=(x+y)%mod;
				p[i+j+k]=(x-y)%mod;
			}
	if(op==-1)
	{
		reverse(p.begin()+1,p.end());
		REP(i,0,n-1)p[i]=(ll)p[i]*inv[n]%mod;
	}
}

inline vector<int> operator *(vector<int>a,vector<int>b)
{
	int N=1,n=SZ(a)-1,m=SZ(b)-1;
	while(N<=SZ(a)+SZ(b)-2)N<<=1;
	a.resize(N); b.resize(N);
	FFT(a,N,1); FFT(b,N,1);
	REP(i,0,N-1)a[i]=(ll)a[i]*b[i]%mod;
	FFT(a,N,-1);
	a.resize(n+m+1);
	return a;
}

int n,k;
vector<int>ed[maxn];

vector<int>f[maxn];

inline void init()
{
	n=read();k=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
}

int sz[maxn];

inline void pls(int &a,int b){ a+=b; a-=a>=mod?mod:0;}
int ans=0;

vector<int> operator/(vector<int>a,int y)
{
	REP(i,1,SZ(a)-1)
	{
		a[i]=(a[i]-(ll)a[i-1]*y)%mod;
	}
	a.resize(SZ(a)-1);
	return a;
}

int fff[maxn];

void dfs(int u,int fa)
{
	sort(ed[u].begin(),ed[u].end(),[](int a,int b){return sz[a]<sz[b];});
	int lstsz=0;vector<int>F,FF=f[u]*((vector<int>){1,n-sz[u]});
	int a=0,up=0;
	for(int v:ed[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		int down=0;
		if(sz[v]!=lstsz)
		{
			F=FF/sz[v],lstsz=sz[v];
			up=0;
			REP(j,0,min(SZ(F)-1,k))up=(up+(ll)F[j]*jc[k]%mod*jcn[k-j])%mod;
		}
		down=fff[v];
		ans=(ans+(ll)up*down)%mod;
		ans=(ans+(ll)a*fff[v])%mod;
		a=(a+fff[v])%mod;
	}

	/*
	if(fa)
	{
		int ad=n-sz[u];
		REP(j,0,min(SZ(f[fa])-1,k))
		{
			int t=0;
			if(j-1>=0)t=(t+(ll)ad*f[fa][j-1])%mod;
			t=(t+(ll)(1-(ll)ad*mns%mod)*f[fa][j])%mod;
			if(j+1<SZ(f[fa]))t=(t-(ll)mns*f[fa][j])%mod;
			t=(t+mod)%mod;
			if(k-j<SZ(g[u]))ans=(ans+(ll)t*g[u][k-j])%mod;
		}
		}*/
}

vector<int> solve(vector<int>A)
{
	if(SZ(A)==0)return {1};
	if(SZ(A)==1)return {1,A.back()};
	vector<int>B,C;
	int len=SZ(A)-1>>1;
	REP(i,0,SZ(A)-1)
		if(i<=len)B.push_back(A[i]);
		else C.push_back(A[i]);
	return solve(B)*solve(C);
}

void pre_dfs(int u,int fa)
{
	vector<int>now;
	for(int v:ed[u])
	{
		if(v==fa)continue;
		pre_dfs(v,u);
		sz[u]+=sz[v];
		now.push_back(sz[v]);
	}
	sz[u]++;
	f[u]=solve(now);
	REP(j,0,min(SZ(f[u])-1,k))fff[u]=(fff[u]+(ll)f[u][j]*jc[k]%mod*jcn[k-j])%mod;
	for(int v:ed[u])if(v!=fa)fff[u]=(fff[u]+fff[v])%mod;
}

inline void doing()
{
	if(k==1)printf("%lld\n",(ll)n*(n-1)%mod*inv[2]%mod),exit(0);
	pre_dfs(1,0);
	dfs(1,0);
	ans=(ans+mod)%mod;
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("981H.in","r",stdin);
	freopen("981H.out","w",stdout);
#endif
	prepare();
	init();
	doing();
	return 0;
}