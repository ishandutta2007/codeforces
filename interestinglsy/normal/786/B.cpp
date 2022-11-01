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
#define TREE 3600010

struct Edge{
	int to;
	ll cost;
	Edge(){}
	Edge( int ti , ll ci ){
		to = ti; cost = ci;
	}
};

#define ROOT(i) 1,n,rt[i]
#define LSON l,l+r>>1,tree[pos].l
#define RSON (l+r>>1)+1,r,tree[pos].r
#define ARG int l , int r , int &pos
struct Node{ int l,r; };
Node tree[TREE];
int rt[4], nodecnt = 0;

int n,q,st;
vc<Edge> e[TREE];

void Link( int gl , int gr , int v , ll cost , bool dir , ARG ){	// dir=0 : v->[gl,gr]; dir=1 : [gl,gr]->v.
	if( gr < l  ||  r < gl ) return;
	if( gl <= l  &&  r <= gr ){
		//cout << l << " " << r << "  " << v << endl;
		if(!dir) e[v].Pb(Edge(pos,cost));
		else e[pos].Pb(Edge(v,cost));
		return;
	}
	Link(gl,gr,v,cost,dir,LSON);
	Link(gl,gr,v,cost,dir,RSON);
}
int intree[MAXN][3];
void Build( int d , bool dir , ARG){
	if(!pos){
		pos = ++nodecnt;
		tree[pos].l = tree[pos].r = 0;
	}
	if( l == r ){
		//cout << l << " " << pos << endl;
		intree[l][d] = pos;
		return;
	}
	Build(d,dir,LSON);
	Build(d,dir,RSON);
	if(!dir){
		e[pos].Pb(Edge(tree[pos].l,0));
		e[pos].Pb(Edge(tree[pos].r,0));
	}else{
		e[tree[pos].l].Pb(Edge(pos,0));
		e[tree[pos].r].Pb(Edge(pos,0));
	}
}

#define pli pair<ll,int>
ll dis[TREE];
priority_queue< pli , vc< pli > , greater< pli > > pq;
bool vis[TREE];
void Dijkstra( int st ){
	Ms(vis);
	Msn(dis,INF);
	pq.push(Mp(0,st));
	dis[st] = 0;
	while(!pq.empty()){
		int u = pq.top().S;
		pq.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		For0(i,e[u].size()){
			Edge now = e[u][i];
			int v = now.to;
			if( dis[v] > dis[u]+now.cost ){
				dis[v] = dis[u]+now.cost;
				pq.push(Mp(dis[v],v));
			}
		}
	}
	For(i,n)
		if( dis[intree[i][0]] >= LINF )
			dis[intree[i][0]] = -1;
}

int main(){
	FILEIO();
	
	Read(n,q,st);
	Build(0,0,ROOT(0));
	Build(1,1,ROOT(1));
	//For(i,n) cout << intree[i][0] << " "; cout << endl;
	//For(i,n) cout << intree[i][1] << " "; cout << endl;
	For(i,n){
		e[intree[i][0]].Pb(Edge(intree[i][1],0));
		e[intree[i][1]].Pb(Edge(intree[i][0],0));
	}
	
	For(i,q){
		int tp;
		ll w;
		Read(tp);
		if( tp == 1 ){
			int v,u;
			Read(v,u);
			Read(w);
			e[intree[v][0]].Pb(Edge(intree[u][0],w));
		}else{
			int v,l,r;
			Read(v,l,r);
			Read(w);
			if( tp == 2 ){
				Link(l,r,intree[v][0],w,0,ROOT(0));
			}else{
				Link(l,r,intree[v][1],w,1,ROOT(1));
			}
		}
	}
	
	Dijkstra(intree[st][0]);
	For(i,n)
		printf("%I64d ",dis[intree[i][0]]);
	printf("\n");
	
	END();
}