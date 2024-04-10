#include <algorithm>
#include <iostream>
#include <cstdlib>
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
#define MAXN 300100		//Maxn means "MAXM"

int n , m;

int dsu[MAXN] , ans[MAXN];
void init(){
	for( int i = 1 ; i <= n+2 ; i++ )
		dsu[i] = i;
}
int getfa( int pos ){
	if( dsu[pos] == pos ) return pos;
	return dsu[pos] = getfa( dsu[pos] );
}

void printans(){
	for( int i = 1 ; i <= n ; i++ )
		printf("%d ",ans[i]);
	printf("\n");
}

int main(){
//	fin( "knight.txt" );

	read2( n , m );
	init();

	for( int i = 1 ; i <= m ; i++ ){
		int l , r , win;
		read3( l , r , win );
		//cout << l << " " << r << "   " << win << endl;
		for( int k = getfa( l ) ; k <= r ; k = getfa( k+1 ) ){
			if( k != win ){
				dsu[k] = k+1;
				ans[k] = win;
			}
			//cout << k << endl;
		}
	}
		//cout << n << endl;
	printans();

	return 0;
}