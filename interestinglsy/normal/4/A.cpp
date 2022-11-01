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
#ifdef InterestingLSY
	#include <windows.h>
	#include <psapi.h>
#endif
il void END(){
	#ifdef InterestingLSY
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
#define fORx(i,j,k) for( rg int (i) = (k) ; (i) >= (j) ; (i)-- )
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
//			D L U  R
#define Mymod(a,b) if( a >= b ) a -= b;
#define Rmod(a,b) a = (a%b+b)%b
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#define MAXN 100010
#define ld double

int n;
ld s,a[MAXN],b[MAXN],r[MAXN];

ld dp[MAXN];
#define X(i) (dp[i]*r[i]/(a[i]*r[i]+b[i]))
#define Y(i) (dp[i]/(a[i]*r[i]+b[i]))
#define Slope(i,j) ((Y(i)-Y(j))/(X(i)-X(j)))
#define K(i) (-a[i]/b[i])

int q[MAXN<<1];
int f = 1, t = 1;

void Check(){
	Forx(i,f,t-3){
		ld k1 = Slope(q[i],q[i+1]);
		ld k2 = Slope(q[i+1],q[i+2]);
		if( k1 < k2 ){
			cout << "????" << endl;
			assert(0);
		}
	}
}
int Findtan( ld k ){
	//cout << "[Findtan]" << endl;
	//cout << "k: " << k << endl;
	/*
	cout << "list: ";
	Forx(i,f,t-2)
		cout << Slope(q[i],q[i+1]) << " ";
	cout << endl;
	Check();
	*/

	if( t-f <= 1 ) return f;
	ld stslope = Slope(q[f],q[f+1]);
	ld edslope = Slope(q[t-2],q[t-1]);
	//cout << stslope << " " << edslope << endl;
	if( k >= stslope ) return f;
	if( k <= edslope ) return t-1;
	Forx(i,f,t-3){
		ld k1 = Slope(q[i],q[i+1]), k2 = Slope(q[i+1],q[i+2]);
		if( k1 >= k  &&  k >= k2 ){
			return i+1;
		}
	}
	cout << "[Findtan] ???" << endl;
	cout << "list: ";
	Forx(j,f,t-2)
		cout << Slope(q[j],q[j+1]) << " ";
	cout << endl;
	assert(0);
	END();
}
int Adddot( int id , ld x ){
	ld stx = X(q[f]);
	ld edx = X(q[t-1]);
	if( x <= stx ){ q[--f] = id; return f; }
	if( x >= edx ){ q[t++] = id; return t-1; }
	Forx(i,f,t-2){
		if( X(q[i]) <= x  &&  x <= X(q[i+1]) ){
			t++;
			fORx(j,i+1,t-1) q[j] = q[j-1];
			q[i+1] = id;
			//O_(f);O_(t);O(i+1);
			return i+1;
		}
	}
	cout << "[Adddot] ???" << endl;
}
void Delete( int gpos ){
	Forx(i,gpos,t-1)
		q[i] = q[i+1];
	t--;
}
void Delete( int gpos , ld y ){
	if( gpos != t-1  &&  y < Y(q[gpos+1]) ){
		Delete(gpos);
		return;
	}
	fORx(i,f+1,gpos-1){
		if( Slope(q[i],q[gpos]) > Slope(q[i-1],q[i]) ){
			Delete(i);
			gpos--;
		}
	}
	Forx(i,gpos+1,t-2){
		if( Slope(q[gpos],q[i]) < Slope(q[i],q[i+1]) ){
			Delete(i);
			i--;
		}
	}
}

void Newdot( int i ){
	//cout << "------------------------------" << endl;
	//O(i);
	//cout << "q:  "; Print(q,f,t-1);

	dp[i] = max(s,dp[i-1]);
	ld nowk = K(i);

	// Find the Tangent Line
	int pos = Findtan(nowk);
	//cout << "[pos] " << f << " " << t << " " << pos << endl;
	//cout << Slope(q[pos],q[pos-1]) << "  " << Slope(q[pos],q[pos+1]) << endl << endl;

	int j = q[pos];
	Mymax(dp[i],X(j)*a[i]+Y(j)*b[i]);
	//cout << X(i) << " " << Y(i) << "  " << dp[i] << endl;
	// Add the Dot
	/*
	cout << "Before Adding: ";
	Print(q,f,t-1);
	Forx(j,f,t-1) cout << X(q[j]) << " "; cout << endl;
	Forx(j,f,t-1) cout << Y(q[j]) << " "; cout << endl;
	cout << "list: ";
	Forx(j,f,t-2)
		cout << Slope(q[j],q[j+1]) << " ";
	cout << endl;
	cout << endl;
	*/

	pos = Adddot(i,X(i));

	/*
	cout << "After Adding: ";
	Print(q,f,t-1);
	Forx(j,f,t-1) cout << X(q[j]) << " "; cout << endl;
	Forx(j,f,t-1) cout << Y(q[j]) << " "; cout << endl;
	cout << "list: ";
	Forx(j,f,t-2)
		cout << Slope(q[j],q[j+1]) << " ";
	cout << endl;
	cout << endl;
	*/

	// Delete Unnecessary Dots
	//cout << "q:  "; Print(q,f,t-1);
	//cout << pos << endl;
	Delete(pos,Y(i));
	/*
	cout << "After Deleting: ";
	Print(q,f,t-1);
	Forx(j,f,t-1) cout << X(q[j]) << " "; cout << endl;
	Forx(j,f,t-1) cout << Y(q[j]) << " "; cout << endl;
	cout << "list: ";
	Forx(j,f,t-2)
		cout << Slope(q[j],q[j+1]) << " ";
	cout << endl;
	cout << endl;
	*/
}

int main(){
	FILEIO();

Read(n);
if( n != 0  &&  !(n&1)  &&  n >= 4 ) printf("YES\n");
else printf("NO\n");
	END();
}