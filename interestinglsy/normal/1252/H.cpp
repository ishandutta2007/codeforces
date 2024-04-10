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
constexpr int MAXN = 512;
constexpr int MAXK = 524288;

int n,m,k;

bool avail[MAXK][8];
struct JumperLanding{
	int id;
	int type;
	int d;
	ll cost;
};
vc<JumperLanding> landings[MAXN][MAXN];
il bool AddLanding( int id, int type , int x , int y , int d , int t , ll cost ){
	// if( x >= n or y >= m or x < 0 or y < 0 ) return 0;
	int arrival_t = x+y;
	if( t > arrival_t ) return 0;
	if( t%4 != arrival_t%4 ) return 0;
	landings[x][y].Pb({id,type,d,cost});
	return 1;
}

ll dp[2][MAXN][2][MAXN];
ll Dp(){
	Msn(dp,INF);
	int cur = 0;
	dp[cur][0][0][0] = 0;
	dp[cur][0][1][0] = 0;
	Forx(xysum,1,n-1+m-1){
		int last = cur;
		cur ^= 1;
		Msn(dp[cur],INF);
		auto ldp = dp[last];
		auto udp = dp[cur];

		int x_lo = max(0,xysum-m+1);
		int x_hi = min(n-1,xysum);
		Forx(x,x_lo,x_hi){
			int y = xysum - x;
			assert( 0 <= x and x < n );
			assert( 0 <= y and y < m );
			// P(x,y);
			ll add = 0;
			for( auto landing : landings[x][y] )
				add += landing.cost;

			int len_lim = max(n,m);
			Forx(len,0,len_lim){
				if(y) Mymin( udp[x][0][len+1] , ldp[x][0][len] + add );
				if(x) Mymin( udp[x][1][len+1] , ldp[x-1][1][len] + add );
			}

			for( auto landing : landings[x][y] ){
				if( landing.type == 1 ) continue;
				if( landing.type == 2 ) continue;
				int min_len = landing.d;
				if( ( landing.type == 3 and avail[landing.id][2] ) or
					( landing.type == 4 and avail[landing.id][1] ) ){
					Forx(len,min_len,len_lim)
						udp[x][0][len] -= landing.cost;
				}
				if( ( landing.type == 3 and avail[landing.id][1] ) ){
					Forx(len,min_len,len_lim)
						udp[x][1][len] -= landing.cost;
				}
			}

			Forx(len,0,len_lim){
				Mymin( udp[x][0][0] , udp[x][1][len] );
				Mymin( udp[x][1][0] , udp[x][0][len] );
			}
		}
	}
	auto ansdp = dp[cur];
	ll ans = LINF;
	Forx(len,0,max(n,m)){
		Mymin( ans , ansdp[n-1][0][len] );
		Mymin( ans , ansdp[n-1][1][len] );
	}
	return ans;
}

int main(){
	FILEIO();

	Read(n,m,k);
	For(i,k){
		iRead2(x,y);
		iRead3(d,t,cost);
		avail[i][1] = AddLanding(i,1,x,y,d,t,cost);
		avail[i][2] = AddLanding(i,2,x+d,y-d,d,t+1,cost);
		avail[i][3] = AddLanding(i,3,x+d,y,d,t+2,cost);
		avail[i][4] = AddLanding(i,4,x,y+d,d,t+3,cost);
	}

	ll ans = Dp();
	cout << ans << endl;

	END();
}