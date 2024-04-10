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
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
const int MAXN = 64;
const int MAXD = 8192;

bool Ask( int x1 , int y1 , int x2 , int y2 ){
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	fflush(stdout);
	int res;
	cin >> res;
	if( res == -1 ) while(1);
	return res;
}

int n;
int id[MAXN][MAXN][2];

int dsu[MAXD];
void Init(){
	For0(i,MAXD) dsu[i] = i;
}
int Findfa( int pos ){
	return dsu[pos] == pos ? pos : dsu[pos] = Findfa(dsu[pos]);
}
il bool Unite( int a , int b ){
	a = Findfa(a); b = Findfa(b);
	if( a == b ) return 0;
	dsu[a] = b;
	return 1;
}
bool IsNumDiff( int x1 , int y1 , int x2 , int y2 ){
	return Findfa(id[x1][y1][0]) != Findfa(id[x2][y2][0]);
}

int ansl[MAXD];

void SaveMe( int p ){
	bool s1 = Ask(p,p,p+2,p+1);
	bool s2 = Ask(p+1,p,p+2,p+2);
	if(s1){
		Unite(id[p][p][0],id[p+2][p+1][0]);
		Unite(id[p][p][1],id[p+2][p+1][1]);
		return;
	}
	if(s2){
		Unite(id[p+1][p][0],id[p+2][p+2][0]);
		Unite(id[p+1][p][1],id[p+2][p+2][1]);
		return;
	}
	if(!IsNumDiff(p,p,p+1,p+1)){
		Unite(id[p][p][0],id[p+2][p+1][1]);
		Unite(id[p][p][1],id[p+2][p+1][0]);
	}else{
		Unite(id[p][p][0],id[p+1][p][0]);
		Unite(id[p][p][1],id[p+1][p][1]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	Msn(ansl,-1);

	cin >> n;
	int uid = 0;
	For(i,n) For(j,n){
		id[i][j][0] = ++uid;
		id[i][j][1] = ++uid;
	}
	Init();

	Unite(id[1][1][0],id[n][n][1]);
	Unite(id[1][1][1],id[n][n][0]);

	For(i,n-1)
		For(j,n-1){
			if( i == n-1 and j == n-1 ) continue;
			bool same = Ask(i,j,i+1,j+1);
			if(same){
				Unite(id[i][j][0],id[i+1][j+1][0]);
				Unite(id[i][j][1],id[i+1][j+1][1]);
			}else{
				Unite(id[i][j][0],id[i+1][j+1][1]);
				Unite(id[i][j][1],id[i+1][j+1][0]);
			}
		}
	Forstep(i,1,n-2,1){
		bool same = Ask(i,1,i+2,1);
		if(same){
			Unite(id[i][1][0],id[i+2][1][0]);
			Unite(id[i][1][1],id[i+2][1][1]);
		}else{
			Unite(id[i][1][0],id[i+2][1][1]);
			Unite(id[i][1][1],id[i+2][1][0]);
		}
	}
	Forstep(j,1,n-2,1){
		bool same = Ask(1,j,1,j+2);
		if(same){
			Unite(id[1][j][0],id[1][j+2][0]);
			Unite(id[1][j][1],id[1][j+2][1]);
		}else{
			Unite(id[1][j][0],id[1][j+2][1]);
			Unite(id[1][j][1],id[1][j+2][0]);
		}
	}

	{
		bool same = Ask(1,2,3,2);
		if(same){
			Unite(id[1][2][0],id[3][2][0]);
			Unite(id[1][2][1],id[3][2][1]);
		}else{
			Unite(id[1][2][0],id[3][2][1]);
			Unite(id[1][2][1],id[3][2][0]);
		}
	}

	For(i,n){
		if(!IsNumDiff(1,1,i,i)){
			int j = i+2;
			if( j == n or IsNumDiff(1,1,j,j) ){
				SaveMe(i);
				break;
			}
		}
	}

	cout << "!" << endl;
	int god = Findfa(id[1][1][1]);
	For(i,n){
		For(j,n){
			int fa0 = Findfa(id[i][j][0]);
			int fa1 = Findfa(id[i][j][1]);
			if( fa0 == god or (i==n&&j==n) ) cout << "0";
			else if( fa1 == god ) cout << "1";
			else assert(0);
		}
		cout << endl;
	}

	END();
}