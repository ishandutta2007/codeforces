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
#define MAXN 105	//Maxn means "MAXM"

int n , k;
int a[MAXN];

int main(){
	fastio;
//	fin( "B.txt" );

	cin >> n >> k;
	for( int i = 1 ; i <= k ; i++ )
		cin >> a[i];

	int left4 = n;
	for( int i = 1 ; i <= k ; i++ ){
		while( 1 ){
			if( a[i] < 4  ||  left4 == 0 ) break;
			a[i] -= 4;
			left4--;
		}
	}

	/*
	cout << left4 << endl;
	for( int i = 1 ; i <= k ; i++ )
		cout << a[i] << " ";
	cout << endl;
	*/

	int left2 = n + n + left4;
	int use2 = 0;

	for( int i = 1 ; i <= k ; i++ ){
		while( 1 ){
			if( a[i] < 2  ||  left2 == 0 ) break;
			a[i] -= 2;
			left2--;
			use2++;
		}
	}

	/*
	cout << left2 << " " << use2 << endl;
	for( int i = 1 ; i <= k ; i++ )
		cout << a[i] << " ";
	cout << endl;
	*/

	int left1 = left2 + left4;
	//cout << left1 << endl;
	for( int i = 1 ; i <= k ; i++ ){
		while( 1 ){
			if( a[i] < 1  ||  left1 == 0 ) break;
			a[i] -= 1;
			left1--;
		}
	}

	//cout << left1 << endl;

	for( int i = 1 ; i <= k ; i++ ){
		if( a[i] ){
			cout << "NO\n";
			exit( 0 );
		}
	}

	cout << "YES\n";

	return 0;
}