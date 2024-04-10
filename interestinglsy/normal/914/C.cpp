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
#define O(x) cerr << #x << " " << x << endl;
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
    char buf[bs]; int p;
    il InputReader():p(bs){}
    il void Flush(){
        p = 0;
        fread(buf,1,bs,stdin);
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
	il ll Readll(){
		ll ans = 0LL;
		char ch = Getnum()+'0';
        while( ch >= '0'  &&  ch <= '9' ){
            ans *= 10LL;
            ans += ch-'0';
            ch = C();
        }
        return ans;
	}
	il void Readstring( string &x ){
		x.clear();
		char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch) ) ch = C();
		int p = 0;
		while( isdigit(ch)  ||  isalpha(ch) ){
			x += ch;
			ch = C();
			p++;
		}
		x[p] = '\0';
	}
	il char Specialread(){
		char ch = C();
		while( ch != '+'  &&  ch != '?' ) ch = C();
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
clock_t _starttime,_endtime;
il void FILEIO(){
	#ifdef WIN32
		_starttime = clock();
		Fin("in.in");
	#endif
}
#ifdef WIN32
	#include <windows.h>
	#include <psapi.h>
	#pragma comment(lib,"Psapi.lib")
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
#define For(i,j) for( int (i) = 1 ; (i) <= (j) ; (i)++ )
#define For0(i,j) for( int (i) = 0 ; (i) < (j) ; (i)++ )
#define Forx(i,j,k) for( int (i) = (j) ; (i) <= (k) ; (i)++ )
#define fOR(i,j) for( int (i) = (j) ; (i) >= 1 ; (i)-- )
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#define MOD (1000000007LL)
#define MAXN 1010
int n[MAXN];
int k,len;

il ll Qpow( ll a , ll b ){
	a %= MOD;
	ll ret = 1LL;
	while(b){
		if(b&1){
			ret *= a;
			ret %= MOD;
		}
		a *= a;
		a %= MOD;
		b >>= 1LL;
	}
	return ret % MOD;;
}
il ll Inv( ll x ){
	return Qpow(x,MOD-2) % MOD;;
}

il ll Fact( ll a ){
	ll ret = 1LL;
	for( ll i = 2LL ; i <= a ; i++ ){
		ret *= i;
		ret %= MOD;
	}
	assert(ret>=0);
	return ret % MOD;
}
il ll C( int n , int m ){
	ll ret = 1LL;
	for( ll a = m+1 ; a <= n ; a++ ){
		ret *= a;
		ret %= MOD;
	}
	ret *= Inv(Fact(n-m));
	ret %= MOD;
	assert(ret>=0);
	return ret;
}
//x1
il int Tran( int x ){
	int ans = 0;
	while( x != 1 ){
		ans++;
		x = __builtin_popcount(x);
	}
	return ans;
}

ll mem[MAXN][MAXN][2];
il ll Dfs( int pos , int left1 , bool equal ){
	if( mem[pos][left1][equal] != -1 ){
		return mem[pos][left1][equal];
	}
	if( left1 < 0 ) return mem[pos][left1][equal] = 0;
	if( left1 > pos ) return mem[pos][left1][equal] = 0;
	if( pos == 0 ) return mem[pos][left1][equal] = 1;

	if( !equal ) return mem[pos][left1][equal] = (Dfs(pos-1,left1-1,0)+Dfs(pos-1,left1,0)) % MOD;//return Dfs(pos-1,left1-1,0) + Dfs(pos-1,left1,0);
	if( !n[pos] ){
		return mem[pos][left1][equal] = Dfs(pos-1,left1,1) % MOD;
	}
	return mem[pos][left1][equal] = (Dfs(pos-1,left1-1,1)+Dfs(pos-1,left1,0)) % MOD;
}

ll ans = 0LL;
int main(){
	FILEIO();
	Msn(mem,-1);

	string s;
	In.Readstring(s);
	reverse(s.begin(),s.end());
	len = s.length();
	For0(i,len) n[i+1] = s[i]-'0';
	Read(k);

	if( k == 0 ){
		printf("1\n");
		END();
	}
	if( k == 1 ){
		printf("%d\n",len-1);
		END();
	}

	//For(i,len-1)
	//	if( Tran(i)+1 == k )
	//		ans += C(len-1,i);

	For(i,len){
		if( Tran(i)+1 != k ) continue;
		//cout << i << endl;
		//cout << Dfs(len,i,1) << endl;
		ans += Dfs(len,i,1);
		ans %= MOD;
	}

	printf("%lld\n",ans);

	END();
}