#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <iomanip>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <set>
#include <map>
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
#define All(x) x.begin(),x.end()

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

// Read
struct InputReader{
	#define bs 1000001
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
	Fin((pname+".in").c_str());
	#ifndef intLSY
		Fout((pname+".out").c_str());
	#endif
}
void Printtime(){
	#ifdef intLSY
		double _timeuse = clock()* 1000.0 / CLOCKS_PER_SEC;
		printf("\n\nTime usage:\n%.0lf ms\n",_timeuse);
	#endif
}
void END(){ Printtime(); exit(0); }
_tp<_tyn T>void END( T mes ){ cout << mes << endl; END(); }


// Loop
#define For(i,j) for( int (i) = 1 ; (i) <= (j) ; ++(i) )
#define For0(i,j) for( int (i) = 0 ; (i) < (j) ; ++(i) )
#define Forx(i,j,k) for( int (i) = (j) ; (i) <= (k) ; ++(i) )
#define Forstep(i,j,k,st) for( int (i) = (j) ; (i) <= (k) ; (i) += (st) )
#define fOR(i,j) for( int (i) = (j) ; (i) >= 1 ; --(i) )
#define fOR0(i,j) for( int (i) = (j)-1 ; (i) >= 0 ; --(i) )
#define fORx(i,j,k) for( int (i) = (k) ; (i) >= (j) ; --(i) )


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
#define abs(a) ((a)<0?(~(a)+1):(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
//#define swap(a,b) {a=a^b;b=a^b;a=a^b;}
#define Mymax(a,b) (a) = max((a),(b))
#define Mymin(a,b) (a) = min((a),(b))
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
#define MOD 998244353
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#define MAXN 256

int n,m;
int a[MAXN][MAXN];
int totid;
int rowid[MAXN][2], colid[MAXN][2];

int dsu[1000000], sz[1000000];
vc<pii> ops;
void Init(){
	For(i,totid){
		dsu[i] = i;
		sz[i] = 1;
		ops.clear();
	}
}
int Findfa( int pos , bool force ){
	if(force) return dsu[pos] == pos ? pos : dsu[pos] = Findfa(dsu[pos],1);
	return dsu[pos] == pos ? pos : Findfa(dsu[pos],0);
}
il void Unite( int a , int b , bool force ){
	a = Findfa(a,force);
	b = Findfa(b,force);
	if( sz[a] > sz[b] ) swap(a,b);
	dsu[a] = b;
	sz[b] += sz[a];
	if(!force) ops.Pb({a,b});
}
il void Undo(){
	int a,b;
	tie(a,b) = ops.back();
	ops.pop_back();
	dsu[a] = a;
	sz[b] -= sz[a];
}
il bool Same( int a , int b , bool force ){
	return Findfa(a,force) == Findfa(b,force);
}

void Let( int x , int y , int c , bool force = 0 ){
	int isdiff = a[x][y]!=c;
	if(isdiff){
		Unite(rowid[x][0],colid[y][1],force);
		Unite(rowid[x][1],colid[y][0],force);
	}else{
		Unite(rowid[x][0],colid[y][0],force);
		Unite(rowid[x][1],colid[y][1],force);
	}
}
bool Check( bool force = 0 ){
	For(i,n) if(Same(rowid[i][0],rowid[i][1],force)) return 0;
	For(i,m) if(Same(colid[i][0],colid[i][1],force)) return 0;
	return 1;
}

vc<int> e[1000000];
vc<int> boss;
bool sel[1000000];
void Dfs( int pos ){
	sel[pos] = 1;
	for( auto v : e[pos] ) Dfs(v);
}

int main(){
	FILEIO();

	Read(n,m);
	For(i,n)
		For(j,m){
			Read(a[i][j]);
		}
	int uid = 0;
	For(i,n){
		rowid[i][1] = ++uid;
		rowid[i][0] = ++uid;
	}
	For(j,m){
		colid[j][1] = ++uid;
		colid[j][0] = ++uid;
	}
	totid = uid;

	For(irow,n){
		Init();
		Forx(i,1,irow-1)
			For(j,m)
				Let(i,j,0,1);
		Forx(i,irow+1,n)
			For(j,m)
				Let(i,j,1,1);
		if(!Check(1)) continue;
		Forx(last0,0,m){
			For(j,last0){
				Let(irow,j,0);
			}
			Forx(j,last0+1,m){
				Let(irow,j,1);
			}
			if(Check()){
				puts("YES");
				/*
				Forx(i,1,irow-1){
					For(j,m) putchar('0');
					putchar(10);
				}
				For(i,last0) putchar('0');
				Forx(j,last0+1,m) putchar('1');
				putchar(10);
				Forx(i,irow+1,n){
					For(j,m) putchar('1');
					putchar(10);
				}
				*/
				For(i,totid){
					if( dsu[i] != i ) e[dsu[i]].Pb(i);
					else{
						boss.Pb(i);
					}
				}
				Dfs(boss[0]);
				For(i,n) putchar(sel[rowid[i][0]]?'0':'1'); putchar(10);
				For(i,m) putchar(sel[colid[i][0]]?'0':'1'); putchar(10);
				END();
			}
			For(i,2*m) Undo();
		}
	}
	puts("NO");

	END();
}
////////////////////////////////////////////////