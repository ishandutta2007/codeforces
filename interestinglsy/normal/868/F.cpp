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
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
constexpr int MAXN = 131072;

int n, k;
int a[MAXN];

struct CostKeeper{
	int app[MAXN];
	ll cost;
	il void Clear(){
		Ms(app);
		cost = 0;
	}
	il void AddNumber( int x ){
		// P("add",x);
		cost += app[x];
		++app[x];
	}
	il void DelNumber( int x ){
		// P("del",x);
		--app[x];
		cost -= app[x];
	}
};

ll dp[MAXN];
void Transform( int resL , int resR ){
	static ll ndp[MAXN];
	static CostKeeper costKeeper;
	// For(i,n) assert(!costKeeper.app[i]);

	auto AddInterval = [&]( int l , int r ){
		Forx(i,l,r)
			costKeeper.AddNumber(a[i]);
	};
	auto DelInterval = [&]( int l , int r ){
		Forx(i,l,r)
			costKeeper.DelNumber(a[i]);
	};

	auto Check = [&]( int l , int r , int t ){
		static CostKeeper ck;
		ck.Clear();
		Forx(i,l,r) ck.AddNumber(a[i]);
		if( ck.cost != t ){
			P(l,r,ck.cost,t);
		}
		return ck.cost;
	};
	function<void(int,int,int,int)>
	OverallDAC = [&]( int fromL , int fromR , int resL , int resR ){
		if( resL > resR ) return;
		// assert( fromL <= fromR );
		if( fromL == fromR ){
			// assert( fromR <= resL );
			Forx(i,resL,resR){
				costKeeper.AddNumber(a[i]);
				ndp[i] = dp[fromL-1] + costKeeper.cost;
			}
			fORx(i,resL,resR)
				costKeeper.DelNumber(a[i]);
			return;
		}
		// costKeeper.Clear();
		// Forx(i,fromR,resL-1)
		// 	costKeeper.AddNumber(a[i]);

		int resMid = resL + resR >> 1;
		pli midTransform = {LINF,-1};

		static vc<int> added; added.clear();
		static vc<int> deled; deled.clear();

		Forx(i,fromR>=resL?fromR:resL,resMid){
			added.Eb(a[i]);
			costKeeper.AddNumber(a[i]);
		}
		fORx(i,fromL,min(resMid,fromR)){
			if( i < fromR ){
				added.Eb(a[i]);
				costKeeper.AddNumber(a[i]);
			}
			// Check(i,resMid,costKeeper.cost);
			pli tMidTransform = {dp[i-1]+costKeeper.cost,i};
			Mymin( midTransform , tMidTransform );
		}
		assert( midTransform.S != -1 );
		ndp[resMid] = midTransform.F;
		for( auto x : deled ) costKeeper.AddNumber(x);
		for( auto x : added ) costKeeper.DelNumber(x);

		#define Func(l,r) \
		{ \
			AddInterval(l,r); \
			NEXTFUNC; \
			DelInterval(l,r); \
		}

		// auto Func = [&]( int l , int r , int fL , int fR , int rL , int rR ){
		// 	AddInterval(l,r);
		// 	OverallDAC(fL,fR,rL,rR);
		// 	DelInterval(l,r);
		// };

		#define NEXTFUNC OverallDAC(fromL,midTransform.S,resL,resMid-1)
		if( midTransform.S < resL ){
			if( fromR < resL ) Func(midTransform.S,fromR-1)
			else Func(midTransform.S,resL-1)
		}else{
			Func(1,-1);
		}
		#undef NEXTFUNC

		#define NEXTFUNC OverallDAC(midTransform.S,fromR,resMid+1,resR);
		if( fromR < resMid+1 ){
			if( fromR < resL ) Func(resL,resMid)
			else Func(fromR,resMid)
		}else{
			Func(1,-1);
		}
	};
	OverallDAC(1,n,resL,resR);
	memcpy(dp,ndp,sizeof dp);
	// assert(!costKeeper.cost);
}

int main(){
	FILEIO();

	Read(n,k);
	Read(a,1,n);

	Msn(dp,INF);
	dp[0] = 0;
	For(i,k){
		Transform(i,n);
	}

	cout << dp[n] << endl;

	END();
}