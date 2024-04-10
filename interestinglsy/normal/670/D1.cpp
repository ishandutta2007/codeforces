#include <algorithm>
#include <iostream>
#include <cstring>
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
#define out cout <<
#define ln  << endl
#define pb push_back
#define mp make_pair
#define ll long long
#define _tp template
#define _tyn typename
#define pf push_front
#define itor iterator
#define mp make_pair
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
void print(int _x){printf("%d ",_x);}
void print(ll _x){printf("%I64d ",_x);}
#define MAXN 1010

int n , k;
ll a[MAXN] , b[MAXN];

bool check( int pos ){
	ll ans = 0;
	for( int i = 1 ; i <= n ; i++ )
		if( a[i] * pos - b[i] > k ) return 0;
	for( int i = 1 ; i <= n ; i++ )
		ans += max( a[i] * pos - b[i] , 0LL );
	if( ans <= k ) return 1;
	return 0;
}

int main(){
//	fin( "ls.txt" );

	read2( n , k );
	for( int i = 1 ; i <= n ; i++ )
		scanf("%I64d",&a[i]);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%I64d",&b[i]);

	ll l = 0 , r = INF;
	ll ans = 0;
	while( l <= r ){
		ll mid = ( l + r ) >> 1;
		if( check( mid ) ){
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
	}

	printf("%I64d\n",ans);

	return 0;
}