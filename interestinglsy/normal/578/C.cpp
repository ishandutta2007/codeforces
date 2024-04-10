#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#define F first
#define S second
#define vc vector
#define ld long double
#define Pb push_back
#define Mp make_pair
#define ll long long
#define _tp template
#define _tyn typename
#define Pf push_front
#define ull unsigned ll
#define INF (0x3f3f3f3f)
#define Sqr(x) ((x)*(x))
#define pii pair<int,int>
#define All(x) x.begin(),x.end()
#define Fin(a) freopen(a,"r",stdin)
#define Fout(a) freopen(a,"w",stdout)
#define B cout << "BreakPoint" << endl;
#define O(x) cout << #x << " " << x << endl;
#define O_(x) cout << #x << " " << x << "  ";
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
#define Ms(_data) memset(_data,0,sizeof(_data))
#define Msn(_data,_num) memset(_data,_num,sizeof(_data))
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define Mymax(a,b) (a) = max((a),(b))
#define Mymin(a,b) (a) = min((a),(b))
#define swap(a,b) {a=a^b;b=a^b;a=a^b;}
#define abs(a) ((a)<0?-(a):(a))
#define fu(a) (~(a) + 1)
_tp<_tyn T>void Print( T _a[] , int _s , int _t ){
    for( int i = _s ; i <= _t ; i++ )
        cout << _a[i] << " ";
    cout << endl;
}
#define il inline
#define rg register
struct InputReader{
    static const int bs = 1000001;
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
    il int Getnum(){
        char ch = C();
        while( ch < '0'  ||  ch > '9' ) ch = C();
        return (int)(ch-'0');
    }
    int operator() (){
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
        ll fu = 1LL;
        char ch = C();
        while( ch < '0'  ||  ch > '9' ){
            if( ch == '-' ) fu = -1LL;
            ch = C();
        }
        while( ch >= '0'  &&  ch <= '9' ){
            ans *= 10LL;
            ans += (ll)ch-'0';
            ch = C();
        }
        return ans * fu;
    }
    il void Readstring( string &x ){
        x.clear();
        char ch = C();
        while( !isdigit(ch)  &&  !isalpha(ch)  &&  ch != '_'  &&  ch != '.' ) ch = C();
        while( isdigit(ch)  ||  isalpha(ch)  ||  ch == '_'  ||  ch == '.' ){
            x += ch;
            ch = C();
        }
    }
	il void Readchstring( char s[] ){
		int len = 0;
		char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch)  /*&&  ch != '*'  &&  ch != '?'*/ ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch)  /*||  ch == '*'  ||  ch == '?'*/ ){
			s[len++] = ch;
			ch = C();
		}
		s[len] = '\0';
	}
    il void Readalpha( char &c ){
        c = C();
        while( !isalpha(c) ) c = C();
    }
    il void Specialread( char &c ){
        c = C();
        while( c != '.'  &&  c != 'W'  &&  c != 'A'  &&  c != 'B' ) c = C();
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
void END(){
	Printtime();
    exit(0);
}
_tp<_tyn T>void END( T mes ){
	cout << mes << endl;
	END();
}
#define For(i,j) for( rg int (i) = 1 ; (i) <= (j) ; ++(i) )
#define For0(i,j) for( rg int (i) = 0 ; (i) < (j) ; ++(i) )
#define Forx(i,j,k) for( rg int (i) = (j) ; (i) <= (k) ; ++(i) )
#define Forstep(i,j,k,st) for( rg int (i) = (j) ; (i) <= (k) ; (i) += (st) )
#define fOR(i,j) for( rg int (i) = (j) ; (i) >= 1 ; --(i) )
#define fOR0(i,j) for( rg int (i) = (j)-1 ; (i) >= 0 ; --(i) )
#define fORx(i,j,k) for( rg int (i) = (k) ; (i) >= (j) ; --(i) )
int dx4[] = {0,-1,0,1};
int dy4[] = {1,0,-1,0};
int dx8[] = {0,1,1,1,0,-1,-1,-1};
int dy8[] = {1,-1,0,1,-1,-1,0,1};
//          D L U  R
#define ERR(x) cout << "ERR! #" << x << endl
#define Msz(x) cout << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
// Maths
#define MOD 19260817LL
#define Rmoi(a,b) ((a)%b+b)%b
#define Lowbit(x) ((x)&(~(x)+1))
#define Rmo(a) ((a)%MOD+MOD)%MOD
#define Rmod(a) a = (a%MOD+MOD)%MOD
#define Rmodi(a,b) a = (a%(b)+(b))%(b)
#define Mymod(a) a = (a)>=MOD?((a)-MOD):(a)
#define Mymodi(a,b) a = ((a)>=(b))?((a)-(b)):(a)
#define Mdis(x1,y1,x2,y2) (abs(x1-x2)+abs(y1-y2))
#define Dis(x1,y1,x2,y2) (sqrt(Dis2(x1,y1,x2,y2)))
#define Dis2(x1,y1,x2,y2) (Sqr((x1)-(x2))+Sqr((y1)-(y2)))
_tp<_tyn T1,_tyn T2> T1 Pow( T1 a , T2 b ){
	T1 ret(1);
	while(b){ if(b&1) ret = ret * a; a = a*a; b >>= 1; }
	return ret;
}
ll Pow( ll a , int b ){
	ll ret(1);
	while(b){  if(b&1)(ret*=a) %= MOD; (a*=a) %= MOD; b >>= 1; }
	return ret;
}
_tp<_tyn T>T Gcd( T a , T b ){
	return b?Gcd(b,a%b):a;
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
#define Eps ((ld)(1e-12))
#define MAXN 200010

int n;
int a[MAXN];

ld b[MAXN];
ld dp[MAXN];
ld Cal( ld x ){
	For(i,n) b[i] = a[i]-x;

	ld maxa = -1000000000;
	dp[0] = 0;
	For(i,n){
		dp[i] = max(dp[i-1]+b[i],b[i]);
		Mymax(maxa,dp[i]);
	}

	ld mina = 1000000000;
	dp[0] = 0;
	For(i,n){
		dp[i] = min(dp[i-1]+b[i],b[i]);
		Mymin(mina,dp[i]);
	}
	//cout << maxa << " " << mina << endl;
	return max( abs(maxa) , abs(mina) );
}
ld Trichotomy(){
	ld l = -10010, r = 10010, midl, midr, ans = 1000000000;
	while( r-l >= Eps ){
		//cout << l << " " << r << endl;
		midl = (l+r)/2;
		midr = midl+Eps;

		ld ans1 = Cal(midl);
		ld ans2 = Cal(midr);
		Mymin(ans,ans1);
		Mymin(ans,ans2);

		if( ans1 > ans2 ) l = midr;
		else r = midl-Eps;
	}
	return ans;
}

int main(){
	FILEIO();
	//O(Cal(1));

	Read(n);
	For(i,n) Read(a[i]);

	ld ans = Trichotomy();
	printf("%.7Lf\n",ans);

	END();
}