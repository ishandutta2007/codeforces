#include <bits/stdc++.h>
#define F first
#define S second
#define vc vector
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))
#define Pb push_back
#define Mp make_pair
#define ll long long
#define _tp template
#define _tyn typename
#define Pf push_front
#define ull unsigned ll
#define pii pair<int,int>
#define ld double
#define Sqr(x) ((x)*(x))
#define All(x) x.begin(),x.end()
#define B cout << "BreakPoint" << endl;
#define Fin(a) freopen(a,"r",stdin)
#define Fout(a) freopen(a,"w",stdout)
#define Ms(_data) memset(_data,0,sizeof(_data))
#define Msn(_data,_num) memset(_data,_num,sizeof(_data))
#define O_(x) cout << #x << " " << x << "  ";
#define O(x) cout << #x << " " << x << endl;
using namespace std;
#define Mymax(a,b) a = max(a,b)
#define Mymin(a,b) a = min(a,b)
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
        while( !isdigit(ch)  &&  !isalpha(ch)  &&  ch != '_' ) ch = C();
        while( isdigit(ch)  ||  isalpha(ch)  ||  ch == '_' ){
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
        while( c != '/'  &&  c != '\\'  &&  c != 'A'  &&  c != 'B' ) c = C();
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
//          D L U  R
#define Mymod(a,b) if( a >= b ) a -= b;
#define Rmod(a,b) a = (a%b+b)%b
#define Dis2(x1,y1,x2,y2) (Sqr((x1)-(x2))+Sqr((y1)-(y2)))
#define Dis(x1,y1,x2,y2) (sqrt(Dis2(x1,y1,x2,y2)))
#define ERR(x) cout << "ERR! #" << x << endl
#define Msz(x) cout << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#define MAXN 200010

int n,h;
int l[MAXN], r[MAXN];
vc<pii> g;

int ans = h, tans = 0;
int Partgx( int f , int s , int h ){
	if( h >= s ) return f+s;
	return f+h;
}
int Need( int s , int hi ){
	if( s > hi ) return hi;
	return s;
}

int main(){
	FILEIO();

	Read(n,h);
	For(i,n) Read(l[i],r[i]);
	l[n+1] = 2000233000;

	g.Pb(Mp(233,233));
	For(i,n){
		g.Pb(Mp(r[i]-l[i],l[i+1]-r[i]));
	}
	//cout << g[g.size()-1].S << endl;

	int st = 1;
	int hi = h;
	int ed = 1;
	while(1){
		if( hi <= g[ed].S ){
			ans = tans + g[ed].F + hi;
			break;
		}else{
			hi -= g[ed].S;
			tans += g[ed].F + g[ed].S;
			ed++;
		}
	}
	//O(tans);O(ans);

	Forx(st,2,g.size()-1){
		int uf = g[st].F, us = g[st].S;
		int vf = g[st-1].F, vs = g[st-1].S;
		if( h > vs ){
			tans -= vf + vs;
			hi += vs;
		}
		if( ed < st ){
			ed = st;
			hi = h;
			tans = 0;
		}
		while(1){
			if( hi <= g[ed].S ){
				int ttans = tans + g[ed].F + hi;//O(ttans);
				Mymax(ans,ttans);
				break;
			}else{
				hi -= g[ed].S;
				tans += g[ed].F + g[ed].S;
				ed++;
			}
		}
	}

	printf("%d\n",ans);

	END();
}