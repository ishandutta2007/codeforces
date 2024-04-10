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
#define O(x) cerr << #x << " " << x << endl;
#define o(x) cerr << #x << " " << x << "  ";
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
#define Sqr(x) ((ull)(x)*(x))
#define Lowbit(a) ((a)&(-(a)))
vc<int> Range( int l , int r ){
	vc<int> ret{};
	Forx(i,l,r) ret.Pb(i);
	return ret;
}
mt19937 Rand(0xe38195e38293);	// 
#define MOD (1000000007LL)
#define Rmoi(a,b) ((a)%b+b)%b
#define Rmo(a) ((a)%MOD+MOD)%MOD
#define Rmod(a) a = (a%MOD+MOD)%MOD
#define Rmodi(a,b) a = (a%(b)+(b))%(b)
#define Mymoi(a,b) ((a)>=b?((a)-b):(a))
#define Mymodi(a,b) a = ((a)>=(b))?((a)-(b)):(a)
template<typename T>
T Mymo( const T &x ){ return x >= MOD ? x-MOD : x; }
template<typename T>
void Mymod( T &x ){ x = x >= MOD ? x-MOD : x; }
il ll Pow( ll a , ll b , const ll p = MOD ){
	ll ret = 1;
	for( ; b ; a = a*a%p, b >>= 1LL )
		if(b&1LL) ret = ret*a%p;
	return ret;
}
il ll Inv( ll a , const ll p = MOD ){ return Pow(a,p-2LL,p); }
il ll Frac( const ll x ){
	ll ret = 1;
	For(i,x) ret = ret*i % MOD;
	return ret;
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
const int MAXN = 262144;

int n;
struct Line{ int l,r,id,vir_l,vir_r; };
vc<Line> a;

vc<int> ps;
int tot;
int max_l = 0, max_l_cnt = 0;
void Readin(){
	Read(n);
	For(i,n){
		iRead2(l,r);
		swap(l,r);
		a.Pb({l,r,i,0,0});
		ps.Eb(l); ps.Eb(r);
		if( l > max_l ){
			max_l = l;
			max_l_cnt = 0;
		}
		if( l == max_l ) ++max_l_cnt;
	}
	sort(All(ps));
	ps.resize( unique(All(ps)) - ps.begin() );
	tot = ps.size();
	for( auto &[l,r,id,vir_l,vir_r] : a ){
		vir_l = lower_bound(All(ps),l) - ps.begin() + 1;
		vir_r = lower_bound(All(ps),r) - ps.begin() + 1;
	}
}

#define TREE 1048576
#define ARG int l , int r , int pos
#define ROOT 1,tot,1
#define LSON l,l+r>>1,pos<<1
#define RSON (l+r>>1)+1,r,pos<<1|1
struct Node{ ll mi; int micnt; };
il Node operator+( const Node &a , const Node &b ){
	ll cmi = min(a.mi,b.mi);
	return (Node){
		cmi,
		Mymo( (a.mi==cmi?a.micnt:0) + (b.mi==cmi?b.micnt:0) )
	};
}
Node t[TREE];
#define Mi(pos) t[pos].mi
#define Micnt(pos) t[pos].micnt
il void Update( int pos ){
	t[pos] = t[pos<<1] + t[pos<<1|1];
}
il void Build(ARG){
	t[pos] = {LINF,r-l+1};
	if( l == r ) return;
	Build(LSON);
	Build(RSON);
}
il void Change( int gpos , Node x , ARG ){
	if( l == r ){
		// assert( t[pos].mi >= x.mi );
		t[pos] = x+t[pos];
		return;
	}
	int mid = l+r >> 1;
	if( gpos <= mid ) Change(gpos,x,LSON);
	else Change(gpos,x,RSON);
	Update(pos);
}
il Node Query( int gl , int gr , ARG ){
	if( gl <= l and r <= gr ) return t[pos];
	int mid = l+r >> 1;
	if( gr <= mid ) return Query(gl,gr,LSON);
	if( gl > mid ) return Query(gl,gr,RSON);
	return Query(gl,gr,LSON) + Query(gl,gr,RSON);
}

ll dp[MAXN];
int cnt[MAXN];

int main(){
	FILEIO();

	Readin();
	sort(All(a),[]( const Line &a , const Line &b ){
		return a.l != b.l ? a.l < b.l : a.r < b.r;
	});
	Build(ROOT);

	ll ans = 0, minsp = LINF;
	for( auto [l,r,id,vir_l,vir_r] : a ){
		Node res = Query(1,vir_l,ROOT);
		if( res.mi >= LINF ){
			dp[id] = l; cnt[id] = 1;
		}else{
			dp[id] = l + res.mi;
			cnt[id] = res.micnt;
		}
		Change(vir_r,{dp[id]-r,cnt[id]},ROOT);
		// cout << r << " " << max_l << endl;
		// cout << id << " " << dp[id] << endl;
		if( r > max_l ){
			Mymin(minsp,dp[id]);
		}
	}

	for( auto [l,r,id,vir_l,vir_r] : a ){
		if( r > max_l and dp[id] == minsp ){
			ans = Mymo( ans + cnt[id] );
		}
	}
	cout << ans << endl;

	END();
}