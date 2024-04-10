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
#define MAXN 100100

int n;
int bef[MAXN];
pii aft[MAXN];
int realpos[MAXN];	//The real pos of num i

int dsu[MAXN];
void init(){
	for( int i = 0 ; i <= n + 2 ; i++ )
		dsu[i] = i;
}
int getfa( int pos ){
	if( dsu[pos] == pos ) return pos;
	return dsu[pos] = getfa( dsu[pos] );
}
bool unite( int a , int b ){
	a = getfa( a );
	b = getfa( b );
	if( a == b ) return 0;
	dsu[a] = b;
	return 1;
}

bool cmp( vector<int> v1 , vector<int> v2 ){
	if( v1.empty()  ||  v2.empty() ) return 0;
	return v1[0] < v2[0];
}
int main(){
	//fin( "C.txt" );

	read( n ); init();
	for( int i = 1 ; i <= n ; i++ ){
		read( bef[i] );
		aft[i] = mp( bef[i] , i );
	}

	sort( aft+1 , aft+1+n );

	for( int i = 1 ; i <= n ; i++ ){
		realpos[ aft[i].S ] = i;
	}

	for( int i = 1 ; i <= n ; i++ )
		unite( i , realpos[i] );

	vector<int> ans[MAXN];
	int cnt = 0;
	for( int i = 1 ; i <= n ; i++ ){
		if( ans[ getfa(i) ].empty() ) cnt++;
		ans[ getfa(i) ].pb( i );
	}

	printf("%d\n",cnt);
	sort( ans+1 , ans+1+n , cmp );
	for( int i = 1 ; i <= n ; i++ )
		if( !ans[i].empty() ){
			sort( ans[i].begin() , ans[i].end() );
			printf("%d ",ans[i].size());
			for( uint j = 0 ; j < ans[i].size() ; j++ )
				printf("%d ",ans[i][j]);
			printf("\n");
		}

	return 0;
}