#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <ctime>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define F first
#define S second
#define qq queue
#define dq deque
#define vc vector
#define INF ((int)(1e8))
#define in cin >>
#define LINF ((int)(1e17))
#define out cout <<
#define ln  << outtimedl
#define pb push_back
#define mp make_pair
#define ll long long
#define _tp template
#define _tyn typename
#define pf push_front
#define itor iterator
#define sint short int
#define ull unsigned ll
#define pq priority_queue
#define pii pair<int,int>
#define uint unsigned int
#define B out "BreakPoint\n";
#define read(_num) scanf("%d",&_num)
#define ms(_data) memset(_data,0,sizeof(_data))
#define fin(_filouttimeame) freopen(_filouttimeame,"r",stdin)
#define fout(_filouttimeame) freopen(_filouttimeame,"w",stdout)
#define read2(_num1,_num2) scanf("%d %d",&_num1,&_num2)
#define msn(_data,_num) memset(_data,_num,sizeof(_data))
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define read3(_num1,_num2,_num3) scanf("%d %d %d",&_num1,&_num2,&_num3)
using namespace std;
_tp<_tyn T>void mymax( T &_a , T _b ){ if( _a < _b ) _a = _b; }
_tp<_tyn T>void mymin( T &_a , T _b ){ if( _a > _b ) _a = _b; }
void print(int _x){printf("%d ",_x);}
void print(ll _x){printf("%I64d ",_x);}
#define MAXN 501020

struct Node{
	ll val;
	ll lazy;
};

struct mintreeegtree{
	Node tree[MAXN*4];
	void upd( int pos ){
		tree[pos].lazy = min(
			tree[pos<<1].lazy + tree[pos<<1].val ,
			tree[pos<<1|1].lazy + tree[pos<<1|1].val );
	}
	void down( int pos ){
		tree[pos<<1].val += tree[pos].val;
		tree[pos<<1|1].val += tree[pos].val;
		tree[pos].lazy += tree[pos].val;
		tree[pos].val = 0;
	}
	void val( int pos , int l , int r , int a , int b , ll c ) {
		if (a <= l && b >= r) {
			tree[pos].val += c;
			return;
		}
		int mid = ( l+r ) >> 1;
		down(pos);
		if( a <= mid ) val( pos<<1 , l , mid , a , b , c );
		if( b > mid ) val( pos << 1 | 1 , mid + 1 , r , a , b , c );
		upd( pos );
	}
	ll ask( int pos , int l , int r , int gl , int gr ) {
		if( gl <= l && r <= gr ) return tree[pos].lazy + tree[pos].val;
		int mid = (l+r) >> 1;
		down( pos );
		ll ret = LINF;
		if( gl <= mid ) ret = min(ret, ask( pos << 1 , l , mid , gl , gr ) );
		if( gr > mid ) ret = min(ret, ask( pos << 1 | 1 , mid+1 , r , gl , gr ) );
		return ret;
	}
}mintree;

vector< pair<int,ll> > tree[MAXN];
int n, q;
ll tort[MAXN];
int intime[MAXN], outtime[MAXN];
int tot;
int foo[ MAXN << 1 ] , bar[ MAXN << 1 ] , w[ MAXN << 1 ];

void dfs( int pos , ll rootdis ) {
	tot++;
	intime[pos] = tot;
	mintree.val( 1 , 1 , n , tot , tot , rootdis + tort[pos] );
	for( uint i = 0 ; i < tree[pos].size() ; i++ )
		dfs( tree[pos][i].F , rootdis+tree[pos][i].S );
	outtime[pos] = tot;
}

ll path(int x) {
	return mintree.ask(1,1,n,intime[x],intime[x]) - tort[x];
}

int main() {
//	fin( "B.txt" );

	scanf( "%d %d" , &n , &q );
	for( int i = 1 ; i <= n-1 ; i++ ){
		scanf( "%d %d %d", &foo[i], &bar[i], &w[i] );
		tree[foo[i]].pb( mp( bar[i] , w[i] ) );
	}
	for (int i = n; i <= ( n << 1 )-2 ; i++ ){
		scanf( "%d%d%d", &foo[i], &bar[i], &w[i] );
		tort[foo[i]] = w[i];
	}

	tot = 0;
	dfs(1, 0);

	for (int i = 1; i <= q; ++i) {
		int op , x , y;
		scanf( "%d %d %d", &op, &x, &y );
		if( op == 1 ){
			if (x <= n-1)
				mintree.val(1,1,n,intime[bar[x]],outtime[bar[x]],y-w[x]);
			else{
				mintree.val(1,1,n,intime[foo[x]],intime[foo[x]],y-w[x]);
				tort[foo[x]] = y;
			}
			w[x] = y;
		}
		else{
			ll px = path(x) , py = path(y);
			if( intime[y] >= intime[x] && outtime[y] <= outtime[x] )
				printf( "%I64d\n" , py - px );
			else printf( "%I64d\n" , mintree.ask(1,1,n,intime[x],outtime[x]) - px + py );
		}
	}
}