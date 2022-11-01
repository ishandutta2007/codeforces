// InterestingLSY
// 2659723130
// 
#include <bits/stdc++.h>
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
#undef ld
#define ld long double
const ld Eps = 1e-8;
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
const int MAXN = 131072;
// #define i128 __int128

struct Point{
	ll x,y; ld slope; int id;
	il Point ReplaceSlope( ld newslope ){
		return {x,y,newslope,id};
	}
};
il Point operator+( const Point &a , const Point &b ){ return {a.x+b.x,a.y+b.y}; }
il Point operator-( const Point &a , const Point &b ){ return {a.x-b.x,a.y-b.y}; }
il ld operator*( const Point &a , const Point &b ){ return (ld)a.x*b.y - (ld)a.y*b.x; }
il bool operator==( const Point &a , const Point &b ){ return a.x == b.x and a.y == b.y; };
il bool TurnLeft( const Point &a , const Point &b , const Point &c ){
	return (b-a)*(c-b) > 0;
}
il bool TurnRight( const Point &a , const Point &b , const Point &c ){
	return (b-a)*(c-b) < 0;
}
il ld Slope( const Point &a , const Point &b ){
	assert( a.x != b.x );
	return (ld)(a.y-b.y) / (ld)(a.x-b.x);
}

il bool CmpByXYAsc( const Point &a , const Point &b ){
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}
il bool CmpBySlopeDesc( const Point &a , const Point &b ){
	return a.slope < b.slope;
}
bool comp_type = 0;
il bool operator<( const Point &a , const Point &b ){
	return !comp_type ? CmpByXYAsc(a,b) : CmpBySlopeDesc(a,b);
}

struct Hull{
	set<Point> h;
	il int PopLeft( auto iter , Point p ){
		if( iter == h.begin() ) return 0;
		iter = prev(iter);
		int removed = 0;
		while( iter != h.begin() ){
			auto tmp = iter; iter = prev(iter);
			Point b = *tmp , bb = *iter;
			if(!TurnLeft(bb,b,p)){
				++removed;
				h.erase(tmp);
			}else break;
		}
		return removed;
	}
	il int PopRight( auto iter , Point p ){
		if( iter == h.end() ) return 0;
		int removed = 0;
		while(1){
			auto tmp = iter; iter = next(iter);
			if( iter == h.end() ) break;
			Point f = *tmp , ff = *iter;
			if(!TurnLeft(p,f,ff)){
				++removed;
				h.erase(tmp);
			}else break;
		}
		return removed;
	}
	void Insert( Point p ){
		comp_type = 0;
		auto lowp = h.lower_bound(p);
		if( lowp != h.end() and *lowp == p ) return;

		int l_removed = PopLeft(lowp,p);
		lowp = h.lower_bound(p);
		int r_removed = PopRight(lowp,p);
		lowp = h.lower_bound(p);

		if( h.size() >= 2 and lowp != h.begin() and lowp != h.end() ){
			Point pre = *prev(lowp), nxt = *lowp;
			if(!TurnLeft(pre,p,nxt)){
				// O(l_removed);
				// O(r_removed);
				// assert( !l_removed and !r_removed );
				return;
			}
		}

		if( lowp != h.begin() ){
			auto iter = prev(lowp);
			if( iter->x == p.x ) return;
		}
		lowp = h.lower_bound(p);

		if( lowp != h.end() ){
			if( lowp->x == p.x ) h.erase(lowp);
		}
		lowp = h.lower_bound(p);

		if( lowp != h.begin() ){
			auto prep = prev(lowp);
			Point pre = *prep;
			h.erase(prep);
			h.insert(pre.ReplaceSlope(Slope(pre,p)));
		}
		ld now_slope;
		if( lowp != h.end() ){
			Point nxt = *lowp;
			now_slope = Slope(p,nxt);
		}else{
			now_slope = 1e10;
		}
		h.insert(p.ReplaceSlope(now_slope));
		// h.insert(p);
	}
	void Merge( const Hull &h2 ){
		for( auto p : h2.h ){
			Insert(p);
		}
	}
	int Tangent( ld slope ){
		comp_type = 1;
		auto iter = h.lower_bound({0,0,slope,0});
		if( iter == h.end() ) iter = prev(iter);
		return iter->id;
	}
	ll BruteCalc( ll slope ){
		ll ans = LINF;
		for( auto p : h ){
			ll tans = slope*p.x + p.y;
			MyMin(ans,tans);
		}
		return ans;
	}
}hulls[MAXN];

int n;
vc<int> e[MAXN];
ll a[MAXN], b[MAXN];
ll dp[MAXN];

int sz[MAXN], gson[MAXN];
void FindGson( int pos , int fa ){
	sz[pos] = 1;
	for( auto v : e[pos] ){
		if( v == fa ) continue;
		FindGson(v,pos);
		sz[pos] += sz[v];
		if( sz[v] > sz[gson[pos]] )
			gson[pos] = v;
	}
}

void Solve( int pos , int fa ){
	if( fa and e[pos].size() == 1 ){
		dp[pos] = 0;
		hulls[pos].Insert({b[pos],dp[pos],-1,pos});
		return;
	}
	if(gson[pos]){
		Solve(gson[pos],pos);
		hulls[pos].h.swap(hulls[gson[pos]].h);	// magic
	}
	for( auto v : e[pos] ){
		if( v == fa or v == gson[pos] ) continue;
		Solve(v,pos);
		hulls[pos].Merge(hulls[v]);
	}
	int vjump = hulls[pos].Tangent(-a[pos]);
	dp[pos] = a[pos]*b[vjump] + dp[vjump];
	// dp[pos] = hulls[pos].BruteCalc(a[pos]);
	hulls[pos].Insert({b[pos],dp[pos],-1,pos});
}

int main(){
	FILEIO();
	#ifdef intLSY
		Fout("ans.out");
	#endif

	Read(n);
	Read(a,1,n);
	Read(b,1,n);
	For(i,n-1){
		iRead2(a,b);
		e[a].Eb(b);
		e[b].Eb(a);
	}

	FindGson(1,0);
	Solve(1,0);
	Print(dp,1,n,'\n');

	END();
}