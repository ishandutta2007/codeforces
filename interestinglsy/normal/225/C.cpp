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
#define INF ((int)(1e9))
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
void print(int _x){printf("%d ",_x);}
void print(ll _x){printf("%I64d ",_x);}
#define MAXN 1010

int n , m , x , y;
int haveb[MAXN] , havew[MAXN];

int mem[MAXN][MAXN][3];
int dfs( int pos , int last , bool col ){	//last: 	//col: 1:black	0:white
	//for( int i = 1 ; i < pos; i++) cout<<"\t";
	//cout << "dfs at " << pos << " " << last << " " << col << endl;
	if( pos == m + 1 ) return 0;

	if( mem[pos][last][col] != -1 ) return mem[pos][last][col];

	int ans1 , ans2;
	ans1 = ans2 = INF;

	if( x <= last  &&  m - pos + 1 >= x ) ans1 = dfs( pos+1 , 1 , col ^ 1 ) + ( col ? haveb[pos] : havew[pos] );
	if( last + 1 <= y ) ans2 = dfs( pos+1 , last+1 , col ) + ( col ? havew[pos] : haveb[pos] );

	mem[pos][last][col] = min( ans1 , ans2 );
	return min( ans1 , ans2 );
}

int main(){
//	fin( "A.txt" );
	ms( haveb );
	ms( havew );
	msn( mem , -1 );

	read2( n , m );
	read2( x , y );

	getchar();
	for( int i = 1 ; i <= n; i++ ){
		for( int j = 1 ; j <= m ; j++ ){
			char c;
			scanf("%c",&c);
			if( c == '.' ) havew[j]++;
			else haveb[j]++;
			//cout << c;
		}
		getchar();
		//cout << endl;
	}

	//for( int i = 1 ; i <= m ; i++ )
	//	cout << havew[i] << " " << haveb[i] << endl;

	int ans1 = dfs( 1 , 0 , 0 );
	int ans2 = dfs( 1 , 0 , 1 );
	int ans = min( ans1 , ans2 );
	cout << ans << endl;

	return 0;
}