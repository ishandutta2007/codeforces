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
	il void Readstring( string &x ){
		x.clear(); char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch)  &&  ch != '#'  &&  ch != '.' ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch)  ||  ch == '#'  ||  ch == '.' ){
			x += ch;
			ch = C();
		}
	}
	il void Readchstring( char s[] ){
		int len = 0; char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch)  /*&&  ch != '*'  &&  ch != '?'*/ ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch)  /*||  ch == '*'  ||  ch == '?'*/ ){
			s[len++] = ch;
			ch = C();
		}
		s[len] = '\0';
	}
	il void Specialread( char &c ){
		c = C();
		while( !isdigit(c) && !isalpha(c) && c != '#'  &&  c != '.'  &&  c != '='  &&  c != 'B' ) c = C();
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
il void FILEIO( string pname ){
	#ifndef intLSY
		Fin((pname+".in").c_str());
		Fout((pname+".out").c_str());
	#else
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
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
constexpr int MAXN = 131072;

int n;
ll a[MAXN], prod = 1;
struct Event{
	bool isadd;
	int pos;
};
vc<Event> events_c_time[MAXN];
vc<int> e[MAXN];

int sz[MAXN], gson[MAXN], dep[MAXN], fa[MAXN];
void FindGson( int pos , int fa ){
	sz[pos] = 1;
	dep[pos] = dep[fa] + 1;
	::fa[pos] = fa;
	for( auto v : e[pos] ){
		if( v == fa ) continue;
		FindGson(v,pos);
		sz[pos] += sz[v];
		if( sz[v] > sz[gson[pos]] )
			gson[pos] = v;
	}
}
int top[MAXN];
int in[MAXN], out[MAXN], nowtime = 0, whoin[MAXN];
void LinkLine( int pos , int fa , int tp ){
	in[pos] = ++nowtime;
	whoin[nowtime] = pos;
	top[pos] = tp;
	if(gson[pos]) LinkLine(gson[pos],pos,tp);
	for( auto v : e[pos] ){
		if( v == fa or v == gson[pos] ) continue;
		LinkLine(v,pos,v);
	}
	out[pos] = nowtime;
}

class BIT{
private:
	ll di[MAXN], idi[MAXN];
	il void Add( int pos , ll x ){
		const ll idiadd = pos*x%MOD;
		for( ; pos <= n ; pos += Lowbit(pos) ){
			Addi( di[pos] , x );
			Addi( idi[pos] , idiadd );
		}
	}
	il ll Sum( int pos ){
		int opos = pos;
		ll disum = 0, idisum = 0;
		for( ; pos ; pos -= Lowbit(pos) ){
			Addi( disum , di[pos] );
			Addi( idisum , idi[pos] );
		}
		return ( (opos+1)*disum - idisum + MOD ) % MOD;
	}
public:
	il void IntervalAdd( int l , int r , ll x ){
		Add(l,+x); Add(r+1,Mymo(MOD-x));
	}
	il ll IntervalSum( int l , int r ){
		return Mymo(Sum(r)-Sum(l-1)+MOD);
	}
}bit;

void HLDInit(){
	FindGson(1,0);
	LinkLine(1,0,1);
}

void PathAdd( int pos , ll x ){
	while(pos){
		bit.IntervalAdd(in[top[pos]],in[pos],x);
		pos = fa[top[pos]];
	}
}
ll PathSum( int pos ){
	ll ans = 0;
	while(pos){
		Addi( ans , bit.IntervalSum(in[top[pos]],in[pos]) );
		pos = fa[top[pos]];
	}
	return ans;
}

// ll t[MAXN];
// void PathAdd( int pos , ll x ){
// 	while(pos){
// 		Addi( t[pos] , x );
// 		pos = fa[pos];
// 	}
// }
// ll PathSum( int pos ){
// 	ll ans = 0;
// 	while(pos){
// 		Addi( ans , t[pos] );
// 		pos = fa[pos];
// 	}
// 	return ans;
// }

ll s1, s2, s3, s4;
void AddNode( int pos ){
	Addi( s1 , dep[pos]*a[pos]%MOD );
	Addi( s2 , a[pos] );
	Addi( s3 , dep[pos]*a[pos]%MOD*a[pos]%MOD );
	Addi( s4 , a[pos]*PathSum(pos)%MOD );
	PathAdd(pos,a[pos]);
}
void DelNode( int pos ){
	Deci( s1 , dep[pos]*a[pos]%MOD );
	Deci( s2 , a[pos] );
	Deci( s3 , dep[pos]*a[pos]%MOD*a[pos]%MOD );
	PathAdd(pos,MOD-a[pos]);
	Deci( s4 , a[pos]*PathSum(pos)%MOD );
}
ll GetAns(){
	ll ans = prod * (s1*s2%MOD-s3-2*s4+3LL*MOD) % MOD;
	// P(prod,s1,s2,s3,s4,ans);
	return ans;
}

ll Solve(){
	ll ans = 0;
	For(i,100000){
		for( auto event : events_c_time[i] ){
			if(event.isadd) AddNode(event.pos);
			else DelNode(event.pos);
		}
		ll tans = GetAns();
		// O(tans);
		Addi( ans , tans );
	}
	return ans;
}

int main(){
	FILEIO();

	Read(n);
	For(i,n){
		iRead2(l,r);
		a[i] = Inv(r-l+1);
		Muli( prod , (r-l+1) );
		events_c_time[l].Pb({1,i});
		events_c_time[r+1].Pb({0,i});
	}
	For(i,n-1){
		iRead2(a,b);
		e[a].Eb(b);
		e[b].Eb(a);
	}

	HLDInit();
	ll ans = Solve();
	cout << ans << endl;

	END();
}