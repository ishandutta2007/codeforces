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
#include <ctime>
#include <set>
#include <map>
#define F first
#define S second
#define qq queue
#define dq deque
#define vc vector
#define INF ((int)(2e9))
#define LINF ((int)(1e18))
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
#define B cout << "BreakPoint\n";
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
void print( int _x ){ printf("%d\n",_x); }
_tp<_tyn T>void print( T _data[] , int _size ){
	for( int i = 1 ; i <= _size ; i++ )
		cout << _data[i] << " ";
	cout << endl;
}

int n , m;
int haveb_heng[55] , havew_heng[55];
int haveb_shu[55] , havew_shu[55];

ll ans = 0;
ll pow2( int x ){
	ll ret = 1LL;
	for( int i = 1 ; i <= x ; i++ )
		ret *= 2;
	return ret;
}

int main(){
	//fin( "B.txt" );
	ms( havew_heng ); ms( havew_shu );
	ms( haveb_shu ); ms( haveb_heng );

	cin >> n >> m;
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ ){
			char c;
			cin >> c;
			if( c == '0' ){
				havew_heng[i]++;
				havew_shu[j]++;
			}else{
				haveb_heng[i]++;
				haveb_shu[j]++;
			}
		}

	for( int i = 1 ; i <= n ; i++ ){
		ans += pow2( haveb_heng[i] ) - 1;
		ans += pow2( havew_heng[i] ) - 1;
	}

	for( int i = 1 ; i <= m ; i++ ){
		ans += pow2( haveb_shu[i] ) - 1 - haveb_shu[i];
		ans += pow2( havew_shu[i] ) - 1 - havew_shu[i];
	}

	cout << ans << endl;

	return 0;
}