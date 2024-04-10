#include <bits/stdc++.h>
#define Sqr(x) ((x)*(x))
#define F first
#define S second
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
#define Ms(_data) memset(_data,0,sizeof(_data))
#define Fin(_filename) freopen(_filename,"r",stdin)
#define Fout(_filename) freopen(_filename,"w",stdout)
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
    il char C(){
        return getchar();
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
        //x += '\0';
    }
    il void Readalpha( char &c ){
        c = C();
        while( !isalpha(c) ) c = C();
    }
    il char Specialread(){
        char ch = C();
        while( !isalpha(ch) ) ch = C();
        return ch;
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
il void Read( ll &x ){
    x = In.Readll();
}
il void Read( ll &x, ll &y ){ x = In.Readll(); y = In.Readll(); }
il void Read( ll &x1 , ll &x2 , ll &x3 ){
    x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll();
}
il void Read( ll &x1 , ll &x2 , ll &x3 , ll &x4 ){
    x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); x4 = In.Readll();
}
clock_t _starttime , _endtime;
il void FILEIO(){
    #ifdef WIN32
        _starttime = clock();
        Fin("in.in");
    #endif
}
#ifdef WIN32
    #include <windows.h>
    #include <psapi.h>
#endif
il void END(){
    #ifdef WIN32
        _endtime = clock();
        double _timeuse = (_endtime-_starttime)* 1000.0 / CLOCKS_PER_SEC;
        printf("\n\nTime usage:\n%.0lf ms\n",_timeuse);
        HANDLE _handle = GetCurrentProcess();
        PROCESS_MEMORY_COUNTERS pmc;
        GetProcessMemoryInfo(_handle,&pmc,sizeof(pmc));
        double _memuse = pmc.PeakPagefileUsage/1024.00/1024.00;
        printf("Memory usage:\n%.1lf MB\n\n",_memuse);
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
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#define MAXN 100010
#define MAXM 100010
#define MAXC 200020
struct Ask{
	int l,r;
	int t,id;
};
Ask ask[MAXM];
int askcnt = 0;
struct Chg{
	int pos,x;
};
Chg chg[MAXM];
int chgcnt = 0;
int bsize;
int block[MAXN];
bool operator<( rg Ask o1 , rg Ask o2 ){
	if( block[o1.l] != block[o2.l] )
		return block[o1.l] < block[o2.l];
	if( block[o1.r] != block[o2.r] )
		return block[o1.r] < block[o2.r];
	return o1.t < o2.t;
}

int n,m;
int c[MAXM];

#define Lb(a) lower_bound(All(disc),a)-disc.begin()
vc<int> disc;
il void Disc(){
	For(i,n)
		disc.Pb(c[i]);
	For(i,chgcnt)
		disc.Pb(chg[i].x);

	sort(All(disc));
	disc.resize( unique(All(disc)) - disc.begin() );

	For(i,n)
		c[i] = Lb(c[i]);
	For(i,chgcnt)
		chg[i].x = Lb(chg[i].x);
}

int l,r,t;
int cnt[MAXC];
int cntcnt[MAXC];
int a;
il int Findans(){
	for( ; a <= MAXN+10 ; a++ )
		if(!cntcnt[a])
			return a;
	cout << "qwq?" << endl;
	END();
}
il void Add( int col , int delta ){
	cntcnt[cnt[col]]--;
	cnt[col] += delta;
	cntcnt[cnt[col]]++;
	if( a == cnt[col] )
		Findans();
	if(!cntcnt[cnt[col]-delta])
		Mymin(a,cnt[col]-delta);
}
il void Upd( int id ){
	id--;
	if(!id) return;
	Chg u = chg[id];
	if( l <= u.pos  &&  u.pos <= r )
		Add(chg[id].x,1);
	swap(c[u.pos],chg[id].x);
	if( l <= u.pos  &&  u.pos <= r )
		Add(chg[id].x,-1);
}
int ans[MAXM];
il void Solve(){
	Ms(cnt); Ms(cntcnt);
	l = r = t = 1;
	a = -2333;
	Add(c[1],1);
	cntcnt[0] = INF;
	a = 2;
	For(i,askcnt){
		Ask u = ask[i];
		while( r < u.r ){ Add(c[r+1],1); r++; }
		while( l > u.l ){ Add(c[l-1],1); l--; }
		while( t < u.t ){ Upd(t+1); t++; }
		while( t > u.t ){ Upd(t); t--; }
		while( r > u.r ){ Add(c[r],-1); r--; }
		while( l < u.l ){ Add(c[l],-1); l++; }
		ans[u.id] = Findans();
	}
}

int main(){
	FILEIO();

	Read(n,m);
	For(i,n)
		Read(c[i]);
	int tim = 1;
	For(i,m){
		int o;
		Read(o);
		if( o == 1 ){
			askcnt++;
			ask[askcnt].id = askcnt;
			Read(ask[askcnt].l,ask[askcnt].r);
			ask[askcnt].t = tim;
		}else{
			tim++;
			chgcnt++;
			Read(chg[chgcnt].pos,chg[chgcnt].x);
		}
	}

	bsize = pow(n,0.66667);
	int bb = 1;
	Forstep(i,1,n,bsize){
		For0(j,bsize){
			if( i+j > n ) break;
			block[i+j] = bb;
		}
		bb++;
	}
	sort(ask+1,ask+1+askcnt);

	Disc();
	Solve();

	For(i,askcnt){
		printf("%d\n",ans[i]);
	}

	END();
}