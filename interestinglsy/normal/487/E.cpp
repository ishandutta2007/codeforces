#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <iomanip>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <set>
#include <map>
using namespace std;
#define il inline
#define rg register
#define elif else if

// Type
#define ld double
#define ll long long
#define ull unsigned ll

// Vector
#define vc vector
#define Pb push_back
#define Pf push_front
#define All(x) x.begin(),x.end()

// Memory
#define Ms(_data) memset(_data,0,sizeof(_data))
#define Msn(_data,_num) memset(_data,_num,sizeof(_data))

// Template
#define _cl class
#define _tp template
#define _tyn typename

// Pair
#define Mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>

// Read
struct InputReader{
	#define bs 1000001
	char buf[bs]; int p;
	il InputReader(){ p = bs; }
	il void Flush(){ p = 0; fread(buf,1,bs,stdin); }
	il char C(){ if(p >= bs) Flush(); return buf[p++]; }
	il char Readnum(){ char ch = C(); while( !isdigit(ch) && ch != '-' ) ch = C(); return ch; }
	il void Readalpha( char &c ){ c = C(); while( !isalpha(c) ) c = C(); }
	int operator() (){
		int ans = 0, fu = 1; char ch = Readnum();
		if( ch == '-' ) fu = -1, ch = C();
		while( ch >= '0' && ch <= '9' ){
			ans = ans*10 + ch-'0';
			ch = C();
		}
		return ans * fu;
	}
	ll Readll(){
		ll ans = 0LL, fu = 1LL; char ch = Readnum();
		if( ch == '-' ) fu = -1LL, ch = C();
		while( ch >= '0' && ch <= '9' ){
			ans = ans*10LL + ch-'0';
			ch = C();
		}
		return ans * fu;
	}
	il void Readstring( string &x ){
		x.clear(); char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch)  &&  ch != '-'  &&  ch != '.' ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch)  ||  ch == '-'  ||  ch == '.' ){
			x += ch;
			ch = C();
		}
	}
	il void Readchstring( char s[] ){
		int len = 0; char ch = C();
		while( !isdigit(ch)  &&  !isalpha(ch)  /*&&  ch != '*'  &&  ch != '?'*/ ) ch = C();
		while( isdigit(ch)  ||  isalpha(ch)  /*||  ch == '*'  ||  ch == '?'*/ ){
			s[len++] = ch;
			ch = C();
		}
		s[len] = '\0';
	}
	il void Specialread( char &c ){
		c = C();
		while( !isdigit(c) && !isalpha(c) && c != '#'  &&  c != '.'  &&  c != '='  &&  c != 'B' ) c = C();
	}
	#undef bs
}In;
il void Read( int &x ){ x = In(); }
il void Read( int &x, int &y ){ x = In(); y = In(); }
il void Read( int &x1 , int &x2 , int &x3 ){ x1 = In(); x2 = In(); x3 = In(); }
il void Read( int &x1 , int &x2 , int &x3 , int &x4 ){ x1 = In(); x2 = In(); x3 = In(); x4 = In(); }
il void Read( ll &x ){ x = In.Readll(); }
il void Read( ll &x, ll &y ){ x = In.Readll(); y = In.Readll(); }
il void Read( ll &x1 , ll &x2 , ll &x3 ){ x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); }
il void Read( ll &x1 , ll &x2 , ll &x3 , ll &x4 ){ x1 = In.Readll(); x2 = In.Readll(); x3 = In.Readll(); x4 = In.Readll(); }
#define iRead(k) int k; Read(k);
#define iRead2(a,b) iRead(a); iRead(b);
#define iRead3(a,b,c) iRead2(a,b); iRead(c);
#define iRead4(a,b,c,d) iRead2(a,b); iRead2(c,d);
#define lRead(k) ll k; Read(k);
#define lRead2(a,b) lRead(a); lRead(b);
#define lRead3(a,b,c) lRead2(a,b); lRead(c);
#define lRead4(a,b,c,d) lRead2(a,b); lRead2(c,d);

