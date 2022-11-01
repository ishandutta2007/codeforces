#include <assert.h>
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
#define fir() for( int i = 1 ; i <= n ; i++ )
#define fjr() for( int j = 1 ; j <= n ; j++ )
#define fkr() for( int k = 1 ; k <= n ; k++ )
#define firx( _x ) for( int i = 1 ; i <= _x ; i++ )
#define fjrx( _x ) for( int j = 1 ; j <= _x ; j++ )
#define fkrx( _x ) for( int k = 1 ; k <= _x ; k++ )
#define fir0x( _x ) for( int i = 0 ; i < _x ; i++ )
#define fjr0x( _x ) for( int j = 0 ; j < _x ; j++ )
#define fkr0x( _x ) for( int k = 0 ; k < _x ; k++ )
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
#define read(_nowans) scanf("%d",&_nowans)
#define ms(_data) memset(_data,0,sizeof(_data))
#define fin(_filename) freopen(_filename,"r",stdin)
#define fout(_filename) freopen(_filename,"w",stdout)
#define read2(_nowans1,_nowans2) scanf("%d %d",&_nowans1,&_nowans2)
#define msn(_data,_nowans) memset(_data,_nowans,sizeof(_data))
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define read3(_nowans1,_nowans2,_nowans3) scanf("%d %d %d",&_nowans1,&_nowans2,&_nowans3)
using namespace std;
_tp<_tyn T>void mymax( T &_a , T _b ){ if( _a < _b ) _a = _b; }
_tp<_tyn T>void mymin( T &_a , T _b ){ if( _a > _b ) _a = _b; }
void print( ll _x ){ cout << _x << endl; }
_tp<_tyn T>void print( T _data[] , int _size ){
	firx( _size )
		cout << _data[i] << " ";
	cout << endl;
}

string t;

int yuan[10] , xian[10];
int ans = INF;
void dfs( int pos , int chg ){
	if( pos == 7 ){
		if( xian[1]+xian[2]+xian[3] == xian[4]+xian[5]+xian[6] ){
			mymin( ans , chg );
		}
		return;
	}
	for( int i = 0 ; i <= 9 ; i++ ){
		xian[pos] = i;
		dfs( pos+1 , chg + ( i != yuan[pos] ) );
	}
}

int main(){
	//fin( "B.txt" );

	cin >> t;
	for( int i = 0 ; i < 6 ; i++ )
		yuan[i+1] = t[i] - '0';

	dfs(1,0);

	cout << ans << endl;

	return 0;
}