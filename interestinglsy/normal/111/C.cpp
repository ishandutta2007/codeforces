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
#define INF (1000000000)
#define in cin >>
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
_tp<_tyn T>void print(T _x){
for(auto _it=_x.begin();_it!=_x.end();_it++)
cout<<*_it<<" ";cout ln;}
void print(int _x){printf("%d ",_x);}
void print(ll _x){printf("%lld ",_x);}

#define MAXN 45

int n , m;
int juji[MAXN][MAXN];

int ans = INF;
bool check( int jie ){
	for( int i = 1 ; i <= jie ; i++ )
		for( int j = 1 ; j <= m ; j++ )
			if( juji[j][i] == 0 )
				return 0;
	return 1;
}
void dfs( int x , int y , int nowjuji ){
	if( y == n+1 ){
		//cout << "Checking....\n";
		if( check(n) ){
			ans = min( ans , nowjuji );
			///cout << "Ans updated " << ans << endl;
		}
		return;
	}
	if( nowjuji > (m*y)/3 ) return;
	if( nowjuji >= ans ) return;
	if( x == m ){
		if( y - 2 >= 1  &&  !check( y-2 ) ) return;
		dfs( 1 , y+1 , nowjuji );
	}
	else dfs( x+1 , y , nowjuji );
	juji[x-1][y]++;
	juji[x][y-1]++;
	juji[x+1][y]++;
	juji[x][y+1]++;
	juji[x][y]++;
	if( x == m ) dfs( 1 , y+1 , nowjuji+1 );
	else dfs( x+1 , y , nowjuji+1 );
	juji[x-1][y]--;
	juji[x][y-1]--;
	juji[x+1][y]--;
	juji[x][y+1]--;
	juji[x][y]--;
}

int main(){
//	fin( "spi.txt" );
	ms( juji );
	
	read2( n , m );
	if( n < m ) swap( n , m );
	
	dfs( 1 , 1 , 0 );
	
	printf("%d\n",n*m-ans);
	
	return 0;
}