// File
#define Fin(a) freopen(a,"r",stdin)
#define Fout(a) freopen(a,"w",stdout)
il void FILEIO(){
	#ifdef intLSY
		Fin("in.in");
	#endif
}
il void FILEIO( string pname ){
	Fin((pname+".in").c_str());
	#ifndef intLSY
		Fout((pname+".out").c_str());
	#endif
}
void Printtime(){
	#ifdef intLSY
		double _timeuse = clock()* 1000.0 / CLOCKS_PER_SEC;
		printf("\n\nTime usage:\n%.0lf ms\n",_timeuse);
	#endif
}
void END(){ Printtime(); exit(0); }
_tp<_tyn T>void END( T mes ){ cout << mes << endl; END(); }


// Loop
#define For(i,j) for( rg int (i) = 1 ; (i) <= (j) ; ++(i) )
#define For0(i,j) for( rg int (i) = 0 ; (i) < (j) ; ++(i) )
#define Forx(i,j,k) for( rg int (i) = (j) ; (i) <= (k) ; ++(i) )
#define Forstep(i,j,k,st) for( rg int (i) = (j) ; (i) <= (k) ; (i) += (st) )
#define fOR(i,j) for( rg int (i) = (j) ; (i) >= 1 ; --(i) )
#define fOR0(i,j) for( rg int (i) = (j)-1 ; (i) >= 0 ; --(i) )
#define fORx(i,j,k) for( rg int (i) = (k) ; (i) >= (j) ; --(i) )


// Debug
#define B cerr << "BreakPoint" << endl;
#define O(x) cerr << #x << " " << x << endl;
#define O_(x) cerr << #x << " " << x << "  ";
#define ERR(x) cerr << "ERR! #" << x << endl;
#define Msz(x) cerr << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
_tp<_tyn T>void Print( T a[] , int s , int t , char sp = ' ' , char ed = '\n' ){
	if( s > t ) return;
	for( int i = s ; i < t ; i++ )
		cout << a[i] << sp;
	cout << a[t] << ed;
	cout.flush();
}
_tp<_tyn T>void Print( T a , int s = 0 , int t = -1 , char sp = ' ' , char ed = '\n' ){
	if( t == -1 ) t = a.size()-1;
	for( int i = s ; i <= t ; i++ )
		cout << a[i] << sp;
	cout << ed;
	cout.flush();
}


// Optimize
#define abs(a) ((a)<0?(~(a)+1):(a))
#define max(a,b) ((a)>(b)?(a):(b))
// #define min(a,b) ((a)<(b)?(a):(b))
//#define swap(a,b) {a=a^b;b=a^b;a=a^b;}
#define Mymax(a,b) (a) = max((a),(b))
#define Mymin(a,b) (a) = min((a),(b))
#define INF (0x3f3f3f3f)
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#define MAXN 200010

int n,m,q;
int inp[MAXN];
vc<int> e[MAXN];

vc<int> tree[MAXN];
bool issqu[MAXN];

namespace Tarjan_{
	int dfn[MAXN], low[MAXN], nowtime = 0;
	bool ancestor[MAXN];
	int st[MAXN], top = 0;
	void Tarjan( int pos , int fa ){
		ancestor[pos] = 1;
		dfn[pos] = low[pos] = ++nowtime;
		st[++top] = pos;
		for( auto v : e[pos] ){
			if( v == fa ) continue;
			if(ancestor[v]) Mymin(low[pos],dfn[v]);
			else if(!dfn[v]){
				Tarjan(v,pos);
				Mymin(low[pos],low[v]);
				if( low[v] >= dfn[pos] ){
					int squ = ++n;
					issqu[squ] = 1;
					tree[squ].Pb(pos);
					tree[pos].Pb(squ);
					int w = 0;
					while( w != v ){
						w = st[top--];
						tree[squ].Pb(w);
						tree[w].Pb(squ);
					}
				}
			}
		}
		ancestor[pos] = 0;
	}
}
using Tarjan_::Tarjan;

