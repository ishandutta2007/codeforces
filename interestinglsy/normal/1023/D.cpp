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
#define MAXN 200010
#define ARG int l , int r , int &pos
#define LSON l,l+r>>1,tree[pos].l
#define RSON (l+r>>1)+1,r,tree[pos].r
#define TREE MAXN<<5
#define ROOT(i) 1,q+2,root[i]
struct Node{ int l,r,v; };
Node tree[TREE];
int root[MAXN], nodecnt = 0;
void GG(){
	cout << "NO" << endl;
	END();
}

int n,q;

void Build(ARG){
	pos = ++nodecnt;
	tree[pos].v = 0;
	if( l == r ) return;
	Build(LSON);
	Build(RSON);
}
void Insert( int gnum , int old , ARG ){
	pos = ++nodecnt;
	tree[pos] = tree[old];
	tree[pos].v++;
	if( l == r ) return;
	int mid = l+r >> 1;
	if( gnum <= mid ) Insert(gnum,tree[old].l,LSON);
	else Insert(gnum,tree[old].r,RSON);
}
// <=gpos
int Query( int gpos , ARG ){
	if( l == r ) return tree[pos].v;
	int mid = l+r >> 1;
	if( gpos > mid ) return Query(gpos,RSON) + tree[tree[pos].l].v;
	return Query(gpos,LSON);
}
int Leq( int l , int r , int x ){
	x--;
	if(!x) return 0;
	//O(Query(x,ROOT(r)));
	return Query(x,ROOT(r)) - Query(x,ROOT(l-1));
}

int a[MAXN];
int minx[MAXN], maxx[MAXN];
int maxnum = 0,pos0;
bool have0 = 0;

#define SARG int l , int r , int pos
#define SL l,l+r>>1,pos<<1
#define SR (l+r>>1)+1,r,pos<<1|1
#define SROOT 1,n,1
#define SEG MAXN<<2
int seg[SEG];
void Pushdown(SARG){
	if( l == r ) return;
	if(!seg[pos]) return;
	seg[pos<<1] = seg[pos<<1|1] = seg[pos];
	seg[pos] = 0;
}
void Change( int gl , int gr , int x , SARG ){
	Pushdown(l,r,pos);
	if( gr < l  ||  r < gl ) return;
	if( gl <= l  &&  r <= gr ){
		seg[pos] = x;
		return;
	}
	Change(gl,gr,x,SL);
	Change(gl,gr,x,SR);
}
int Squery( int gpos , SARG ){
	Pushdown(l,r,pos);
	if( l == r ) return seg[pos];
	int mid = l+r >> 1;
	if( gpos <= mid ) return Squery(gpos,SL);
	return Squery(gpos,SR);
}

int main(){
	FILEIO();
	Msn(minx,INF);
	Ms(maxx);

	cin >> n >> q;
	Build(ROOT(0));
	For(i,n){
		cin >> a[i];
		Mymax(maxnum,a[i]);
		have0 |= (!a[i]);
		if(!a[i]) pos0 = i;
		if(!a[i]) a[i] = q+2;
		Insert(a[i],root[i-1],ROOT(i));
		Mymin( minx[a[i]] , i );
		Mymax( maxx[a[i]] , i );
	}

	For0(i,SEG) seg[i] = 1;
	//Change(1,n,1);
	Forx(i,2,q){
		if( minx[i] >= INF ){
			if( !have0  &&  i > maxnum ) GG();
			Change(pos0,pos0,i,SROOT);
			continue;
		}
		int l = minx[i], r = maxx[i];
		if( Leq(l,r,i) ){//O(a[i]);
			//cout << minx[i] << " " << maxx[i] << endl;
			GG();
		}
		Change(l,r,i,SROOT);
	}

	cout << "YES" << endl;
	For(i,n)
		cout << Squery(i,SROOT) << " ";
	cout << endl;

	END();
}