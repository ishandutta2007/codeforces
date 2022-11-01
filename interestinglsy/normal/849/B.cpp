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
#define INF ((int)(2e9)+1)
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
#define read(_nowans) scanf("%d",&_nowans)
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
#define MAXN 1010
#define ld double

int n;
int yuan[MAXN];

map< pair< ld , ld > , bool > mpa;

int main(){
//	fin( "B.txt" );

	while( scanf("%d",&n) != EOF ){
		for( int i = 1 ; i <= n ; i++ )
			read(yuan[i]);
		if( n == 1 ){
			printf("No\n");
			continue;
		}
		if( n == 2 ){
			printf("Yes\n");
			continue;
		}
		mpa.clear();
		bool ok = 0;
		for( int i = 1 ; i < n ; i++ ){
			for( int j = i+1 ; j <= n ; j++ ){
				ld nowk = (ld)( yuan[j] - yuan[i] ) / (ld)(j-i);
				ld nowb = (ld)yuan[j] - j * nowk;
				if( mpa.count( mp( nowk , nowb ) ) ) continue;
				mpa[ mp( nowk , nowb ) ] = 1;
				//cout << "Sel " << i << " and " << j << endl;
				//cout << "K: " << nowk << "  B: " << nowb << endl << endl;
				bool fst = 0;
				ld dis = (ld)(2000000001);
				bool chg = 0;
				for( int k = 1 ; k <= n ; k++ ){
					if( k == i  ||  k == j ) continue;
					ld nowdis = (ld)yuan[k] - (ld)k * nowk - nowb;
					if( !nowdis ) continue;
					if( nowdis == dis ) continue;
					if( dis != INF ){
						fst = 1;
						break;
					}
					chg = 1;
					dis = nowdis;
				}
				if( !fst  &&  chg ){
					ok = 1;
					break;
				}
			}
			if( ok ) break;
		}
		if( ok ) printf("Yes\n");
		else printf("No\n");
		//return 0;
	}

	return 0;
}