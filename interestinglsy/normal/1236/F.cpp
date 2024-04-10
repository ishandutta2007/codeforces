// InterestingLSY
// 2659723130
// 
#ifdef intLSY
#include <intlsy/stdc++.h>
#else
#include <bits/stdc++.h>
#endif
#include <bits/c++0x_warning.h>
using namespace std;
#define il inline
#define elif else if

// Type
#define ld double
#define ll long long
#define ull unsigned ll

// Vector
#define vc vector
#define Pb push_back
#define Pf push_front
#define Eb emplace_back
#define All(x) x.begin(),x.end()
#define AllRev(x) x.rbegin(),x.rend()

// Memory
#define Ms(_data) memset(_data,0,sizeof(_data))
#define Msn(_data,_num) memset(_data,_num,sizeof(_data))

// Template
#define _cl class
#define _tp template
#define _tyn typename

// Pair
#define Mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>

// Loop
#define For(i,j) for( int (i) = 1 ; (i) <= (j) ; ++(i) )
#define For0(i,j) for( int (i) = 0 ; (i) < (j) ; ++(i) )
#define Forx(i,j,k) for( int (i) = (j) ; (i) <= (k) ; ++(i) )
#define Forstep(i,j,k,st) for( int (i) = (j) ; (i) <= (k) ; (i) += (st) )
#define fOR(i,j) for( int (i) = (j) ; (i) >= 1 ; --(i) )
#define fOR0(i,j) for( int (i) = (j)-1 ; (i) >= 0 ; --(i) )
#define fORx(i,j,k) for( int (i) = (k) ; (i) >= (j) ; --(i) )

// Read
struct InputReader{
	#define bs 1048576
	char buf[bs]; int p;
	il InputReader(){ p = bs; }
	il void Flush(){ p = 0; fread(buf,1,bs,stdin); }
	il char C(){ if(p >= bs) Flush(); return buf[p++]; }
	il char Readnum(){ char ch = C(); while( !isdigit(ch) && ch != '-' ) ch = C(); return ch; }
	il void Readalpha( char &c ){ c = C(); while( !isalpha(c) ) c = C(); }
	int operator() (){
		int ans = 0, fu = 1; char ch = Readnum();
		if( ch == '-' ) fu = -1, ch = C();
		while( ch >= '0' && ch <= '9' ){
			ans = ans*10 + ch-'0';
			ch = C();
		}
		return ans * fu;
	}
	ll Readll(){
		ll ans = 0LL, fu = 1LL; char ch = Readnum();
		if( ch == '-' ) fu = -1LL, ch = C();
		while( ch >= '0' && ch <= '9' ){
			ans = ans*10LL + ch-'0';
			ch = C();
		}
		return ans * fu;
	}
	#undef bs
}In;
il void Read( int &x ){ x = In(); }
il void Read( int &x, int &y ){ x = In(); y = In(); }
il void Read( int &x1 , int &x2 , int &x3 ){ x1 = In(); x2 = In(); x3 = In(); }
il void Read( int &x1 , int &x2 , int &x3 , int &x4 ){ x1 = In(); x2 = In(); x3 = In(); x4 = In(); }
il void Read( ll &x ){ x = In.Readll(); }
il void Read( ll &x, ll &y ){ x = In.Readll(); y = In.Readll(); }
il void Read( ll &x1 , ll &x2 , ll &x3 ){ x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); }
il void Read( ll &x1 , ll &x2 , ll &x3 , ll &x4 ){ x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); x4 = In.Readll(); }
_tp<_tyn T> void Read( T a[] , int st , int ed ){ Forx(i,st,ed) Read(a[i]); }
#define iRead(k) int k; Read(k);
#define iRead2(a,b) iRead(a); iRead(b);
#define iRead3(a,b,c) iRead2(a,b); iRead(c);
#define iRead4(a,b,c,d) iRead2(a,b); iRead2(c,d);
#define lRead(k) ll k; Read(k);
#define lRead2(a,b) lRead(a); lRead(b);
#define lRead3(a,b,c) lRead2(a,b); lRead(c);
#define lRead4(a,b,c,d) lRead2(a,b); lRead2(c,d);
// File
#define Fin(a) freopen(a,"r",stdin)
#define Fout(a) freopen(a,"w",stdout)
il void FILEIO(){
	#ifdef intLSY
		Fin("in.in");
	#endif
}
il void FILEIO_OICONTEST( string pname ){
	Fin((pname+".in").c_str());
	#ifndef intLSY
		Fout((pname+".out").c_str());
	#endif
}
void Printtime(){
	#ifdef intLSY
		double _timeuse = clock()* 1000.0 / CLOCKS_PER_SEC;
		fprintf(stderr,"\n\nTime usage:\n%.0lf ms\n",_timeuse);
	#endif
}
void END(){ Printtime(); exit(0); }
_tp<_tyn T>void END( T mes ){ cout << mes << endl; END(); }

