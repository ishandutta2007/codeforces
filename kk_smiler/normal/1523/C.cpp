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
	#define sz 1010
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

int n; int a[sz];

void work()
{
	read(n); rep(i,1,n) read(a[i]);
	stack<vector<int>>s; s.push(vector<int>());
	auto out=[&](vector<int>V){rep(i,0,(int)V.size()-2) printf("%d.",V[i]); printf("%d\n",V.back());};
	rep(i,1,n)
	{
		if (a[i]==1)
		{
			vector<int>V=s.top(); V.push_back(1); out(V);
			s.push(V); continue;
		}
		while (s.top().back()!=a[i]-1) { if (s.top().back()!=a[i]) s.pop(); else s.pop(),s.pop(); }
		vector<int>V=s.top(); ++V.back(); out(V);
		s.push(V);
	}
}

int main()
{
	file();
	int T; read(T);
	while (T--) work();
	return 0;
}