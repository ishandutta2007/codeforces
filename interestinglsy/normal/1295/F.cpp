// InterestingLSY
// codeforces&github: interestingLSY, qq: 2659723130
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

// Pair
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
	static constexpr int MAXSZ = 1048576;
	char buf[MAXSZ]; int p;
	il InputReader(){ p = MAXSZ; }
	il void Flush(){ p = 0; fread(buf,1,MAXSZ,stdin); }
	il void GetChar( char &c ){ if(p >= MAXSZ) Flush(); c = buf[p++]; }
	il void ReadNum( char &c ){ GetChar(c); while( !isdigit(c) && c != '-' ) GetChar(c); }
	il void ReadAlpha( char &c ){ GetChar(c); while( !isalpha(c) ) GetChar(c); }
	il void ReadInt( int &ans ){
		ans = 0; int nega = 1;
		char c; ReadNum(c);
		if( c == '-' ){
			nega = -1;
			GetChar(c);
		}
		while(isdigit(c)){
			ans = ans*10 + c-'0';
			GetChar(c);
		}
		ans *= nega;
	}
	il void Readll( ll &ans ){
		ans = 0; int nega = 1;
		char c; ReadNum(c);
		if( c == '-' ){
			nega = -1;
			GetChar(c);
		}
		while(isdigit(c)){
			ans = ans*10 + c-'0';
			GetChar(c);
		}
		ans *= nega;
	}
	il void ReadString( string &x ){
		x.clear(); char ch; GetChar(ch);
		while( !isdigit(ch)  &&  !isalpha(ch)  &&  ch != '#'  &&  ch != '.' ) GetChar(ch);
		while( isdigit(ch)  ||  isalpha(ch)  ||  ch == '#'  ||  ch == '.' ){
			x += ch;
			GetChar(ch);
		}
	}
	il void ReadCString( char s[] ){
		int len = 0; char ch; GetChar(ch);
		while( !isdigit(ch)  &&  !isalpha(ch)  /*&&  ch != '*'  &&  ch != '?'*/ ) GetChar(ch);
		while( isdigit(ch)  ||  isalpha(ch)  /*||  ch == '*'  ||  ch == '?'*/ ){
			s[len++] = ch;
			GetChar(ch);
		}
		s[len] = '\0';
	}
	il void SpecialRead( char &c ){
		GetChar(c);
		while( !isdigit(c) && !isalpha(c) && c != '#'  &&  c != '.'  &&  c != '='  &&  c != 'B' ) GetChar(c);
	}
}In;
il void Read( int &x ){ In.ReadInt(x); }
il void Read( int &x, int &y ){ In.ReadInt(x); In.ReadInt(y); }
il void Read( int &x1 , int &x2 , int &x3 ){ In.ReadInt(x1); In.ReadInt(x2); In.ReadInt(x3); }
il void Read( int &x1 , int &x2 , int &x3 , int &x4 ){ In.ReadInt(x1); In.ReadInt(x2); In.ReadInt(x3); In.ReadInt(x4); }
il void Read( ll &x ){ In.Readll(x); }
il void Read( ll &x, ll &y ){ In.Readll(x); In.Readll(y); }
il void Read( ll &x1 , ll &x2 , ll &x3 ){ In.Readll(x1); In.Readll(x2); In.Readll(x3); }
il void Read( ll &x1 , ll &x2 , ll &x3 , ll &x4 ){ In.Readll(x1); In.Readll(x2); In.Readll(x3); In.Readll(x4); }
template<typename T> void Read( T a[] , int st , int ed ){ Forx(i,st,ed) Read(a[i]); }
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
template<typename T>void END( T mes ){ cout << mes << endl; END(); }

