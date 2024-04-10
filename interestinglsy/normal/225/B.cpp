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

int n,k,tot;
ll f[100000];

int main(){

	cin >> n >> k;

	tot = 1;
	f[1] = 1;
	while( 1 ){
		if( f[tot] > n ) break;
		tot++;
		for( int j = max( 1 , tot-k ) ; j <= tot - 1 ; j++ )
			f[tot] += f[j];
	}

	vc<int> a;
	a.pb( 0 );
	int ans = 1;
	for( int i = tot ; i >= 1 ; i-- )
		if( n >= f[i] ){
			n -= f[i];
			ans++;
			a.pb( f[i] );
		}

	cout << ans << endl;
	for( uint i = 0 ; i < a.size() ; i++ )
		cout << a[i] << " ";
	cout << endl;

    return 0;
}