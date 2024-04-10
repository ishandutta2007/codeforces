#include <assert.h>
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
#define INF ((int)(2e9))
#define LINF ((int)(1e18))
#define fir() for( int i = 1 ; i <= n ; i++ )
#define fjr() for( int j = 1 ; j <= n ; j++ )
#define fkr() for( int k = 1 ; k <= n ; k++ )
#define firx( _x ) for( int i = 1 ; i <= _x ; i++ )
#define fjrx( _x ) for( int j = 1 ; j <= _x ; j++ )
#define fkrx( _x ) for( int k = 1 ; k <= _x ; k++ )
#define fir0x( _x ) for( int i = 0 ; i < _x ; i++ )
#define fjr0x( _x ) for( int j = 0 ; j < _x ; j++ )
#define fkr0x( _x ) for( int k = 0 ; k < _x ; k++ )
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
#define read(_nowans) scanf("%d",&_nowans)
#define ms(_data) memset(_data,0,sizeof(_data))
#define fin(_filename) freopen(_filename,"r",stdin)
#define fout(_filename) freopen(_filename,"w",stdout)
#define read2(_nowans1,_nowans2) scanf("%d %d",&_nowans1,&_nowans2)
#define msn(_data,_nowans) memset(_data,_nowans,sizeof(_data))
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define read3(_nowans1,_nowans2,_nowans3) scanf("%d %d %d",&_nowans1,&_nowans2,&_nowans3)
using namespace std;
_tp<_tyn T>void mymax( T &_a , T _b ){ if( _a < _b ) _a = _b; }
_tp<_tyn T>void mymin( T &_a , T _b ){ if( _a > _b ) _a = _b; }
void print( ll _x ){ cout << _x << endl; }
_tp<_tyn T>void print( T _data[] , int _size ){
	firx( _size )
		cout << _data[i] << " ";
	cout << endl;
}

#define MAXN 200100
#define TIAOSU 1
#define CHAO 2
#define XIANSU 3
#define KECHAO 4
#define BUXIANSU 5
#define BUKECHAO 6
#define DAT(_x) ( _x == TIAOSU  ||  _x == XIANSU )

int n;

int xiansulog[MAXN];
int top = 1;
int ans = 0;
void delXIANSU( int v ){
	while( top > 1  &&  xiansulog[top-1] < v ){
		top--;
		ans++;
	}
}

int main(){
//	fin( "D.txt" );

	read( n );

	int nowv;
	bool canchao = 1;
	int cannotchao = 0;

	fir(){
		int cmd , dat;
		read( cmd );
		if( DAT( cmd ) ) read( dat );

		if( cmd == TIAOSU ){
			nowv = dat;
			delXIANSU( nowv );
		}
		if( cmd == CHAO  &&  !canchao ){
			ans += cannotchao;
			cannotchao = 0;
			canchao = 1;
		}
		if( cmd == XIANSU ){
			//xianv = dat;
			xiansulog[top++] = dat;
			delXIANSU( nowv );
		}
		if( cmd == KECHAO ){
			canchao = 1;
			cannotchao = 0;
		}
		if( cmd == BUXIANSU ){
			top = 1;
		}
		if( cmd == BUKECHAO ){
			canchao = 0;
			cannotchao++;
		}
		//cout << "Xiansulog after cmd " << cmd << " : "; print( xiansulog , top-1 );
		//cout << "Ans after cmd " << cmd << " : " << ans << endl;
		//cout << "Nowv after cmd " << cmd << " : " << nowv << endl;
	}

	printf("%d\n",ans);

	return 0;
}