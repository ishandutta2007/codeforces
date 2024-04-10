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
#define MAXN 51 //Maxn means "MAXM"

char inp[MAXN];
int n;

ll ans = 0;
ll dp[MAXN][10];

int main(){
//	fin( "phone.txt" );
	msn( dp , 0 );
fastio;
	cin >> inp;
	n = strlen(inp);

	for( int i = 0 ; i < n ; i++ )
		inp[i] -= '0';

	for( int i = 0 ; i <= 9 ; i++ )
		dp[0][i] = 1;

	for( int i = 1 ; i < n ; i++ ){
		int now = inp[i];
		for( int j = 0 ; j <= 9 ; j++ ){
			int l = (now+j) >> 1 , r = (now+j+1) >> 1;
			dp[i][l] += dp[i-1][j];
			if( l != r )
				dp[i][r] += dp[i-1][j];
		}
	}

	for( int i = 0 ; i <= 9 ; i++ )
		ans += dp[n-1][i];

	bool fg = 1;
	for( int i = 0 ; i < n-1 ; i++ )
		if( !( inp[i]-inp[i+1] <= 1  &&  inp[i] - inp[i+1] >= -1 ) ){
			fg = 0;
			break;
		}

	if( fg ) ans--;

	cout << ans << endl;

	return 0;
}