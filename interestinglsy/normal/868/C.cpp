#include <bits/stdc++.h>
#define F first
#define S second
#define dq deque
#define vc vector
#define INF ((int)(1e9))
#define LINF ((int)(1e18))
#define pb push_back
#define mp make_pair
#define _tp template
#define _tyn typename
#define pf push_front
#define itor iterator
#define mp make_pair
#define sint short int
#define ull unsigned long long
#define pii pair<int,int>
#define uint unsigned int
#define ll long long
#define B cout << "BreakPoint" << endl;
#define read(_nowans) scanf("%d",&_nowans)
#define ms(_data) memset(_data,0,sizeof(_data))
#define fin(_filename) freopen(_filename,"r",stdin)
#define fout(_filename) freopen(_filename,"w",stdout)
#define read2(_nowans1,_nowans2) scanf("%d %d",&_nowans1,&_nowans2)
#define msn(_data,_nowans) memset(_data,_nowans,sizeof(_data))
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define read3(_nowans1,_nowans2,_nowans3) scanf("%d %d %d",&_nowans1,&_nowans2,&_nowans3)
#define lb( _x , _y ) ( lower_bound( _x.begin() , _x.end() , _y ) - _x.begin() + 1 )
using namespace std;
_tp<_tyn T>void mymax( T &_a , T _b ){ if( _a < _b ) _a = _b; }
_tp<_tyn T>void mymin( T &_a , T _b ){ if( _a > _b ) _a = _b; }
void print( int _x ){ printf("%d\n",_x); }
_tp<_tyn T>void print( int _stpos , T _data[] , int _size ){
	for( int i = _stpos ; i <= _size ; i++ )
		cout << _data[i] << ((i!=_size)?" ":"");
	cout << endl;
}
#define MAXN 100100
#define MAXK 10

int n,k;
void ok(){
	cout << "YES\n";
	exit(0);
}
void no(){
	cout << "NO\n";
	exit(0);
}
int have[300];
bool good( int a , int b ){
	for( int i = 1 ; i <= k ; i++ ){
		if( (a&1) & (b&1) ) return 0;
		a >>= 1;
		b >>= 1;
	}
	return 1;
}
int main(){
	ms( have );

	read2(n,k);
	for( int i = 1 ; i <= n ; i++ ){
		int a = 0;
		int o = 0;
		for( int j = 1 ; j <= k ; j++ ){
			//assert(k<MAXK);
			int x;
			read(x);
			a <<= 1;
			a |= x;
			o += x;
		}
		if( o == 0 ){
			ok();
		}
		have[a]++;
	}

	for( int i = 1 ; i <= (1<<k) ; i++ )
		if( have[i] )
			for( int j = 1 ; j <= (1<<k) ; j++ )
				if( have[j] )
					if( good(i,j) )
						ok();
	no();

	return 0;
}