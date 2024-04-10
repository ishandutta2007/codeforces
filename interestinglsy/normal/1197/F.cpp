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
#define Sqr(x) ((x)*(x))
#define Lowbit(a) ((a)&(-(a)))
mt19937 Rand(0xe38195e38293);	// 
#define MOD (998244353LL)
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

// orz laofudasuan
// modified

namespace io{
	const int SIZE = (1 << 20) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// print the remaining part
	inline void Flush(){
		fwrite(obuf,1,oS-obuf,stdout);
		oS = obuf;
	}
	// putchar
	inline void Putc(char x) {

		*oS ++ = x;
		if( oS == oT ) Flush();
	}
	// print a signed integer
	template <class I>
	inline void Print(I x) {
		if(!x) Putc('0');
		if( x < 0 ){ Putc('-'); x = -x; }
		while(x){
			qu[++ qr] = x % 10 + '0';
			x /= 10;
		}
		while(qr) Putc(qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_{~Flusher_(){Flush();}}io_flusher_;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#define Vec vc<int>
#define Mat vc<vc<int>>
const int MAXN = 1024;
/*
 dp 
dp[i][r1][r2][r3]  i  123 
 sg  r1 r2 r3.
*/

Vec Mul( const Mat &a , const Vec &b ){
	int n = a.size(), m = b.size();
	Vec c(m);
	For0(i,n)
		For0(j,m)
			c[i] = ( c[i] + 1LL*b[j]*a[i][j] ) % MOD;
	return c;
}
Mat Add( const Mat &a , const Mat &b ){
	int n = a.size(), m = a[0].size();
	assert( b.size() == n );
	assert( b[0].size() == m );
	Mat c(n,Vec(m,0));
	For0(i,n)
		For0(j,m)
			c[i][j] = Mymo(a[i][j]+b[i][j]);
	return c;
}
Mat Mul( const Mat &a , const Mat &b ){
	int x = a.size(), y = a[0].size(), z = b[0].size();
	assert( b.size() == y );
	Mat c(x,Vec(z,0));
	For0(i,x)
		For0(j,y)
			For0(k,z)
				c[i][k] = ( c[i][k] + 1LL*a[i][j]*b[j][k] ) % MOD;
	return c;
}
Mat Pow( Mat a , int b ){
	int n = a.size();
	assert( a[0].size() == n );
	Mat c(n,Vec(n,0));
	For0(i,n) c[i][i] = 1;
	while(b){
		if(b&1) c = Mul(c,a);
		if(b>>=1) a = Mul(a,a);
	}
	return c;
}

int n, a[MAXN], m;
vc<pii> cols[MAXN];
int can[3][3];
il void Readin(){
	Read(n);
	Read(a,0,n-1);
	Read(m);
	For(i,m){
		iRead3(which,pos,col);
		--which; --pos; --col;
		cols[which].Pb({pos,col});
	}
	For0(i,n) sort(All(cols[i]));
	For0(i,3) For0(j,3) Read(can[i][j]);
}

il vc<int> Decode( int x ){ return {x>>4,(x>>2)&3,x&3}; }
il int Encode( vc<int> x ){ return x[0]<<4 | x[1]<<2 | x[2]; }

Mat colmat[3], fullmat(64,Vec(64,0)), fullpow[32];
Mat CalcColMat( int color ){
	Mat ret(64,Vec(64,0));
	For0(bef,64){
		vc<int> r = Decode(bef);
		bool apped[4] = {0,0,0,0};
		// apped[0] = apped[1] = apped[2] = apped[3] = 0;
		if(can[color][0]) apped[r[0]] = 1;
		if(can[color][1]) apped[r[1]] = 1;
		if(can[color][2]) apped[r[2]] = 1;
		int aft_sg = !apped[0] ? 0 : !apped[1] ? 1 : !apped[2] ? 2 : 3;
		int aft = Encode({ aft_sg , r[0] , r[1] });
		// ++ret[bef][aft];
		++ret[aft][bef];
		// cout << aft_sg << endl;
	}
	return ret;
}

void InitTran(){
	For0(i,3){
		// 
		colmat[i] = CalcColMat(i);
		fullmat = Add(fullmat,colmat[i]);
	}
	// For0(i,64) Print(fullmat[i]);
	fullpow[0] = fullmat;
	For(i,31) fullpow[i] = Mul(fullpow[i-1],fullpow[i-1]);
}
Vec PowMul( int b , Vec v ){
	Forx(i,0,30){
		if(b&1) v = Mul(fullpow[i],v);
		b >>= 1;
	}
	return v;
}

int dp[MAXN][4];
void Dp(){
	dp[0][0] = 1;
	For0(i,n){
		Vec t(64,0);
		t[Encode({3,3,3})] = 1;
		int last = 0;
		for( auto [pos,col] : cols[i] ){
			t = PowMul(pos-last,t);
			t = Mul(colmat[col],t);
			last = pos+1;
		}
		t = PowMul(a[i]-last,t);
		For0(j,4)
			For0(k,64){
				int sg = Decode(k)[0];
				dp[i+1][j^sg] = ( dp[i+1][j^sg] + 1LL*dp[i][j]*t[k] ) % MOD;
			}
	}
}

int main(){
	FILEIO();
	// Fout("ans.out");

	Readin();
	InitTran();
	Dp();
	cout << dp[n][0] << endl;

	END();
}