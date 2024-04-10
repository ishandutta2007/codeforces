#include <functional>
#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <iomanip>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <set>
#include <map>
using namespace std;
#define il inline
#define rg register
#define elif else if

// Type
#define ld double
#define ll long long
#define ull unsigned ll

// Vector
#define vc vector
#define Pb push_back
#define Pf push_front
#define All(x) x.begin(),x.end()

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

// Read
struct InputReader{
	#define bs 1000001
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
		while( !isdigit(ch)  &&  !isalpha(ch)  &&  ch != '-'  &&  ch != '.' ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch)  ||  ch == '-'  ||  ch == '.' ){
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
	il void Specialread( char &c ){ c = C();
		while( c != '>'  &&  c != '<'  &&  c != '='  &&  c != 'B' ) c = C();
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
	Fin((pname+".in").c_str());
	#ifndef intLSY
		Fout((pname+".out").c_str());
	#endif
}
void Printtime(){
	#ifdef intLSY
		double _timeuse = clock()* 1000.0 / CLOCKS_PER_SEC;
		printf("\n\nTime usage:\n%.0lf ms\n",_timeuse);
	#endif
}
void END(){ Printtime(); exit(0); }
_tp<_tyn T>void END( T mes ){ cout << mes << endl; END(); }


// Loop
#define For(i,j) for( rg int (i) = 1 ; (i) <= (j) ; ++(i) )
#define For0(i,j) for( rg int (i) = 0 ; (i) < (j) ; ++(i) )
#define Forx(i,j,k) for( rg int (i) = (j) ; (i) <= (k) ; ++(i) )
#define Forstep(i,j,k,st) for( rg int (i) = (j) ; (i) <= (k) ; (i) += (st) )
#define fOR(i,j) for( rg int (i) = (j) ; (i) >= 1 ; --(i) )
#define fOR0(i,j) for( rg int (i) = (j)-1 ; (i) >= 0 ; --(i) )
#define fORx(i,j,k) for( rg int (i) = (k) ; (i) >= (j) ; --(i) )


// Debug
#define B cout << "BreakPoint" << endl;
#define O(x) cout << #x << " " << x << endl;
#define O_(x) cout << #x << " " << x << "  ";
#define ERR(x) cout << "ERR! #" << x << endl;
#define Msz(x) cout << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
using namespace std;
_tp<_tyn T>void Print( T _a[] , int _s , int _t ){
	for( int i = _s ; i <= _t ; i++ )
		cout << _a[i] << " ";
	cout << endl;
}


// Optimize
#define abs(a) ((a)<0?(~(a)+1):(a))
//#define max(a,b) ((a)>(b)?(a):(b))
//#define min(a,b) ((a)<(b)?(a):(b))
//#define swap(a,b) {a=a^b;b=a^b;a=a^b;}
#define Mymax(a,b) (a) = max((a),(b))
#define Mymin(a,b) (a) = min((a),(b))


// Random
//#define USEMT
#ifdef USEMT
	#undef min
	#undef max
	#undef abs
	#undef il
	#include <chrono>
	#include <random>
	mt19937 rng;
	#define Srand() rng = mt19937(chrono::steady_clock::now().time_since_epoch().count())
	#define Rand(i) (uniform_int_distribution<int>(1,i)(rng))
	#define Randr(i,j) (uniform_int_distribution<int>(i,j)(rng))
#else
	#define Srand() srand(time(0)*(ull)(new char))
	#define Rand(i) ((1LL*rand()*rand()%(i)+(i))%(i)+1)
	#define Randr(i,j) (Rand(j-i+1)+i-1)
#endif


// Datagenerating
namespace Datagenerating{
	string Tostring( int a ){
		string ret;
		while(a){ ret += a%10+'0'; a /= 10; }
		reverse(All(ret));
		return ret;
	}
	int Toint( string s ){
		int len = s.length();
		int a = 0;
		For0(i,len){ a *= 10; a += s[i]-'0'; }
		return a;
	}
	int Randneq( int lim , int neq ){
		int ret = neq;
		while( ret == neq ) ret = Rand(lim);
		return ret;
	}
	int Randrneq( int a , int b , int neq ){
		int ret = neq;
		while( ret == neq ) ret = Randr(a,b);
		return ret;
	}
}


#define Handwriterandom
#ifdef Handwriterandom
	#undef Rand
	#undef Randr
	#undef Srand
	int sed = 0;
	il void Srand(){ srand(time(0)*(ull)(new char)); sed = rand(); }
	il int Rand(){ return sed = (sed*sed*73+sed*233+19260817) & 0x00ffffff; }
#endif


// Graph
namespace Graph{
	struct Dsu{
		#define DSU 1000010
		int dsu[DSU];
		void Init( int n ){ Forx(i,0,n) dsu[i] = i; }
		int Findfa( int pos ){ return dsu[pos]==pos ? pos : dsu[pos]=Findfa(dsu[pos]); }
		int operator[]( int pos ){ return Findfa(pos); }
		bool Same( int a , int b ){ return Findfa(a) == Findfa(b); }
		bool Unite( int a , int b ){ return (a=Findfa(a))==(b=Findfa(b)) ? 0 : (dsu[a]=b,1); }
	};
	struct E{
		int f,t; int c;
		E(){}
		E( int fi , int ti , int ci ){ f = fi; t = ti; c = ci; }
		bool operator<( E b ){ return c > b.c; }
	};
	struct Edge{
		int to; ll cost;
		Edge(){}
		Edge( int ti , ll ci ){ to = ti; cost = ci; }
	};
}
//#define USEPBDS
#ifdef USEPBDS
	#undef max
	#undef min
	#undef swap
	#include <ext/pb_ds/priority_queue.hpp>
#endif
int dx4[] = {0,-1,0,1};
int dy4[] = {1,0,-1,0};
// R U L D
// E N W S
//int dx4[] = {-1,1,0,0};
//int dy4[] = {0,0,-1,1};
int dx8[] = {0,1,1,1,0,-1,-1,-1};
int dy8[] = {1,-1,0,1,-1,-1,0,1};


// Maths
ll p;
#define MOD (1000000007)
#define Eps (1e-7)
#define Sqr(x) ((x)*(x))
#define Rmoi(a,b) ((a)%b+b)%b
#define Rmo(a) ((a)%MOD+MOD)%MOD
#define Rmod(a) a = (a%MOD+MOD)%MOD
#define Rmodi(a,b) a = (a%(b)+(b))%(b)
#define Mymoi(a,b) ((a)>=b?((a)-b):(a))
#define Mymo(a) ((a)>=MOD?((a)-MOD):(a))
#define Mymod(a) a = (a)>=MOD?((a)-MOD):(a)
#define Mymodi(a,b) a = ((a)>=(b))?((a)-(b)):(a)
#define Mdis(x1,y1,x2,y2) (abs(x1-x2)+abs(y1-y2))
#define Edis(x1,y1,x2,y2) (sqrt(Edis2(x1,y1,x2,y2)))
#define Edis2(x1,y1,x2,y2) (Sqr((x1)-(x2))+Sqr((y1)-(y2)))
#define INF (0x3f3f3f3f)
#define FINF ((ld)(1000000000))
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
namespace Maths{
	_tp<_tyn T>T Gcd( T a , T b ){ return b?Gcd(b,a%b):a; }
	il ll Pow( rg ll a , rg ll b ){
		rg ll ret = 1;
		for( ; b ; (a*=a)%=MOD, b >>= 1LL )
			if(b&1LL) (ret*=a) %= MOD;
		return ret;
	}
	ll Inv( ll a ){ return Pow(a,MOD-2LL); }
	ll Frac( ll x ){
		ll ret = 1;
		For(i,x) ret = ret*i % MOD;
		return ret;
	}
}


// Data structure
namespace Datastructure{
	_tp<_cl T>struct Bit{
		#define BIT 1000010
		#define Lowbit(x) ((x)&(~(x)+1))
		//#define BITMOD
		T tree[BIT];
		Bit(){ Ms(tree); }
		void Add( rg int pos , rg T x ){
			for( ; pos < BIT ; pos += Lowbit(pos) ){
				tree[pos] += x;
				#ifdef BITMOD
					Mymod(tree[pos]);
				#endif
			}
		}
		T Sum( rg int pos ){
			rg T ret = 0;
			for( ; pos ; pos -= Lowbit(pos) ){
				ret += tree[pos];
				#ifdef BITMOD
					Mymod(ret);
				#endif
			}
			return ret;
		}
		T Sum( rg int l , rg int r ){
			#ifdef BITMOD
				return Rmo(Sum(r) - Sum(l-1));
			#else
				return Sum(r) - Sum(l-1);
			#endif
		}
	};
}


// NetworkFlow
namespace Networkflow{
	#define NET 50013
	int S = NET-2;
	int T = NET-1;
	int HUBS = NET-4;
 	int HUBT = NET-3;
	struct Edge{
		int to,rev,id; ll cap; int cost;
		Edge(){}
		Edge( int ti , ll ci , int ri , int coi , int iid = -2333333 ){
			to = ti; cap = ci; rev = ri; cost = coi; id = iid;
		}
	};
	vc<Edge> e[NET];
	il void Link( int f , int t , ll c , int co = 0 , int id = -2333333 ){
		//cout << f << " " << t << " " << c << endl;
		e[f].Pb( Edge( t , c , e[t].size() , co , id ) );
		e[t].Pb( Edge( f , 0 , e[f].size()-1 , -co , id==-2333333?id:-id ) );
	}
	int in[NET], out[NET];
	il void Links( int a , int b , ll lower , ll upper , int id = 0 ){
		if(id) Link(a,b,upper-lower,0,id); else Link(a,b,upper-lower);
		in[b] += lower; out[a] += lower;
	}
	il int Smooth(){
		rg int tot = 0;
		For(i,NET-1){
			if( in[i] > out[i] ){ Link(S,i,in[i]-out[i]); tot += in[i]-out[i]; }
			elif( in[i] < out[i] ){ Link(i,T,out[i]-in[i]); }
		}
		return tot;
	}
	void Cleargraph(){ Ms(in); Ms(out); For0(i,NET) e[i].clear(); }

	int lev[NET];
	queue<int> q;
	bool Bfs(){
		Msn(lev,-1);
		q.push(S); lev[S] = 1;
		while(!q.empty()){
			int u = q.front(); q.pop();
			For0(i,e[u].size()){
				int v = e[u][i].to;
				if( ~lev[v] || !e[u][i].cap ) continue;
				lev[v] = lev[u]+1; q.push(v);
			}
		}
		return ~lev[T];
	}
	ll Dfs( int pos , ll flow ){
		if( pos == T ) return flow;
		ll used = 0;
		For0(i,e[pos].size()){
			int v = e[pos][i].to; ll co = e[pos][i].cap;
			if( lev[v] != lev[pos]+1 || !co ) continue;
			ll w = Dfs(v,min(flow - used,co));
			if(w){
				e[pos][i].cap -= w;
				e[v][e[pos][i].rev].cap += w;
				used += w;
			}
			if( used == flow ) break;
		}
		if(!used) lev[pos] = -1;
		return used;
	}
	ll Dinic(){
		rg ll ans = 0;
		while(Bfs()) ans += Dfs(S,INF);
		return ans;
	}

	ll dis[NET];
	bool inque[NET];
	int prevdot[NET], prevedge[NET];
	#define PREV(u) e[prevdot[u]][prevedge[u]]
	bool Spfa(){
		For0(i,NET) dis[i] = LINF;//O(dis[1]);
		Ms(inque); q.push(S);
		dis[S] = 0; inque[S] = 1;
		while(!q.empty()){
			int u = q.front(); q.pop();
			inque[u] = 0;
			For0(i,e[u].size()){
				Edge nowe = e[u][i];
				if( nowe.cap <= 0 ) continue;
				int v = nowe.to;
				if( dis[v] > dis[u] + nowe.cost ){
					dis[v] = dis[u] + nowe.cost;
					prevdot[v] = u; prevedge[v] = i;
					if(!inque[v]){ inque[v] = 1; q.push(v); }
				}
			}
		}
		return dis[T] != LINF;
	}
	ll Refresh(){
		int u = T;
		ll flow = LINF;
		while( u != S ){ Mymin(flow,PREV(u).cap); u = prevdot[u]; }
		u = T;
		while( u != S ){
			PREV(u).cap -= flow;
			e[u][PREV(u).rev].cap += flow;
			u = prevdot[u];
		}
		return flow;
	}
	#define pdi pair<ld,int>
	#define pdd pair<ld,ld>
	pll Mincostflow(){
		ll ans = 0; ld flow = 0;
		while(Spfa()){
			ll tflow = Refresh();
			ll tans = tflow * dis[T];
			ans += tans; flow += tflow;
		}
		return Mp(ans,flow);
	}
	#undef PREV
}


// Bitset
#define Bit(mask,pos) ((mask)>>(pos)-1&1)
#define Set1(mask,pos) ((1<<(pos)-1)|(mask))
#define Set0(mask,pos) ((1<<(pos)-1)^(mask))
int Len( int a ){
	int ret = 0;
	while(a){ a >>= 1; ret++; }
	return ret;
}


// Computation geometry
namespace Geometry{
	_tp<_cl T>struct Point{
		T x,y;
		Point(){ x = y = 0; }
		Point( T ai , T bi ){ x = ai; y = bi; }
		T norm2(){ return Sqr(x) + Sqr(y); }
		ld norm(){ return sqrt(norm2()); }
		void Print(){ cout << x << " " << y << endl; }
		Point operator+( Point<T> v ){ return Point(x+v.x,y+v.y); }
		Point operator-( Point<T> v ){ return Point(x-v.x,y-v.y); }
		T operator*( Point<T> v ){ return x*v.y - y*v.x; }
		T Dis2( Point<T> v ){ return (v-*this).norm2(); }
		ld Dis( Point<T> v ){ return sqrt(Dis2(v)); }
		bool operator!=( Point<T> v ){ return x!=v.x || y!=v.y; }
		bool operator<( Point<T> v )const{ return x!=v.x ? x<v.x : y<v.y; }
	};
	_tp<_tyn T>bool Turnright( Point<T> a , Point<T> b , Point<T> c ){
		return (c-b) * (b-a) > 0;
	}
	bool Turnrightf( Point<ld> a , Point<ld> b , Point<ld> c ){
		return (c-b) * (b-a) > Eps;
	}
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
ll n,k;
ll Upper( ll a , ll b ){
	return a%b ? a/b+1 : a/b;
}

int main(){
	FILEIO();

	cin >> n >> k;
	ll ans = Upper(n*2,k) + Upper(n*5,k) + Upper(n*8,k);
	cout << ans << endl;

	return 0;
}