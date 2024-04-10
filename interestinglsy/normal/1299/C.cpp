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
#define Equ(a,b) (fabs((a)-(b))<Eps)
constexpr ld Eps = 1e-7;
constexpr ld PI = 3.141592653589793238462643383279502884197169399;
struct Point{
	ld x,y;
	il ld Len2(){ return x*x+y*y; }
	il ld Len(){ return sqrt(x*x+y*y); }
};
il Point operator+( const Point &a , const Point &b ){ return {a.x+b.x,a.y+b.y}; }
il Point operator-( const Point &a , const Point &b ){ return {a.x-b.x,a.y-b.y}; }
il ld operator%( const Point &a , const Point &b ){ return a.x*b.x + a.y*b.y; }
il ld operator*( const Point &a , const Point &b ){ return a.x*b.y - b.x*a.y; }
il Point operator*( const Point &a , const ld &b ){ return {a.x*b,a.y*b}; }
il Point operator/( const Point &a , const ld &b ){ return {a.x/b,a.y/b}; }
il bool operator==( const Point &a , const Point &b ){ return fabs(a.x-b.x)<Eps and fabs(a.y-b.y)<Eps; }
il ld Dis( const Point &a , const Point &b ){ return sqrt((ld)Sqr(a.x-b.x)+Sqr(a.y-b.y)); }
il ld Dis2( const Point &a , const Point &b ){ return Sqr(a.x-b.x)+Sqr(a.y-b.y); }
ostream& operator<<( ostream &out , const Point &p ){
	out << p.x << " " << p.y << "  ";
	return out;
}
il bool TurnLeft( const Point &a , const Point &b , const Point &c ){ return (b-a)*(c-b) > Eps; }
il bool TurnRight( const Point &a , const Point &b , const Point &c ){ return (b-a)*(c-b) < -Eps; }
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
constexpr int MAXN = 1048576;

int n;
int a[MAXN];
ld b[MAXN];

ld s[MAXN];
bool onHull[MAXN];
void GetHull(){
	For(i,n) s[i] = s[i-1] + a[i];
	static vc<pair<Point,int>> hull;
	hull.Pb({{0,0},0});
	For(i,n){
		Point curP = {i,s[i]};
		while( hull.size() >= 2 and TurnRight(hull[hull.size()-2].F,hull.back().F,curP) )
			hull.pop_back();
		hull.Pb({curP,i});
	}
	for( auto [p,id] : hull )
		onHull[id] = 1;
}

int main(){
	FILEIO();

	Read(n);
	Read(a,1,n);

	GetHull();
	// Print(onHull,1,n);

	for( int l = 1 ; l <= n ; ){
		pair<ld,int> minAvg = {1e19,-1};
		ld tsum = 0;
		Forx(r,l,n){
			tsum += a[r];
			if(onHull[r]){
				pair<ld,int> t = {tsum/(r-l+1),r};
				minAvg = t;
				break;
			}
		}
		Forx(i,l,minAvg.S) b[i] = minAvg.F;
		l = minAvg.S+1;
	}

	For(i,n)
		printf("%.8lf\n",b[i]);

	END();
}