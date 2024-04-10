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
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
constexpr int MAXN = 262144;

int n, lo;
vc<int> e[MAXN];

vc<int> GetDiameter(){
	auto GetLongestPath = [&]( int st )->vc<int>{
		vc<int> ans{st};
		vc<int> tmp{};
		function<void(int,int)> Dfs = [&]( int pos , int fa ){
			tmp.Eb(pos);
			if( fa and e[pos].size() == 1 and tmp.size() > ans.size() )
				ans = tmp;
			for( auto v : e[pos] ){
				if( v == fa ) continue;
				Dfs(v,pos);
			}
			tmp.pop_back();
		};
		Dfs(st,0);
		return ans;
	};
	vc<int> p1 = GetLongestPath(1);
	vc<int> ans = GetLongestPath(p1.back());
	return ans;
}

function<bool(int,int,int)> IsWantedBinaryTree = []( int pos , int fa , int dep )->bool{
	assert(fa);
	if( dep == 1 ) return e[pos].size() == 1;
	if( e[pos].size() != 3 ) return 0;
	for( auto v : e[pos] ){
		if( v == fa ) continue;
		if(!IsWantedBinaryTree(v,pos,dep-1)) return 0;
	}
	return 1;
};
bool Solve1( int r1 , int r2 ){
	if( r1 > r2 ) swap(r1,r2);
	if(!IsWantedBinaryTree(r1,r2,lo-1)) return 0;
	if(!IsWantedBinaryTree(r2,r1,lo-1)) return 0;
	cout << 2 << endl;
	cout << r1 << " " << r2 << endl;
	return 1;
}
bool Solve2( int root ){
	int specnt = 0;
	int spe = -1;
	For(i,n-1){
		if( e[i].size() > 4 ) return 0;
		// P(i,e[i].size(),root);
		if( ( e[i].size() == 2 and i != root ) or e[i].size() == 4 ){
			++specnt;
			if( specnt > 1 ) return 0;
			spe = i;
		}
	}
	if(!specnt) return 0;

	function<int(int,int)> Dfs = [&]( int pos , int fa )->int{
		if( pos == spe ){
			assert(fa);

			vc<pii> sons;
			for( auto v : e[pos] ){
				if( v == fa ) continue;
				sons.Pb({v,Dfs(v,pos)+1});
			}
			sort(All(sons),[]( const pii &x , const pii &y ){ return x.S > y.S; });
			int dirson = sons[0].F;
			int newpos = n;

			if( sons.size() == 3 ){
				auto Redirect = [&]( int v ){
					e[v].erase(find(All(e[v]),pos));
					e[pos].erase(find(All(e[pos]),v));
					e[v].Pb(newpos);
					e[newpos].Pb(v);
				};
				Redirect(sons[1].F);
				Redirect(sons[2].F);
			}
			e[pos].Pb(newpos);
			e[newpos].Pb(pos);

			return -233;
		}
		int mxdep = 0;
		for( auto v : e[pos] ){
			if( v == fa ) continue;
			Mymax( mxdep , Dfs(v,pos)+1 );
		}
		return mxdep;
	};
	Dfs(root,0);

	if( e[root].size() != 2 ) return 0;
	if(!IsWantedBinaryTree(e[root][0],root,lo-1)) return 0;
	if(!IsWantedBinaryTree(e[root][1],root,lo-1)) return 0;

	cout << 1 << endl;
	cout << spe << endl;
	return 1;
}
bool Solve(){
	vc<int> diameter = GetDiameter();
	int dia_len = diameter.size();
	// Print(diameter);
	if( dia_len != lo+lo-1 and dia_len != lo+lo-2 )
		return 0;

	if( dia_len == lo+lo-2 ){
		return Solve1(diameter[dia_len/2-1],diameter[dia_len/2]);
	}else{
		return Solve2(diameter[dia_len/2]);
	}
}

int main(){
	FILEIO();

	Read(lo);
	n = (1<<lo) - 1;
	For(i,n-2){
		iRead2(a,b);
		e[a].Eb(b);
		e[b].Eb(a);
	}

	bool ok = Solve();
	if(!ok) puts("0");

	END();
}