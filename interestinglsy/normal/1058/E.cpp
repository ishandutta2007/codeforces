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
#define MAXN 300010
int Popcount( ll x ){
	int ret = 0;
	while(x){
		if(x&(1LL)) ret++;
		x >>= 1LL;
	}
	return ret;
}

int n;
int a[MAXN];
ll ans = 0;
int suf[MAXN], cnt[MAXN][2];

int main(){
	FILEIO();

	Read(n);
	For(i,n){
		ll x;
		Read(x);
		a[i] = Popcount(x);
	}
	suf[n+1] = 0;
	cnt[n+1][0] = 1;
	fOR(i,n){
		suf[i] = suf[i+1] + a[i];
		cnt[i][0] = cnt[i+1][0];
		cnt[i][1] = cnt[i+1][1];
		if(suf[i]&1) cnt[i][1]++;
		else cnt[i][0]++;
	}
	//Print(a,1,n);
/*
	For0(i,2){
		For(j,n+1)
			cout << cnt[j][i] << " ";
		cout << endl;
	}
*/

	For(i,n-1){
		int tans = cnt[i+2][suf[i]&1];
		int sum = a[i], maxa = a[i];//O_(suf[i]);O(tans);
		Forx(j,i+1,min(i+62,n)){
			Mymax(maxa,a[j]);
			sum += a[j];
			if(sum&1) continue;
			if( sum-maxa < maxa ) tans--;
			//else if( i == j-1 ) tans--;
		}//O(tans);
		ans += (ll)tans;
	}

	printf("%lld\n",ans);

	END();
}