// Debug
#define B cerr << "BreakPoint" << endl;
#define O(x) cerr << #x << " " << (x) << endl;
#define o(x) cerr << #x << " " << (x) << "  ";
#if __cplusplus >= 201703L
template<typename T, typename... Ts>
void P( T t0 , Ts... ts ){
	cerr << t0 << " ";
	if constexpr(sizeof...(ts)>0) P(ts...);
	else cerr << endl;
}
#else
template<typename T, typename... Ts>
void P( T t0 , Ts... ts ){
	// I love cpp17.
	// Fuck you.
}
#endif
#define Msz(x) cerr << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
_tp<_tyn T>void Print( T a[] , int s , int t , char sp = ' ' , char ed = '\n' ){
	if( s > t ) return;
	for( int i = s ; i < t ; i++ )
		cout << a[i] << sp;
	cout << a[t] << ed;
	cout.flush();
}
_tp<_tyn T>void Print( T a , int s = 0 , int t = -1 , char sp = ' ' , char ed = '\n' ){
	if( t == -1 ) t = a.size()-1;
	for( int i = s ; i <= t ; i++ )
		cout << a[i] << sp;
	cout << ed;
	cout.flush();
}

// Optimize
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define Mymax(a,b) (a) = max((a),(b))
#define Mymin(a,b) (a) = min((a),(b))
#define MyMax(a,b) (a) = Max((a),(b))
#define MyMin(a,b) (a) = Min((a),(b))
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
#define Sqr(x) ((x)*(x))
#define Lowbit(a) ((a)&(-(a)))
vc<int> Range( int l , int r ){
	vc<int> ret{};
	Forx(i,l,r) ret.Pb(i);
	return ret;
}
mt19937 Rand(0xe38195e38293);	// 
constexpr int MOD = 1000000007;
#define Rmoi(a,b) (((a)%b+b)%b)
#define Rmo(a) (((a)%MOD+MOD)%MOD)
#define Rmod(a) a = ((a%MOD+MOD)%MOD)
#define Rmodi(a,b) a = ((a%(b)+(b))%(b))
#define Mymoi(a,b) ((a)>=b?((a)-b):(a))
#define Mymodi(a,b) a = ((a)>=(b))?((a)-(b)):(a)
template<typename T>
il T Mymo( const T &x ){ return x >= MOD ? x-MOD : x; }
template<typename T>
il void Mymod( T &x ){ x = x >= MOD ? x-MOD : x; }
template<typename T1, typename T2>
il void Addi( T1 &x , const T2 &y ){ x = Mymo(x+y); }
template<typename T1, typename T2>
il void Deci( T1 &x , const T2 &y ){ x = Mymo(x-y+MOD); }
template<typename T1, typename T2>
il void Muli( T1 &x , const T2 &y ){ x = 1LL*x*y%MOD; }
il ll Pow( ll a , ll b , const ll p = MOD ){
	ll ret = 1;
	for( ; b ; a = a*a%p, b >>= 1LL )
		if(b&1LL) ret = ret*a%p;
	return ret;
}
il ll Inv( ll a , const ll p = MOD ){ return Pow(a,p-2LL,p); }
#include <functional>
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
constexpr int MAXN = 524288;
const ll inv2 = Inv(2);
const ll inv4 = Inv(4);

int n,m;
vc<int> e[MAXN];
vc<pii> edges;
int deg[MAXN];

struct Cycle{
	int len;
	vc<int> nodes;
};
vc<Cycle> cycles;

