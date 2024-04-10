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
#define MAXN 1005 //Maxn means "MAXM"

int n;
int a[MAXN][MAXN];
int has[MAXN][MAXN][2];
int dp[MAXN][MAXN][2];
bool tran[MAXN][MAXN][2];
bool has0;
int zeroi , zeroj;

vector<char> path;
void getpath( int i , int j , int k ){
	while( i > 1  ||  j > 1 ){
		if( tran[i][j][k] ){
			path.pb( 'D' );
			i--;
		}else{
			path.pb( 'R' );
			j--;
		}
	}
}

int main(){
//	fin( "2b.txt" );
	ms( has );
	ms( dp );
	has0 = 0;

	read( n );
	fir
		fjr{
			read( a[i][j] );
			int x = a[i][j];
			while( !(x&1) && x ){
				x >>= 1;
				has[i][j][0]++;
			}
			while( !(x%5) && x ){
				x /= 5;
				has[i][j][1]++;
			}
			if( a[i][j] == 0 ){
				has0 = 1;
				zeroi = i;
				zeroj = j;
			}
		}

	dp[1][1][0] = has[1][1][0];
	dp[1][1][1] = has[1][1][1];
	for( int k = 0 ; k <= 1 ; k++ )
		for( int i = 2 ; i <= n ; i++ ){
			dp[i][1][k] = dp[i-1][1][k] + has[i][1][k];
			tran[i][1][k] = 1;
			dp[1][i][k] = dp[1][i-1][k] + has[1][i][k];
			tran[1][i][k] = 0;
		}

	for( int i = 2 ; i <= n ; i++ ){
		for( int j = 2 ; j <= n ; j++ ){
			for( int k = 0 ; k <= 1 ; k++ ){
				if( dp[i-1][j][k] > dp[i][j-1][k] ){
					dp[i][j][k] = dp[i][j-1][k] + has[i][j][k];
					tran[i][j][k] = 0;
				}else{
					dp[i][j][k] = dp[i-1][j][k] + has[i][j][k];
					tran[i][j][k] = 1;
				}
			}
		}
	}

	if( has0  &&  min( dp[n][n][1] , dp[n][n][0] ) > 1 ){
		putchar('1');
		putchar('\n');
		for( int i = 1 ; i < zeroj ; i++ ) putchar('R');
		for( int i = 1 ; i < n ; i++ ) putchar('D');
		for( int i = zeroj ; i < n ; i++ ) putchar('R');
		putchar('\n');
		return 0;
	}

	int ans = -1;
	if( dp[n][n][0] > dp[n][n][1] ){
		ans = dp[n][n][1];
		getpath( n , n , 1 );
	}else{
		ans = dp[n][n][0];
		getpath( n , n , 0 );
	}

	printf("%d\n",ans);
	for( int i = path.size()-1 ; i >= 0 ; i-- )
		putchar( path[i] );
	putchar('\n');

	return 0;
}