namespace Segtree{
	#define TREE 524290
	#define LSON l,l+r>>1,pos<<1
	#define RSON (l+r>>1)+1,r,pos<<1|1
	#define ARG int l , int r , int pos
	#define ROOT 1,n,1
	int tree[TREE];
	void Change( int gpos , int x , ARG ){
		if( l == r ){
			tree[pos] = x;
			return;
		}
		int mid = l+r >> 1;
		if( gpos <= mid ) Change(gpos,x,LSON);
		else Change(gpos,x,RSON);
		tree[pos] = min( tree[pos<<1] , tree[pos<<1|1] );
	}
	void Chkmin( int gpos , int x , ARG ){
		Mymin(tree[pos],x);
		if( l == r )
			return;
		int mid = l+r >> 1;
		if( gpos <= mid ) Chkmin(gpos,x,LSON);
		else Chkmin(gpos,x,RSON);
	}
	int Min( int gl , int gr , ARG ){
		if( gl <= l && r <= gr ) return tree[pos];
		if( gr < l || r < gl ) return INF;
		return min( Min(gl,gr,LSON) , Min(gl,gr,RSON) );
	}
}
using Segtree::Change;
using Segtree::Chkmin;
using Segtree::Min;

namespace Decomposition{
	int fa[MAXN], dep[MAXN], sz[MAXN];
	multiset<int> vals[MAXN];
	int gson[MAXN];
	void Findgson( int pos , int fa ){
		Decomposition::fa[pos] = fa;
		dep[pos] = dep[fa] + 1;
		sz[pos] = 1;
		int gsz = 0;
		for( auto v : tree[pos] ){
			if( v == fa ) continue;
			Findgson(v,pos);
			sz[pos] += sz[v];
			if( sz[v] > gsz ){
				gsz = sz[v];
				gson[pos] = v;
			}
			if(issqu[pos]) vals[pos].insert(inp[v]);
		}
	}
	int top[MAXN], in[MAXN], nowtime = 0;
	void Linkline( int pos , int fa , int top ){
		Decomposition::top[pos] = top;
		in[pos] = ++nowtime;
		if(issqu[pos]) Change(in[pos],*vals[pos].begin(),ROOT);
		else Change(in[pos],inp[pos],ROOT);
		if(gson[pos]) Linkline(gson[pos],pos,top);
		for( auto v : tree[pos] ){
			if( v == fa || v == gson[pos] ) continue;
			Linkline(v,pos,v);
		}
	}

	void Chg( int pos , int x ){
		Change(in[pos],x,ROOT);
		if(fa[pos]){
			int fa = Decomposition::fa[pos];
			vals[fa].erase(vals[fa].find(inp[pos]));
			vals[fa].insert(x);
			Change(in[fa],*vals[fa].begin(),ROOT);
		}
		inp[pos] = x;
	}
	int Query( int a , int b ){
		int ans = INF;
		while( top[a] != top[b] ){
			if( dep[top[a]] < dep[top[b]] ) swap(a,b);
			int tans = Min(in[top[a]],in[a],ROOT);
			Mymin(ans,tans);
			a = fa[top[a]];
		}
		if( dep[a] < dep[b] ) swap(a,b);
		int tans = Min(in[b],in[a],ROOT);
		Mymin(ans,tans);
		int lca = b;
		if(issqu[lca]){
			Mymin(ans,inp[fa[lca]]);
		}
		return ans;
	}
}
using Decomposition::Findgson;
using Decomposition::Linkline;
using Decomposition::Chg;
using Decomposition::Query;

int main(){
	FILEIO();
	// Fout("out.out");

	Read(n,m,q);
	For(i,n) Read(inp[i]);
	For(i,m){
		iRead2(a,b);
		e[a].Pb(b);
		e[b].Pb(a);
	}

	Tarjan(1,0);
	// For(i,n)
	// 	for( auto v : tree[i] )
	// 		printf("%d %d\n",i,v);

	Findgson(1,0);
	Linkline(1,0,1);

	For(qwq,q){
		char c;
		In.Readalpha(c);
		if( c == 'C' ){
			iRead2(pos,x);
			Chg(pos,x);
		}else{
			iRead2(a,b);
			printf("%d\n",Query(a,b));
		}
	}

	END();
}