vc<int> cycle_lens;
ll s6[MAXN];
void InitCyclesInfo(){
	static int dep[MAXN];
	static int fat[MAXN];
	function<void(int,int)> Dfs = [&]( int pos , int fa ){
		dep[pos] = dep[fa] + 1;
		fat[pos] = fa;
		for( auto v : e[pos] ){
			if( v == fa ) continue;
			if(!dep[v])
				Dfs(v,pos);
			else if( dep[v] > dep[pos] ){
				int cyclen = dep[v]-dep[pos]+1;
				cycle_lens.Pb(cyclen);

				Cycle cyc; cyc.nodes.clear();

				ll s6_addi = Pow(inv2,cyclen);
				for( int w = v ; w != fat[pos] ; w = fat[w] ){
					Addi( s6[w] , s6_addi );
					cyc.nodes.Pb(w);
				}

				cyc.len = cyc.nodes.size();
				cycles.Pb(cyc);
			}
		}
	};
	Dfs(1,0);
	// Print(cycle_lens);
}

ll F1(){
	return n*Inv(2) % MOD;
}

ll F2(){
	return m*Inv(4) % MOD;
}

ll F3(){
	ll ans = 0;
	for( auto cyclen : cycle_lens ){
		ll p = Pow(inv2,cyclen);
		Addi( ans , p );
	}
	return ans;
}

ll F4(){
	ll ans = 0;
	For(i,n){
		Addi( ans , inv2*inv2%MOD*(n-1)%MOD );
		Addi( ans , inv2 );
	}
	return ans;
}

ll F5(){
	ll ans = 0;
	for( auto [f,t] : edges ){
		int surround = deg[f]-1+deg[t]-1;
		Addi( ans , inv4*inv2%MOD*surround%MOD );
		Addi( ans , inv4*inv4%MOD*(m-surround-1)%MOD );
		Addi( ans , inv4 );
	}
	return ans;
}

ll F6(){
	ll ans = 0;
	ll tots = 0;
	for( auto cyclen : cycle_lens )
		Addi( tots , Pow(inv2,cyclen) );
	for( auto cyc : cycles ){
		ll s = 0;
		for( auto u : cyc.nodes ){
			Addi( s , Mymo(s6[u]-Pow(inv2,cyc.len)+MOD) );
		}
		Addi( ans , Pow(inv2,cyc.len) );
		Addi( ans , Pow(inv2,cyc.len-1)*s%MOD );
		Addi( ans , Pow(inv2,cyc.len)*(tots-s-Pow(inv2,cyc.len)+MOD+MOD)%MOD );
	}
	// P(ans,Inv(8));
	return ans;
}

ll F7(){
	ll tots = 0;
	for( auto cyclen : cycle_lens )
		Addi( tots , Pow(inv2,cyclen) );
	ll ans = 0;
	For(i,n){
		Addi( ans , s6[i] );
		Addi( ans , inv2*(tots-s6[i]+MOD)%MOD );
	}
	// P(ans,Inv(8)*3%MOD);
	return ans;
}

ll F8(){
	ll ans = 0;
	For(i,n){
		int surround = deg[i];
		Addi( ans , inv2*inv2%MOD*surround%MOD );
		Addi( ans , inv2*inv4%MOD*(m-surround)%MOD );
	}
	return ans;
}

ll F9(){
	ll ans = 0;
	for( auto cyc : cycles ){
		Addi( ans , cyc.len*Pow(inv2,cyc.len)%MOD );
		int degsum = 0;
		for( auto u : cyc.nodes )
			degsum += deg[u]-2;
		Addi( ans , inv2*Pow(inv2,cyc.len)%MOD*degsum%MOD );
		Addi( ans , inv4*Pow(inv2,cyc.len)%MOD*(m-cyc.len-degsum)%MOD );
	}
	// P(ans,3*Inv(8)%MOD);
	return ans;
}

ll E1(){
	ll f1 = F1();
	ll f2 = F2();
	ll f3 = F3();
	ll ans = f1-f2+f3;
	Rmod(ans);
	return ans;
}

ll E2(){
	ll f4 = F4();
	ll f5 = F5();
	ll f6 = F6();
	ll f7 = F7();
	ll f8 = F8();
	ll f9 = F9();
	ll ans = f4 + f5 + f6 + 2*f7 - 2*f8 - 2*f9;
	Rmod(ans);
	return ans;
}

ll Solve(){
	ll e1 = E1();
	ll e2 = E2();
	ll ans = e2-e1*e1;
	Rmod(ans);
	return ans;
}

int main(){
	FILEIO();

	Read(n,m);
	For(i,m){
		iRead2(a,b);
		e[a].Eb(b);
		e[b].Eb(a);
		edges.Pb({a,b});
		++deg[a];
		++deg[b];
	}

	InitCyclesInfo();

	ll ans = Solve();
	cout << ans << endl;

	END();
}