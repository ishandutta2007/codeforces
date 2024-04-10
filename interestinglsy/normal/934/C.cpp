#include <bits/stdc++.h>
#define F first
#define S second
#define dq deque
#define vc vector
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f))
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
#define MAXN 2010

int n;
int dat[MAXN];
int cnt0[MAXN], cnt1[MAXN];
int ans = 1;

int sum0( int l , int r ){
    return cnt0[r] - cnt0[l-1];
}
int sum1( int l , int r ){
    return cnt1[r] - cnt1[l-1];
}

int dp[MAXN][MAXN];
int maxdp[MAXN][MAXN];
void Dp(){
    Ms(maxdp);
    For(i,n){
        dp[i][i] = 1;
        int nowmax = 1;
        maxdp[i][i] = 1;
        Forx(j,i+1,n){
            if( dat[j] == 0 ){
                dp[i][j] = nowmax+1;
            }else{
                dp[i][j] = sum1(i,j);
            }
            Mymax(nowmax,dp[i][j]);
            maxdp[i][j] = nowmax;
        }
    }
}

int Cal( int l , int r ){
    int ans = cnt0[l-1] + maxdp[l][r] + cnt1[n] - cnt1[r];
    return ans;
}

int main(){
	FILEIO();

    Read(n);
    For(i,n){
        Read(dat[i]);
        dat[i]--;
    }

    Ms(cnt0); Ms(cnt1);
    For(i,n){
        cnt0[i] = cnt0[i-1] + (dat[i]==0);
        cnt1[i] = cnt1[i-1] + (dat[i]==1);
    }

    Dp();
    
    For(i,n)
        Forx(j,i,n){
            int tans = Cal(i,j);
            Mymax(ans,tans);
        }
    printf("%d\n",ans);

	END();
}