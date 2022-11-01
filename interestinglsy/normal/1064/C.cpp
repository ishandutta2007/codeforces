#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#define F first
#define S second
#define vc vector
#define ld double
#define _cl class
#define Pb push_back
#define Mp make_pair
#define ll long long
#define _tp template
#define _tyn typename
#define Pf push_front
#define ull unsigned ll
#define INF (0x3f3f3f3f)
#define Sqr(x) ((x)*(x))
#define pii pair<int,int>
#define All(x) x.begin(),x.end()
#define Fin(a) freopen(a,"r",stdin)
#define Fout(a) freopen(a,"w",stdout)
#define B cout << "BreakPoint" << endl;
#define O(x) cout << #x << " " << x << endl;
#define O_(x) cout << #x << " " << x << "  ";
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
#define Ms(_data) memset(_data,0,sizeof(_data))
#define Msn(_data,_num) memset(_data,_num,sizeof(_data))
using namespace std;
#define Mymax(a,b) (a) = max((a),(b))
#define Mymin(a,b) (a) = min((a),(b))
_tp<_tyn T>void Print( T _a[] , int _s , int _t ){
	for( int i = _s ; i <= _t ; i++ )
		cout << _a[i] << " ";
	cout << endl;
}
#define il inline
#define rg register
struct InputReader{
	static const int bs = 1000001;
	char buf[bs]; int p;
	il InputReader():p(bs) {}
	il void Flush(){
		p = 0;
		fread(buf, 1, bs, stdin);
	}
	il char C(){
		if(p >= bs) Flush();
		return buf[p++];
	}
	il int Getnum(){
		char ch = C();
		while( ch < '0'  ||  ch > '9' ) ch = C();
		return (int)(ch-'0');
	}
	int operator() (){
		int ans = 0, fu = 1;
		char ch = C();
		while( ch < '0'  ||  ch > '9' ){
			if( ch == '-' ) fu = -1;
			ch = C();
		}
		while( ch >= '0'  &&  ch <= '9' ){
			ans = ans*10 + ch-'0';
			ch = C();
		}
		return ans * fu;
	}
	ll Readll(){
		ll ans = 0LL, fu = 1LL;
		char ch = C();
		while( ch < '0'  ||  ch > '9' ){
			if( ch == '-' ) fu = -1LL;
			ch = C();
		}
		while( ch >= '0'  &&  ch <= '9' ){
			ans = ans*10LL + ch-'0';
			ch = C();
		}
		return ans * fu;
	}
	il void Readstring( string &x ){
		x.clear();
		char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch)  &&  ch != '_'  &&  ch != '.' ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch)  ||  ch == '_'  ||  ch == '.' ){
			x += ch;
			ch = C();
		}
	}
	il void Readchstring( char s[] ){
		int len = 0;
		char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch)  /*&&  ch != '*'  &&  ch != '?'*/ ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch)  /*||  ch == '*'  ||  ch == '?'*/ ){
			s[len++] = ch;
			ch = C();
		}
		s[len] = '\0';
	}
	il void Readalpha( char &c ){
		c = C();
		while( !isalpha(c) ) c = C();
	}
	il void Specialread( char &c ){
		c = C();
		while( c != '.'  &&  c != 'W'  &&  c != 'A'  &&  c != 'B' ) c = C();
	}
}In;
il void Read( int &x ){ x = In(); }
il void Read( int &x, int &y ){ x = In(); y = In(); }
il void Read( int &x1 , int &x2 , int &x3 ){
	x1 = In(); x2 = In(); x3 = In();
}
il void Read( int &x1 , int &x2 , int &x3 , int &x4 ){
	x1 = In(); x2 = In(); x3 = In(); x4 = In();
}
il void Read( ll &x ){ x = In.Readll(); }
il void Read( ll &x, ll &y ){ x = In.Readll(); y = In.Readll(); }
il void Read( ll &x1 , ll &x2 , ll &x3 ){
	x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll();
}
il void Read( ll &x1 , ll &x2 , ll &x3 , ll &x4 ){
	x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); x4 = In.Readll();
}
#define iRead(k) int k; Read(k);
#define iRead2(a,b) iRead(a); iRead(b);
#define iRead3(a,b,c) iRead2(a,b); iRead(c);
#define iRead4(a,b,c,d) iRead2(a,b); iRead2(c,d);
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
void END(){
	Printtime();
	exit(0);
}
_tp<_tyn T>void END( T mes ){
	cout << mes << endl;
	END();
}
#define For(i,j) for( rg int (i) = 1 ; (i) <= (j) ; ++(i) )
#define For0(i,j) for( rg int (i) = 0 ; (i) < (j) ; ++(i) )
#define Forx(i,j,k) for( rg int (i) = (j) ; (i) <= (k) ; ++(i) )
#define Forstep(i,j,k,st) for( rg int (i) = (j) ; (i) <= (k) ; (i) += (st) )
#define fOR(i,j) for( rg int (i) = (j) ; (i) >= 1 ; --(i) )
#define fOR0(i,j) for( rg int (i) = (j)-1 ; (i) >= 0 ; --(i) )
#define fORx(i,j,k) for( rg int (i) = (k) ; (i) >= (j) ; --(i) )
// int dx4[] = {0,-1,0,1};
// int dy4[] = {1,0,-1,0};
int dx4[] = {-1,1,0,0};
int dy4[] = {0,0,-1,1};
int dx8[] = {0,1,1,1,0,-1,-1,-1};
int dy8[] = {1,-1,0,1,-1,-1,0,1};
#define ERR(x) cout << "ERR! #" << x << endl
#define Msz(x) cout << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
// Optimize
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define swap(a,b) {a=a^b;b=a^b;a=a^b;}
#define abs(a) ((a)<0?-(a):(a))
#define Fu(a) (~(a) + 1)
// Maths
#define MOD 233
#define Rmoi(a,b) ((a)%b+b)%b
#define Rmo(a) ((a)%MOD+MOD)%MOD
#define Rmod(a) a = (a%MOD+MOD)%MOD
#define Rmodi(a,b) a = (a%(b)+(b))%(b)
#define Mymoi(a,b) ((a)>=b?((a)-b):(a))
#define Mymo(a) ((a)>=MOD?((a)-MOD):(a))
#define Mymod(a) a = (a)>=MOD?((a)-MOD):(a)
#define Mymodi(a,b) a = ((a)>=(b))?((a)-(b)):(a)
#define Mdis(x1,y1,x2,y2) (abs(x1-x2)+abs(y1-y2))
#define Dis(x1,y1,x2,y2) (sqrt(Dis2(x1,y1,x2,y2)))
#define Dis2(x1,y1,x2,y2) (Sqr((x1)-(x2))+Sqr((y1)-(y2)))
namespace Maths{
	_tp<_tyn T>T Gcd( T a , T b ){
		return b?Gcd(b,a%b):a;
	}
	ll Pow( ll a , ll b ){
		ll ret = 1;
		for( ; b ; (a*=a)%=MOD, b >>= 1LL )
			if(b&1LL) (ret*=a) %= MOD;
		return ret;
	}
	ll Inv( ll a ){ return Pow(a,MOD-2LL); }
}
// Random
#define USEMT
#ifdef USEMT
	#undef min
	#undef max
	#undef abs
	#undef il
	#include <chrono>
	#include <random>
	mt19937 rng;
	#define Srand() rng = mt19937(chrono::steady_clock::now().time_since_epoch().count())
	#define Rand(i) (uniform_int_distribution<int>(0,i)(rng))
	#define Randr(i,j) (uniform_int_distribution<int>(i,j)(rng))
