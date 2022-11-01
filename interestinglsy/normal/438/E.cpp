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
#define O_(x) cerr << #x << " " << x << "  ";
#define ERR(x) cerr << "ERR! #" << x << endl;
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
// #define max(a,b) ((a)>(b)?(a):(b))
// #define min(a,b) ((a)<(b)?(a):(b))
#define Mymax(a,b) (a) = max((a),(b))
#define Mymin(a,b) (a) = min((a),(b))
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
#define Sqr(x) ((x)*(x))
#define Lowbit(a) ((a)&(-(a)))
vc<int> Range( int l , int r ){
	vc<int> ret{};
	Forx(i,l,r) ret.Pb(i);
	return ret;
}
#define MOD (998244353)
#define Rmoi(a,b) ((a)%b+b)%b
#define Rmo(a) ((a)%MOD+MOD)%MOD
#define Rmod(a) a = (a%MOD+MOD)%MOD
#define Rmodi(a,b) a = (a%(b)+(b))%(b)
#define Mymoi(a,b) ((a)>=b?((a)-b):(a))
#define Mymo(a) ((a)>=MOD?((a)-MOD):(a))
#define Mymod(a) a = (a)>=MOD?((a)-MOD):(a)
#define Mymodi(a,b) a = ((a)>=(b))?((a)-(b)):(a)
#define Bit(mask,pos) ((mask)>>(pos)&1)
#define Add(mask,pos) ((mask)|1<<(pos))
struct I{
	int z;
	il I(){ z = 0; }
	_tp<_tyn T> il I( T v ){ z = v; }
};
il bool operator==( const I &a , const I &b ){ return a.z == b.z; }
il bool operator!=( const I &a , const I &b ){ return a.z != b.z; }
il bool operator<( const I &a , const I &b ){ return a.z < b.z; }
il bool operator<=( const I &a , const I &b ){ return a.z <= b.z; }
il bool operator>( const I &a , const I &b ){ return a.z > b.z; }
il bool operator>=( const I &a , const I &b ){ return a.z >= b.z; }
il I operator+( const I &a , const I &b ){ return a.z+b.z >= MOD ? a.z+b.z-MOD : a.z+b.z; }
il I operator-( const I &a , const I &b ){  return a.z>=b.z ? a.z-b.z : a.z-b.z+MOD; }
il I operator-( const I &a ){ return a.z ? MOD-a.z : 0; }
il I operator*( const I &a , const I &b ){  return 1LL*a.z*b.z%MOD; }
il I &operator+=( I &a , const I &b ){  a.z = a.z+b.z>=MOD ? a.z+b.z-MOD : a.z+b.z; return a; }
il I &operator-=( I &a , const I &b ){  a.z = a.z>=b.z ? a.z-b.z : a.z-b.z+MOD; return a; }
il I &operator*=( I &a , const I &b ){  a.z = 1LL*a.z*b.z%MOD; return a; }
il istream &operator>>( istream &inp , I &a ){ ll x; inp >> x; a = I(x); return inp; }
il ostream &operator<<( ostream &oup , const I &a ){ oup << a.z; return oup; }
il I Pow( I a , ll b ){
	I ans = 1;
	for( ; b ; b >>= 1LL, a *= a ) if(b&1LL) ans *= a;
	return ans;
}
int Exgcd( int a , int b , int &x , int &y ){
	if(!b){ x = 1; y = 0; return a; }
	int x_,y_,d = Exgcd(b,a%b,x_,y_);
	x = y_; y = x_-(a/b)*y_;
	return d;
}
il I Inv( I a , int p = MOD ){
	int x,y; Exgcd(a.z,p,x,y); return I(Rmoi(x,p));
}
il I operator/( const I &a , const I &b ){ return a*Inv(b); }
il I &operator/=( I &a , const I &b ){ a *= Inv(b); return a; }

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#define MAXN 262144

const int tot = 262144;
I w[tot], invw[tot];
void InitW(){
	const I bs = Pow(3,998244352/tot), invbs = Inv(bs);
	I tb = 1, invtb = 1;
	For0(i,tot){
		w[i] = tb; tb *= bs;
		invw[i] = invtb; invtb *= invbs;
	}
}

int DFT( int _n , I a[] , bool useinv = 0 ){
	int n,logn; for( n = 1, logn = 0 ; n < _n ; n <<= 1, ++logn );
	For0(i,n){ int to = 0; For0(j,logn) if(Bit(i,j)) to = Add(to,logn-j-1); if( to < i ) swap(a[to],a[i]); }
	auto uw = useinv ? invw : w;
	for( int len = 2 ; len <= n ; len <<= 1 ){
		int half = len >> 1, divres = tot/len;
		Forstep(st,0,n-1,len)
			For0(k,half){
				I l = a[st+k], r = uw[divres*k]*a[st+k+half];
				a[st+k] = l+r; a[st+k+half] = l-r;
			}
	}
	if(useinv) For0(i,n) a[i] /= I(n);
	return n;
}

void PolyInv( int n , I f[] , I g[] ){
	if( n == 1 ){ g[0] = Inv(f[0]); return; }
	PolyInv(n+1>>1,f,g);
	int len; for( len = 1 ; len < n<<1 ; len <<= 1 );

	static I f_dfted[MAXN];
	copy(f,f+n,f_dfted);
	fill(f_dfted+n,f_dfted+len,0);
	DFT(len,f_dfted);

	DFT(len,g);
	For0(i,len) g[i] = 2*g[i] - f_dfted[i]*g[i]*g[i];
	DFT(len,g,1);
	fill(g+n,g+len,0);
}

void PolySqrt( int n , I f[] , I g[] ){	// g: f0, f: A
	if( n == 1 ){ g[0] = 1; return; }	//  f[0] = 1
	PolySqrt(n+1>>1,f,g);
	int len; for( len = 1 ; len < n<<1 ; len <<= 1 );
	int half = n+1>>1;
	static I g_inved[MAXN];

	fill(g+half,g+n,0);
	fill(g_inved,g_inved+len,0);
	PolyInv(n,g,g_inved);
	fill(g_inved+n,g_inved+len,0);
	DFT(len,g_inved);

	fill(g+half,g+len,0);
	DFT(len/2,g);
	For0(i,len/2) g[i] = g[i]*g[i];
	DFT(len/2,g,1);

	For0(i,n) g[i] = (g[i]+f[i])/2;
	DFT(len,g);

	For0(i,len) g[i] = g[i]*g_inved[i];
	DFT(len,g,1);
}

int main(){
	FILEIO();
	InitW();

	int n,m;
	static I t[MAXN];

	Read(n,m); ++m;
	For(i,n){
		iRead(x);
		if( x < m )
			t[x] = 1;
	}

	For0(i,m) t[i] = -t[i] * 4;
	t[0] += 1;

	static I t_sqrted[MAXN];
	PolySqrt(m,t,t_sqrted);
	t_sqrted[0] += 1;

	static I t_sqrted_inved[MAXN];
	PolyInv(m,t_sqrted,t_sqrted_inved);
	For0(i,m) t_sqrted_inved[i] *= 2;

	For(i,m-1) printf("%d\n",t_sqrted_inved[i]);

	END();
}