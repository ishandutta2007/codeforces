#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define F first
#define S second
#define qq queue
#define dq deque
#define vc vector
#define INF ((int)(2e9))
#define LINF ((int)(1e18))
#define fir for( int i = 1 ; i <= n ; i++ )
#define fjr for( int j = 1 ; j <= n ; j++ )
#define fkr for( int k = 1 ; k <= n ; k++ )
#define firx( _x ) for( int i = 1 ; i <= _x ; i++ )
#define fjrx( _x ) for( int j = 1 ; j <= _x ; j++ )
#define fkrx( _x ) for( int k = 1 ; k <= _x ; k++ )
#define out cout <<
#define ln  << endl
#define pb push_back
#define mp make_pair
#define _tp template
#define _tyn typename
#define pf push_front
#define itor iterator
#define mp make_pair
#define sint short int
#define ull unsigned long long
#define pq priority_queue
#define pii pair<int,int>
#define uint unsigned int
#define ll long long
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
#define MAXN 5001

int n , m;
int t;
vc<int> e[MAXN];
vc<int> dis[MAXN];
int dp[MAXN][MAXN];
int tran[MAXN][MAXN];

ll dfs( int pos , int dotleft ){
	ll ans = INF , anspos;
	if( dp[pos][dotleft] != -1 ) return dp[pos][dotleft];
	if( dotleft == 1 ){
		if( pos == n )
			ans = 0;
	}else{
		for( uint i = 0 ; i < e[pos].size() ; i++ ){
			ll ret = dfs( e[pos][i] , dotleft-1 ) + dis[pos][i];
			if( ret < ans  &&  ret <= t ){
				ans = ret;
				anspos = e[pos][i];
			}
		}
	}
	tran[pos][dotleft] = anspos;
	dp[pos][dotleft] = ans;
	return ans;
}

int main(){
//	fin( "journey.txt" );
	msn( dp , -1 );

	read2( n , m );
	read( t );
	firx( m ){
		int a , b;
		int tuse;
		read2( a , b );
		read( tuse );
		e[a].pb( b );
		dis[a].pb( tuse );
	}

	ll ans = INF;
	for( int i = n ; i >= 0 ; i-- ){
		int ret = dfs( 1 , i );
		if( ret < INF ){
			ans = i;
			break;
		}
	}

	printf("%I64d\n",ans);

	int nowpos = 1;
	for( int i = ans ; i >= 1 ; i-- ){
		printf("%d ",nowpos);
		nowpos = tran[nowpos][i];
	}

	printf("\n");

	return 0;
}