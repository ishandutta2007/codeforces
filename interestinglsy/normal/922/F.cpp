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
	il char Specialread(){
		char ch = C();
		while( ch != '1'  &&  ch != '0'  &&  ch != '*' ) ch = C();
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
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#define MAXN 300100

int n,k;

int tot = 0;
vc<int> e[MAXN];
void Count(){
	For(i,n)
		Forstep(j,i+i,n,i){
			e[j].Pb(i);
			tot++;
		}
	if( tot < k ){
		printf("No\n");
		END();
	}

	/*
	For(i,n){
		For0(j,e[i].size())
			cout << e[i][j] << " ";
		cout << endl;
	}
	*/
}

bool choose[MAXN];
bool Dfs( int pos , int sel ){
	if( sel == k )
		return 1;

	if( pos > n  ||  sel > k ) return 0;

	choose[pos] = 1;
	int cnt = 0;
	For0(i,e[pos].size())
		cnt += (int)(choose[e[pos][i]]);
	if( Dfs(pos+1,sel+cnt) ) return 1;

	choose[pos] = 0;
	return Dfs(pos+1,sel);
}

void Solve(){
	bool st = Dfs(1,0);
	if(!st){
		printf("No\n");
		END();
	}
	int ans = 0;
	For(i,n)
		ans += (int)(choose[i]);

	printf("Yes\n%d\n",ans);
	For(i,n)
		if( choose[i] )
			printf("%d ",i);
	printf("\n");
}

int main(){
	FILEIO();

	Read(n,k);

	Count();
	Solve();

	END();
}