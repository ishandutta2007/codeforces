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
#define sqr(x) ((x)*(x))
int r , d;
int n;
int ans = 0;

int main(){
//	fin( "B.txt" );
	read2(d,r);
	r = d - r;
	read(n);
	for( int i = 1 ; i <= n ; i++ ){
		int x , y , dis , ri;
		read3( x , y , ri );
		dis = sqr(x) + sqr(y);
		//cout << "Dis " << i << " : " << dis << endl;
		//cout << dis-ri << " " << dis+ri << endl;
		if( dis >= r*r+ri*ri+2*r*ri  &&  dis <= d*d+ri*ri-2*d*ri ){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

// sqrt(x) + ri <= d
// sqrt(x) <= d-ri
// x <= d^2 + ri^2 - 2d*ri

// sqrt(x) - ri >= r
// sqrt(x) >= r+ri
// x >= r^2 + ri^2 + 2r*ri