#include<bits/stdc++.h>
namespace my_std{
	using namespace std;
	#define pii pair<int,int>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define templ template<typename T>
	#define sz 121
	typedef long long ll;
	typedef double db;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	templ inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
	templ inline bool chkmax(T &x,T y){return x<y?x=y,1:0;}
	templ inline bool chkmin(T &x,T y){return x>y?x=y,1:0;}
	templ inline void read(T& t)
	{
		t=0;char f=0,ch=getchar();double d=0.1;
		while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
		while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
		if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
		t=(f?-t:t);
	}
	template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
	char __sr[1<<21],__z[20];int __C=-1,__zz=0;
	inline void Ot(){fwrite(__sr,1,__C+1,stdout),__C=-1;}
	inline void print(int x)
	{
		if(__C>1<<20)Ot();if(x<0)__sr[++__C]='-',x=-x;
		while(__z[++__zz]=x%10+48,x/=10);
		while(__sr[++__C]=__z[__zz],--__zz);__sr[++__C]='\n';
	}
	void file()
	{
		#ifdef NTFOrz
		freopen("a.in","r",stdin);
		#endif
	}
	inline void chktime()
	{
		#ifdef NTFOrz
		cerr<<clock()/1000.0<<'\n';
		#endif
	}
	#ifdef mod
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
	ll inv(ll x){return ksm(x,mod-2);}
	#else
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
	#endif
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,m;
ll X[sz],Y[sz],T[sz];
ll dd(int i,int j){return abs(X[i]-X[j])+abs(Y[i]-Y[j]);}

ll f[1<<14][sz],dis[1<<14][sz]; int g[1<<14][sz];

int main()
{
	file();
	read(n,m);
	rep(i,0,n-1) read(X[i+m],Y[i+m]);
	{
		static pair<int,pii> P[sz];
		rep(i,0,m-1) read(P[i].sec.fir,P[i].sec.sec,P[i].fir);
		sort(P,P+m);
		rep(i,0,m-1) T[i]=P[i].fir,tie(X[i],Y[i])=P[i].sec;
	}
	int S=1<<n;
	rep(s,1,S-1) rep(i,0,n+m-1) { ll w=1e10; rep(k,0,n-1) if (s>>k&1) chkmin(w,dd(i,k+m)); dis[s][i]=w; }
	memset(f,0x3f,sizeof(f)); memset(g,-1,sizeof(g));
	rep(i,0,n-1) f[1<<i][0]=0; rep(i,0,m-1) g[0][i]=1;
	rep(s,0,S-1)
	{
		int p=0,q=0;
		auto work1=[&](int i)
		{
			if (g[s][i]>=0&&s) chkmin(f[s][g[s][i]],T[i]);
			if (g[s][i]>=0)
			{
				rep(j,i+1,m-1) if (dd(i,j)<=T[j]-T[i]) chkmax(g[s][j],g[s][i]+1);
				rep(j,0,n-1) if (!(s>>j&1)) chkmin(f[1<<j|s][g[s][i]],T[i]+dd(i,j+m));
			}
		};
		auto work2=[&](int i)
		{
			if (!s||f[s][i]>1e9) return;
			rep(j,i,m-1) if (dis[s][j]<=T[j]-f[s][i]) chkmax(g[s][j],i+1);
			rep(j,0,n-1) if (!(s>>j&1)) chkmin(f[1<<j|s][i],f[s][i]+dis[s][j+m]);
		};
		while (p<m&&q<m) { rep(i,p+1,m-1) if (f[s][i]<=f[s][p]) p=i; if (f[s][p]<T[q]) work2(p),++p; else work1(q),++q; }
		while (p<m) work2(p),++p; while (q<m) work1(q),++q;
	}
	int ans=0;
	rep(s,0,S-1) rep(i,0,m-1) chkmax(ans,g[s][i]);
	cout<<ans;
	return 0;
}