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
#define INF (1e9)
#define in cin >>
#define LINF (1e18)
#define out cout <<
#define ln  << endl
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
#define fin(_filename) freopen(_filename,"r",stdin)
#define fout(_filename) freopen(_filename,"w",stdout)
#define read2(_num1,_num2) scanf("%d %d",&_num1,&_num2)
#define msn(_data,_num) memset(_data,_num,sizeof(_data))
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define read3(_num1,_num2,_num3) scanf("%d %d %d",&_num1,&_num2,&_num3)
using namespace std;
_tp<_tyn T>void mymax( T &_a , T _b ){ if( _a < _b ) _a = _b; }
_tp<_tyn T>void mymin( T &_a , T _b ){ if( _a > _b ) _a = _b; }
_tp<_tyn T>void print(T _x){for(auto _it=_x.begin();_it!=_x.end();_it++)cout<<*_it<<" ";cout ln;}
void print(int _x){printf("%d ",_x);}
void print(ll _x){printf("%lld ",_x);}
#define MAXN 305

int n;
vector<int> e[MAXN];
int rinp[MAXN] , inp[MAXN];
//rinp[x]=i:xi

void unite( dq<int> &a , dq<int> &b ){
	int sza = a.size() , szb = b.size();
	if( sza < szb ){
		while( a.size() ){
			b.pf( a.back() );
			a.pop_back();
		}
		swap( a , b );
		return;
	}
	while( b.size() ){
		a.pb( b.front() );
		b.pop_front();
	}
}

dq<int> ans[MAXN];
int solve( int pos , int fa ){
	ans[pos].pb( pos );
	vc< pii > res;
	for( uint i = 0 ; i < e[pos].size() ; i++ )
		if( e[pos][i] != fa ){
			int ret = solve( e[pos][i] , pos );
			res.pb( mp( ret , e[pos][i] ) );
		}
	
	if( res.size() == 0 )
		return rinp[ pos ];
	sort( res.begin() , res.end() );
	
	//Find the correct order
	for( uint i = 0 ; i < res.size() ; i++ ){
		unite( ans[pos] , ans[res[i].S] );
		ans[pos].pb( pos );
	}
	return res.back().F;
}

int main(){
//	fin( "ant.txt" );
	
	read( n );
	for( int i = 1 ; i < n ; i++ ){
		int a , b;
		read2( a , b );
		e[a].pb(b);
		e[b].pb(a);
	}
	
	int leafcnt = 0;
	for( int i = 2 ; i <= n ; i++ )
		if( e[i].size() == 1 )
			leafcnt++;
	
	for( int i = 1 ; i <= n ; i++ ){
		scanf("%d",&inp[i]);
		rinp[inp[i]] = i;
	}
	
	solve( 1 , -1 );
	
	if( (int)ans[1].size() != 2*n-1 ){
		print( -1 );
		return 0;
	}
	
	int k = 1;
	for( int i = 0 ; i < 2*n-1 ; i++ )
		if( ans[1][i] == inp[k] ) k++;
	
	if( k != leafcnt+1 ){
		print( -1 );
		return 0;
	}
	
	print( ans[1] );
	
	return 0;
}