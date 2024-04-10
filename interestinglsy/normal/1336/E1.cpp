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
	char buf[MAXSZ]; int p, ed;
	bool detectedEOF = false;
	il InputReader(){ p = MAXSZ; }
	il void Flush(){ p = 0; ed = fread(buf,1,MAXSZ,stdin); }
	il void GetChar( char &c ){
		if(p >= MAXSZ) Flush();
		if( p == ed ){ detectedEOF = true; }
		c = buf[p++];
	}
	il void ReadNum( char &c ){ GetChar(c); while( !isdigit(c) && c != '-' && !detectedEOF ) GetChar(c); }
	il void ReadAlpha( char &c ){ GetChar(c); while( !isalpha(c) && !detectedEOF ) GetChar(c); }
	il void ReadInt( int &ans ){
		ans = 0; int nega = 1;
		char c; ReadNum(c); if(detectedEOF) return;
		if( c == '-' ){
			nega = -1;
			GetChar(c);
		}
		while( isdigit(c) && !detectedEOF ){
			ans = ans*10 + c-'0';
			GetChar(c);
		}
		ans *= nega;
	}
	il void Readll( ll &ans ){
		ans = 0; int nega = 1;
		char c; ReadNum(c); if(detectedEOF) return;
		if( c == '-' ){
			nega = -1;
			GetChar(c);
		}
		while( isdigit(c) && !detectedEOF ){
			ans = ans*10 + c-'0';
			GetChar(c);
		}
		ans *= nega;
	}
	il void ReadString( string &x ){
		x.clear(); char ch; GetChar(ch);
		while( !isdigit(ch) && !isalpha(ch) && ch != '#' && ch != '.' && !detectedEOF ) GetChar(ch); if(detectedEOF) return;
		while( (isdigit(ch) || isalpha(ch) || ch == '#' || ch == '.') && !detectedEOF ){
			x += ch;
			GetChar(ch);
		}
	}
	il void ReadCString( char s[] ){
		int len = 0; char ch; GetChar(ch);
		while( !isdigit(ch) && !isalpha(ch) && ch != '#' && ch != '.' && !detectedEOF ) GetChar(ch); if(detectedEOF) return;
		while( (isdigit(ch) || isalpha(ch) || ch == '#' || ch == '.') && !detectedEOF ){
			s[len++] = ch;
			GetChar(ch);
		}
		s[len] = '\0';
	}
	il void SpecialRead( char &c ){
		GetChar(c); if(detectedEOF) return;
		while( !isdigit(c) && !isalpha(c) && c != '#' && c != '.' && c != '=' && c != 'B' && !detectedEOF ) GetChar(c);
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
// constexpr int MOD = 1'000'000'007;
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
const ll inv2 = Inv(2);
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
constexpr int MAXN = 262144;
constexpr int MAXM = 64;

int n,m;
ll a[MAXN];
int ansl[MAXM];

struct LinerBasis{
	ll b[MAXM];
	int failCnt;
	int succCnt;
	ll failMul = 1;
	void Reset(){
		Ms(b);
		failCnt = succCnt = 0;
		failMul = 1;
	}
	bool Insert( ll x ){
		fOR0(i,MAXM){
			if(x>>i&1^1) continue;
			if(!b[i]){
				Forx(j,0,i-1) if(x>>j&1) x ^= b[j];
				Forx(j,i+1,MAXM-1) if(b[j]>>i&1) b[j] ^= x;
				++succCnt;
				b[i] = x;
				return true;
			}else{
				x ^= b[i];
			}
		}
		++failCnt;
		Muli(failMul,2);
		return false;
	}
};

LinerBasis bas;

void FWT( ll a[] , int n ){
	for( int step = 2 ; step <= n ; step <<= 1 ){
		int half = step/2;
		Forstep(i,0,n-1,step){
			Forx(j,i,i+half-1){
				int l = a[j], r = a[j+half];
				a[j] = Mymo(l-r+MOD);
				a[j+half] = Mymo(l+r);
			}
		}
	}
}
void IFWT( ll a[] , int n ){
	for( int step = 2 ; step <= n ; step <<= 1 ){
		int half = step/2;
		Forstep(i,0,n-1,step){
			Forx(j,i,i+half-1){
				int l = a[j], r = a[j+half];
				a[j] = (l+r)*inv2 % MOD;
				a[j+half] = (r-l+MOD)*inv2 % MOD;
			}
		}
	}
}

#define popcnt __builtin_popcount

void GetDistribution( vc<ll> &s , ll a[] ){
	memset(a,0,8*262144);
	function<void(vc<ll>::iterator,ll)> Dfs = [&]( auto cur , ll xorSum ){
		if( cur == s.end() ){
			++a[xorSum];
			return;
		}
		Dfs(next(cur),xorSum);
		Dfs(next(cur),xorSum^(*cur));
	};
	Dfs(s.begin(),0);
}

const int mid = 17;
void Fuck( vc<ll> &s , ll a[20][262144] ){
	function<void(vc<ll>::iterator,ll)> Dfs = [&]( auto cur , ll xorSum ){
		if( cur == s.end() ){
			++a[popcnt(xorSum>>mid)][xorSum&((1<<mid)-1)];
			return;
		}
		Dfs(next(cur),xorSum);
		Dfs(next(cur),xorSum^(*cur));
	};
	Dfs(s.begin(),0);
}

int main(){
	FILEIO();

	Read(n,m);
	Read(a,1,n);

	For(i,n) bas.Insert(a[i]);
	// O(bas.failMul);

	// >=mid <mid 
	static vc<ll> smaller, bigger;
	For0(i,mid){
		if(!bas.b[i]) continue;
		assert( bas.b[i] < (1<<mid) );
		smaller.Eb(bas.b[i]);
	}
	Forx(i,mid,m){
		if(!bas.b[i]) continue;
		int pc = popcnt(bas.b[i]>>mid);
		bigger.Eb(bas.b[i]);
	}

	// For0(i,m)
	// 	if(bas.b[i])
	// 		P(bitset<8>(bas.b[i]));

	// 
	constexpr int DISTRISZ = 262144;
	static ll smallerDistri[DISTRISZ];
	GetDistribution(smaller,smallerDistri);
	// Print(smallerDistri,0,15);
	FWT(smallerDistri,DISTRISZ);

	static ll biggerDd[20][DISTRISZ];
	Fuck(bigger,biggerDd);

	For0(pc,20){
		auto biggerD = biggerDd[pc];
		FWT(biggerD,DISTRISZ);
		For0(i,DISTRISZ)
			Muli(biggerD[i],smallerDistri[i]);
		IFWT(biggerD,DISTRISZ);
		For0(i,DISTRISZ){
			int tpc = popcnt(i) + pc;
			Addi( ansl[tpc] , biggerD[i]*bas.failMul%MOD );
		}
	}

	Forx(i,0,m)
		printf("%d ",ansl[i]);
	putchar(10);

	END();
}