// Debug
#define B cerr << "BreakPoint" << endl;
#define O(x) cerr << #x << " " << (x) << endl;
#define o(x) cerr << #x << " " << (x) << "  ";
template<typename T0>
void P( T0 t0 ){
	cerr << t0 << endl;
}
template<typename T0, typename... Ts>
void P( T0 t0 , Ts... ts ){
	cerr << t0 << " ";
	P(ts...);
}
#define Msz(x) cerr << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
template<typename T>void Print( T a[] , int s , int t , char sp = ' ' , char ed = '\n' ){
	if( s > t ) return;
	for( int i = s ; i < t ; i++ )
		cout << a[i] << sp;
	cout << a[t] << ed;
	cout.flush();
}
template<typename T>void Print( T a , int s = 0 , int t = -1 , char sp = ' ' , char ed = '\n' ){
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
constexpr int MOD = 998244353;
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
	for( ; b ; a = a*a%p, b >>= 1 )
		if(b&1) ret = ret*a%p;
	return ret;
}
il ll Inv( ll a , const ll p = MOD ){ return Pow(a,p-2LL,p); }
constexpr int FACT = 1048576;
ll fact[FACT], invfact[FACT];
il void InitFact(){
	fact[0] = 1;
	For(i,FACT-1) fact[i] = fact[i-1]*i % MOD;
	invfact[FACT-1] = Inv(fact[FACT-1]);
	fOR0(i,FACT-1) invfact[i] = invfact[i+1]*(i+1) % MOD;
}
il ll C( int n , int m ){
	if( n < m ) return 0;
	return fact[n] * invfact[m]%MOD * invfact[n-m]%MOD;
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
constexpr int MAXN = 64;

int n;
pii a[MAXN];
pii virA[MAXN];

int k;
int blkSz[MAXN*2];

vc<int> d;
il int ToVir( int x ){ return lower_bound(All(d),x) - d.begin(); }
il int ToReal( int x ){ return d[x]; }
void Disc(){
	d.Eb(0);
	For(i,n){ d.Eb(a[i].F); d.Eb(a[i].S); }
	sort(All(d));
	d.resize( unique(All(d)) - d.begin() );
	For(i,n){
		virA[i] = { ToVir(a[i].F) , ToVir(a[i].S) };
	}
	k = d.size()-1;
	Forx(i,1,k-1) blkSz[i] = d[i+1] - d[i];
}

ll blkC[MAXN*2][MAXN];
void GetBlkC(){
	blkC[0][0] = 1;
	Forx(i,1,k-1){
		int sz = blkSz[i];
		ll c = 1;
		Forx(j,0,n){
			// blkC[i][j] = C(j+sz-1,sz-1); continue;
			if(j) Muli(c,j+sz-1);
			blkC[i][j] = c*invfact[j] % MOD;
			// assert( blkC[i][j] == C(sz,j) );
		}
	}
}

int mem[MAXN][MAXN*2][MAXN];
#define NOW mem[pos][lastBlock][lastBlockCnt]
#define KNOW ~NOW
ll Dfs( int pos , int lastBlock , int lastBlockCnt ){
	if( pos == n+1 ){
		// P(lastBlock,lastBlockCnt,blkC[lastBlock][lastBlockCnt]);
		return blkC[lastBlock][lastBlockCnt];
	}
	if(KNOW) return NOW;
	// O(pos);
	auto [l,r] = a[pos];
	auto [virL,virR] = virA[pos];
	ll ans = 0;
	Forx(curBlock,virL,virR-1){
		if( curBlock < lastBlock ) continue;
		// P(pos,curBlock);
		ll tans;
		if( curBlock == lastBlock ){
			tans = Dfs(pos+1,lastBlock,lastBlockCnt+1);
		}else{
			tans = blkC[lastBlock][lastBlockCnt] * Dfs(pos+1,curBlock,1) % MOD;
		}
		Addi(ans,tans);
	}
	return NOW = ans;
}

int main(){
	FILEIO();
	InitFact();
	Msn(mem,-1);

	Read(n);
	For(i,n){
		Read(a[i].F,a[i].S);
		++a[i].F; ++a[i].S;
		++a[i].S;
	}
	reverse(a+1,a+1+n);

	Disc();
	GetBlkC();

	ll ans = Dfs(1,0,0);
	ll tot = 1;
	For(i,n) Muli(tot,a[i].S-a[i].F);
	Muli(ans,Inv(tot));
	cout << ans << endl;

	END();
}