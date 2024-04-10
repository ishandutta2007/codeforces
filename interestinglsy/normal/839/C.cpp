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
#define MAXN 101010	//Maxn means "MAXM"
#define ld long double
#include <iomanip>

int n;
vc<int> e[MAXN];

ld ans = 0;
void dfs( int pos , int fa , ld gai , int dis ){
	//cout << "DFS at pos " << pos << " Fa: " << fa << " With gai " << gai << " and dis " << dis << endl;
	if( e[pos].size() == 1  &&  pos != 1 ){
		ans += gai * (ld)(dis);
		return;
	}
	//cout << gai << " / " << e[pos].size() - 1 << " = ";
	if( fa == -1 ) gai /= (ld)e[pos].size();
	else gai /= (ld)(e[pos].size()-1);
//	cout << gai << endl;
	for( uint i = 0 ; i < e[pos].size() ; i++ )
		if( e[pos][i] != fa )
			dfs( e[pos][i] , pos , gai , dis + 1 );
}

int main(){
	//fin( "C.txt" );
	//fout( "ans.txt" );
	//cout << (ld)1 / (ld)2;
	cin >> n;
	for( int i = 1 ; i < n ; i++ ){
		int a , b;
		cin >> a >> b;
		e[a].pb( b );
		e[b].pb( a );
	}

	/*
	for( int i = 1 ; i <= n ; i++ ){
		cout << i << "\t";
		for( uint j = 0 ; j < e[i].size() ; j++ )
			cout << e[i][j] << " ";
		cout << endl;
	}
	*/

	dfs( 1 , -1 , 1.0 , 0 );

	cout << fixed << setprecision(25) << ans << endl;

	return 0;
}