#include <bits/stdc++.h>
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

int n,q;

#define TREE 12600260
#define ARG int l , int r , int &pos
#define LSON l,l+r>>1,tree[pos].l
#define RSON (l+r>>1)+1,r,tree[pos].r
#define ROOT(i) 1,n,rt[i]
struct Node{ int l,r,v,lz; };
Node tree[TREE];
int rt[30], nodecnt = 0;
void Init( int pos ){
	tree[pos].l = tree[pos].r = tree[pos].v = 0;
	tree[pos].lz = -1;
}
void Update(ARG){
	tree[pos].v = tree[tree[pos].l].v + tree[tree[pos].r].v;
}
void Pushdown(ARG){
	if( tree[pos].lz == -1 ) return;
	if( l == r ){
		tree[pos].lz = -1;
		return;
	}
	int mid = l+r >> 1;
	int lenl = mid - l + 1, lenr = r-mid;
	if(!tree[pos].l){
		tree[pos].l = ++nodecnt;
		Init(tree[pos].l);
	}
	if(!tree[pos].r){
		tree[pos].r = ++nodecnt;
		Init(tree[pos].r);
	}
	tree[tree[pos].l].v = tree[pos].lz*lenl;
	tree[tree[pos].l].lz = tree[pos].lz;
	tree[tree[pos].r].v = tree[pos].lz*lenr;
	tree[tree[pos].r].lz = tree[pos].lz;
	tree[pos].lz = -1;
}
void Change( int gpos , int x , ARG ){
	if(!pos){
		pos = ++nodecnt;
		Init(pos);
	}
	tree[pos].v += x;
	if( l == r ) return;
	int mid = l+r >> 1;
	if( gpos <= mid ) Change(gpos,x,LSON);
	else Change(gpos,x,RSON);
}
int Query( int gl , int gr , ARG ){
	if(!pos) return 0;
	Pushdown(l,r,pos);
	if( gr < l  ||  r < gl ) return 0;
	if( gl <= l  &&  r <= gr ) return tree[pos].v;
	return Query(gl,gr,LSON) + Query(gl,gr,RSON);
}
void Change( int gl , int gr , int val , ARG ){
	if(!pos){
		pos = ++nodecnt;
		Init(pos);
	}
	Pushdown(l,r,pos);
	if( gr < l  ||  r < gl ) return;
	if( gl <= l  &&  r <= gr ){
		int len = r-l+1;
		tree[pos].v = val*len;
		tree[pos].lz = val;
		return;
	}
	Change(gl,gr,val,LSON);
	Change(gl,gr,val,RSON);
	Update(l,r,pos);
}

int app[MAXN];
void Out(){
	For(i,n){
		For(j,26){
			if( Query(i,i,ROOT(j)) ){
				printf("%c",j+'a'-1);
				break;
			}
		}
	}
	printf("\n");
}

int main(){
	FILEIO();
	tree[0].v = 0;
	
	Read(n,q);
	For(i,n){
		char c;
		In.Readalpha(c);
		c -= ('a'-1);
		Change(i,1,ROOT(c));
	}
	For(i,q){
		int l,r,x;
		Read(l,r,x);
		Ms(app);
		
		For(i,26){
			app[i] = Query(l,r,ROOT(i));
			if(app[i])
				Change(l,r,0,ROOT(i));
		}

		if(!x){
			// non-inc
			int p = l;
			fOR(i,26){
				if(!app[i]) continue;
				Change(p,p+app[i]-1,1,ROOT(i));
				p += app[i];
			}
			//O(p);
			assert( p == r+1 );
		}else{
			int p = l;
			For(i,26){
				if(!app[i]) continue;
				Change(p,p+app[i]-1,1,ROOT(i));
				p += app[i];
			}
			//O(p);
			assert( p == r+1 );
		}
	}
	Out();
	
	END();
}