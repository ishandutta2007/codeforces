#include <bits/stdc++.h>
#define F first
//#define S second
#define dq deque
#define vc vector
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
#define Pb push_back
#define Mp make_pair
#define ll long long
#define _tp template
#define _tyn typename
#define Pf push_front
#define itor iterator
#define sint short int
#define ull unsigned ll
#define pii pair<int,int>
#define uint unsigned int
#define All(x) x.begin(),x.end()
#define B cout << "BreakPoint" << endl;
#define Fin(a) freopen(a,"r",stdin)
#define Fout(a) freopen(a,"w",stdout)
#define Ms(_data) memset(_data,0,sizeof(_data))
#define Msn(_data,_num) memset(_data,_num,sizeof(_data))
#define Fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define O_(x) cout << #x << " " << x << "  ";
#define O(x) cout << #x << " " << x << endl;
using namespace std;
#define Mymax(a,b) if(a<b) a = b;
#define Mymin(a,b) if(a>b) a = b;
void Print(int _x){printf("%d\n",_x);}
void Print(ll _x){printf("%lld\n",_x);}
_tp<_tyn T>void Print( T _a[] , int _s , int _t ){
	for( int i = _s ; i <= _t ; i++ )
		cout << _a[i] << " ";
   	cout << endl;
}
#define il inline
#define rg register
struct InputReader{
	static const int bs = 100000;
	char buf[bs];
	int p;
	il InputReader():p(bs) {}
	il void Flush(){
		p = 0;
		fread(buf, 1, bs, stdin);
	}
	il char C(){
		if(p >= bs) Flush();
		return buf[p++];
	}
	int Getnum(){
		char ch = C();
		while( ch < '0'  ||  ch > '9' ) ch = C();
		return (int)(ch-'0');
	}
	il int operator() (){
		int ans = 0;
		char ch = C();
		int fu = 1;
		while( ch < '0'  ||  ch > '9' ){
			if( ch == '-' ) fu = -1;
			ch = C();
		}
		while( ch >= '0'  &&  ch <= '9' ){
			ans *= 10;
			ans += ch-'0';
			ch = C();
		}
		return ans * fu;
	}
	ll Readll(){
		ll ans = 0LL;
		ll fu = 1;
		char ch = C();
		while( ch < '0'  ||  ch > '9' ){
			if( ch == '-' ) fu = -1;
			ch = C();
		}
		while( ch >= '0'  &&  ch <= '9' ){
			ans *= 10LL;
			ans += ch-'0';
			ch = C();
		}
		return ans * fu;
	}
	il void Readstring( string &x ){
		x.clear();
		char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch) ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch) ){
			x += ch;
			ch = C();
		}
	}
	il void Readalpha( char &c ){
		c = C();
		while( !isalpha(c) ) c = C();
	}
	il void Specialread( char &c ){
		c = C();
		while( c != 'o'  &&  c != 'x'  &&  c != '?' ) c = C();
	}
}In;
il void Read( int &x ){ x = In(); }
il void Read( int &x, int &y ){ x = In(); y = In(); }
il void Read( int &x1 , int &x2 , int &x3 ){
	x1 = In(); x2 = In(); x3 = In();
}
il void Read( int &x1 , int &x2 , int &x3 , int &x4 ){
	x1 = In(); x2 = In(); x3 = In(); x4 = In();
}
il void Read( ll &x ){ x = In.Readll(); }
il void Read( ll &x, ll &y ){ x = In.Readll(); y = In.Readll(); }
il void Read( ll &x1 , ll &x2 , ll &x3 ){
	x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll();
}
il void Read( ll &x1 , ll &x2 , ll &x3 , ll &x4 ){
	x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); x4 = In.Readll();
}
clock_t _starttime , _endtime;
il void FILEIO(){
	#ifdef InterestingLSY
		_starttime = clock();
		Fin("in.in");
	#endif
}
il void END(){
	#ifdef InterestingLSY
		_endtime = clock();
		double _timeuse = (_endtime-_starttime)* 1000.0 / CLOCKS_PER_SEC;
		printf("\n\nTime usage:\n%.0lf ms\n",_timeuse);
	#endif
	exit(0);
}
#define For(i,j) for( rg int (i) = 1 ; (i) <= (j) ; (i)++ )
#define For0(i,j) for( rg int (i) = 0 ; (i) < (j) ; (i)++ )
#define Forx(i,j,k) for( rg int (i) = (j) ; (i) <= (k) ; (i)++ )
#define Forstep(i,j,k,st) for( rg int (i) = (j) ; (i) <= (k) ; (i) += (st) )
#define fOR(i,j) for( rg int (i) = (j) ; (i) >= 1 ; (i)-- )
#define fOR0(i,j) for( rg int (i) = (j)-1 ; (i) >= 0 ; (i)-- )
#define fORx(i,j,k) for( rg int (i) = (j) ; (i) >= (k) ; (i)-- )
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
//			D L U  R
#define Mymod(a,b) if( a >= b ) a -= b;
#define Rmod(a,b) a = (a%b+b)%b
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#define MAXN 150010

int n;
int a[MAXN], b[MAXN];


bool Ok( int x ){
	Forx(i,2,n)
		if( (a[i]%x)  &&  (b[i]%x) ) return 0;
	return 1;
}
bool Isp( int x ){
	int sqt = sqrt(x);
	Forx(i,2,sqt)
		if( x%i == 0 ) return 0;
	return 1;
}
int Solve( int x ){
	int sqt = sqrt(x);
	if(Ok(x)) return x;
	Forx(i,2,sqt){
		if(x%i) continue;
		if( Isp(i)  &&  Ok(i)) return i;
		if( Isp(x/i) && Ok(x/i)) return x/i;
	}
	return -1;
}

void Gen(){
	Fout("in.in");
	cout << 150000 << endl;
	cout << "1396755360 1862340480" << endl;
	For(i,150000){
		cout << "112550881 1862340480" << endl;
	}
	END();
}

int main(){
	FILEIO();
	//Gen();


	Read(n);
	For(i,n){
		Read(a[i],b[i]);
	}//O(n);

	int ans1 = Solve(a[1]);
	if( ans1 == -1 ) cout << Solve(b[1]) << endl;
	else cout << ans1 << endl;

	END();
}