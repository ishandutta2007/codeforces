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
#define MAXN 260 //Maxn means "MAXM"
#define MAX5 60

int n , k;
int has5[MAXN] , has2[MAXN];

int dp1[MAXN][MAXN*MAX5];
int dp2[MAXN][MAXN*MAX5];

int main(){
//	fin( "round.txt" );
	ms( has5 );
	ms( has2 );

	read2( n , k );
	for( int i = 1 ; i <= n ; i++ ){
		ll x;
		scanf("%I64d",&x);
		while( !( x & 1 ) ){
			has2[i]++;
			x >>= 1;
		}
		while( !( x % 5 ) ){
			has5[i]++;
			x /= 5;
		}
	}

	//for( int i = 1 ; i <= n ; i++ ){
	//	cout << i << "    " << has2[i] << " " << has5[i] << endl;
	//}

	msn( dp1 , -63 );
	dp1[0][0] = 0;
	for( int i = 1 ; i <= n ; i++ ){
		msn( dp2 , -63 );
		for( int j = 0 ; j <= k ; j++ )
			for( int l = 0 ; l <= j*MAX5 ; l++ ){
				mymax( dp2[j][l] , dp1[j][l] );
				mymax( dp2[j+1][l+has5[i]] , dp1[j][l] + has2[i] );
			}
		memcpy( dp1 , dp2 , sizeof( dp2 ) );
	}

	int ans = 0;
	for( int i = 0 ; i < k*MAX5 ; i++ ){
		mymax( ans , min( i , dp1[k][i] ) );
	}

	printf("%d\n",ans);

	return 0;
}