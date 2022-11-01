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
#define INF ((int)(1e9))
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
#define MAXN 100002

int n , m;

vc< vc< int > > matrix;
vc< pii > hang[MAXN];
vc< int > e[ MAXN * 2 ];
//[1,m],m+1,m+iiGROUP""
//"",
//GROUP""

bool vis[MAXN];
int nowtime;
int topu[MAXN];
void dfs( int pos ){
	vis[pos] = 1;
	for( uint i = 0 ; i < e[pos].size() ; i++ )
		if( !vis[e[pos][i]] )
			dfs( e[pos][i] );
	topu[pos] = nowtime++;
}
void gettopu( int edid ){
	ms( vis );
	nowtime = 1;
	for( int i = 1 ; i <= edid ; i++ )
		if( !vis[i] )
			dfs( i );
	for( int i = 1 ; i <= edid ; i++ )
		for( uint j = 0 ; j < e[i].size() ; j++ )
			if( topu[i] < topu[e[i][j]] ){
				printf("-1\n");
				exit( 0 );
			}
}
bool bytopu( int x1 , int x2 ){
	return topu[x1] > topu[x2];
}

int ans[MAXN];
int main(){
//	fin( "matrix.txt" );

	read2( n , m );
	matrix.resize( n+2 );
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ ){
			int x;
			read( x );
			matrix[ i ].pb( x );
			if( x != -1 )
				hang[ i ].pb( mp( x , j ) ) ;
		}

	for( int i = 1 ; i <= n ; i++ )
		sort( hang[i].begin() , hang[i].end() );

	//for( int i = 1 ; i <= n ; i++ ){
	//	cout << i << "  |  ";
	//	for( uint j = 0 ; j < hang[i].size() ; j++ )
	//		cout << hang[i][j].S << " ";
	//	cout << endl;
	//}
	int nowleaderid = m+1;
	for( int i = 1 ; i <= n ; i++ ){
		int k = 0;
		for( uint j = 0 ; j < hang[i].size()  &&  k < (int)hang[i].size() ; j = k ){
			k = j;
			while( hang[i][j].F == hang[i][k].F  &&  k < (int)hang[i].size() ) k++;
			k--;
			for( int l = j ; l <= k ; l++ ){
				if( j != 0 ) e[ nowleaderid-1 ].pb( hang[i][l].S );
				if( k != (int)hang[i].size()-1 ) e[ hang[i][l].S] .pb( nowleaderid );
			}
			if( k != (int)hang[i].size() - 1 ) nowleaderid++;
			k++;
		}
	}

	gettopu( nowleaderid );

	for( int i = 1 ; i <= m ; i++ )
		ans[i] = i;

	sort( ans+1 , ans+m+1 , bytopu );

	for( int i = 1 ; i <= m ; i++ )
		printf("%d ",ans[i]);
	printf("\n");

	return 0;
}