#else
	#define Srand() srand(time(0)*(ull)(new char))
	#define Rand(i) ((rand()*rand()%(i)+(i))%(i)+1)
	#define Randr(i,j) (Rand(j-i+1)+i-1)
#endif
// Graph
namespace Graph{
	struct Dsu{
		#define DSU 10010
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
#define USEPBDS
#ifdef USEPBDS
	#undef max
	#undef min
	#undef swap
	#include <ext/pb_ds/priority_queue.hpp>
	using namespace __gnu_pbds;
#endif
// Data structure
namespace Datastructure{
	_tp<_cl T>struct Bit{
		#define BIT 100010
		#define Lowbit(x) ((x)&(~(x)+1))
		T tree[BIT];
		Bit(){ Ms(tree); }
		void Add( int pos , T x ){
			for( ; pos < BIT ; pos += Lowbit(pos) )
				tree[pos] += x;
		}
		T Sum( int pos ){
			T ret = 0;
			for( ; pos ; pos -= Lowbit(pos) )
				ret += tree[pos];
			return ret;
		}
		T Sum( int l , int r ){ return Sum(r) - Sum(l-1); }
	};
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
string a;

int main(){
	FILEIO();

	int n;
	cin >> n >> a;
	sort(All(a));
	cout << a << endl;
	
	END();
}