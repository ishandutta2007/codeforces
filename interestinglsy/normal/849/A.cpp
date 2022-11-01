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
#define dq deque
#define vc vector
#define INF ((int)(2e9))
#define LINF ((int)(1e18))
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
#define read(_noans) scanf("%d",&_noans)
#define ms(_data) memset(_data,0,sizeof(_data))
#define fin(_filename) freopen(_filename,"r",stdin)
#define fout(_filename) freopen(_filename,"w",stdout)
#define read2(_nowans1,_nowans2) scanf("%d %d",&_nowans1,&_nowans2)
#define msn(_data,_nowans) memset(_data,_nowans,sizeof(_data))
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define read3(_nowans1,_nowans2,_nowans3) scanf("%d %d %d",&_nowans1,&_nowans2,&_nowans3)
#define lb( _x , _y ) ( lower_bound( _x.begin() , _x.end() , _y ) - _x.begin() + 1 )
using namespace std;
_tp<_tyn T>void mymax( T &_a , T _b ){ if( _a < _b ) _a = _b; }
_tp<_tyn T>void mymin( T &_a , T _b ){ if( _a > _b ) _a = _b; }
void print( int _x ){ printf("%d\n",_x); }
_tp<_tyn T>void print( T _data[] , int _size ){
	for( int i = 1 ; i <= _size ; i++ )
		cout << _data[i] << " ";
	cout << endl;
}
#define MAXN 110

int n;
int dat[MAXN];

bool able[MAXN];
bool ji[MAXN];
bool ou[MAXN];
int main(){
	//fin( "A.txt" );

	while( scanf("%d",&n) != EOF ){
		for( int i = 1 ; i <= n ; i++ )
			read(dat[i]);

		if( !(dat[1]&1)  ||  !(dat[n]&1) ){
			printf("No\n");
			continue;
		}

		ms( able );
		ms( ji );
		ms( ou );
		able[n] = 1;
		ji[n] = 1;
		able[n+1] = 1;
		ou[n+1] = 1;
		for( int i = n-1 ; i >= 1 ; i-- ){
			if( !( dat[i] & 1 ) ) continue;
			for( int j = i ; j <= n+1 ; j++ ){
				if( !(( j-i ) & 1 ) ) continue;
				if( able[j] ){
					able[i] = 1;
					if( ji[j] ) ou[i] = 1;
					if( ou[j] ) ji[i] = 1;
				}
			}
		}

		if( able[1]  &&  ji[1] ) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}