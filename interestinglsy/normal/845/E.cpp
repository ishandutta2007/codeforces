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
// NO "fir0x()"!
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
#define B cout << "BreakPoint\n";
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
void print( int _x ){ printf("%d\n",_x); }
_tp<_tyn T>void print( T _data[] , int _size ){
	for( int i = 1 ; i <= _size ; i++ )
		cout << _data[i] << " ";
	cout << endl;
}
#define MAXK 510
#define MAXANS 999999999
//#define lb( _x , _y ) ( lower_bound( _x.begin() , _x.end() , _y ) - _x.begin() )
// Bad Idea!

int n , m , k;
pii dot[MAXK];

struct Seg{
	int l , r , h , dir;	//dir: 
	Seg(){}
	Seg( int li , int ri , int hi , int diri ){
		l = li; r = ri;
		h = hi; dir = diri;
	}
};
bool operator<( Seg s1 , Seg s2 ){
	return s1.h < s2.h;
}

vc<int> useful;	//
vc<Seg> seg;	//
int add[2010];
bool check( int r ){
	//cout << "---------- [Check] St to chk " << r << " ----------" << endl;
	int d = r << 1 | 1;
	bool err = 0;
	//dir=0 : 
	//dir=1 : 
	for( int dir = 0 ; dir <= 1 ; dir++ ){
		//cout << "Dir " << dir << endl;
		seg.clear();
		useful.clear();
		useful.pb(1); useful.pb(m);
		for( int i = 1 ; i <= k ; i++ ){
			//cout << "\t[LSH] " << "deal Squ " << i << " :  ";
			int leftmost , rightmost , upper , lower;
			leftmost = max( 1 , dot[i].F - r );
			rightmost = min( m , dot[i].F + r );
			upper = min( n+1 , dot[i].S + r + 1 );
			lower = max( 1 , dot[i].S - r );

			//cout << leftmost << " " << rightmost << " " << upper << " " << lower << endl;

			useful.pb( leftmost );
			useful.pb( rightmost );
			if( leftmost - 1 >= 1 ) useful.pb( leftmost - 1 );
			if( rightmost + 1 <= m ) useful.pb( rightmost + 1 );

			seg.pb( Seg( leftmost , rightmost , upper , -1 ) );
			seg.pb( Seg( leftmost , rightmost , lower , 1 ) );
		}

		sort( useful.begin() , useful.end() );
		useful.resize( unique( useful.begin() , useful.end() ) - useful.begin() );
		int usecnt = useful.size();

		for( int i = 0 ; i < ( k << 1 ) ; i++ ){
			seg[i].l = lower_bound( useful.begin() , useful.end() , seg[i].l ) - useful.begin();
			seg[i].r = lower_bound( useful.begin() , useful.end() , seg[i].r ) - useful.begin();
		}
		sort( seg.begin() , seg.end() );
		// No Unique Here!

		//cout << "Seg:  ";
		//for( uint i = 0 ; i < seg.size() ; i++ )	cout << seg[i].l << " " << seg[i].r << " " << seg[i].h << "  ,  ";
		//cout << "\nUseful:  ";
		//for( int i = 0 ; i < usecnt ; i++ ) cout << useful[i] << " "; cout << endl;

		ms( add );
		int maxx = useful[0];
		int minx = useful[usecnt-1];
		pii nowsel;	//nowselect	, [ nowsel.F , nowsel.S ]
		nowsel.F = nowsel.S = 0;
		int maxh = 0;
		while( max( nowsel.F , nowsel.S ) < ( k << 1 )  &&  seg[nowsel.F].h <= m ){
			while( nowsel.S < ( k << 1 )  &&  seg[nowsel.S].h == seg[nowsel.F].h ) nowsel.S++;
			nowsel.S--;
			if( seg[nowsel.S].h > n ) break;

			for( int i = nowsel.F ; i <= nowsel.S ; i++ )
				for( int j = seg[i].l ; j <= seg[i].r ; j++ )
					add[j] += seg[i].dir;

			for( int i = 0 ; i < usecnt ; i++ )
				if( !add[i] ){
					mymin( minx , useful[i] );
					mymax( maxx , useful[i] );
				}

			maxh = seg[nowsel.S].h;
			//cout << "At h " << seg[nowsel.F].h << "   Min: " << minx << "  Max: " << maxx << endl;
			nowsel.S++;
			nowsel.F = nowsel.S;
		}

		//cout << "\t Min: " << minx << "  Max: " << maxx << endl;
		if( maxx - minx + 1 > d ){
			//cout << "[Check] gg at " << dir << endl;
			err = 1;
		}
		if( maxh < n  &&  seg[seg.size()-1].h < n ){
			if( m > d ){
				err = 1;
			}
		}
		if( seg[0].h > 1 ){
			if( m > d ){
				err = 1;
			}
		}

		swap( n , m );
		for( int i = 1 ; i <= k ; i++ )
			swap( dot[i].F , dot[i].S );
	}

	return err ^ 1;
}

int main(){
	//fin( "E.txt" );

	read3( m , n , k );	//Yes! m,n,k! Not n,m,k!
	for( int i = 1 ; i <= k ; i++ ){
		read2( dot[i].F , dot[i].S );
	}

	//B
	//cout << check( 500 ) << endl;
	//return 0;

	int l = 0 , r = max( n , m );		// [ l , r ]
	while( l < r ){
		int mid = ( l + r ) >> 1;
		if( check( mid ) ){
			r = mid;
		}else{
			l = mid + 1;
		}
	}

	printf("%d\n",l);

	return 0;
}