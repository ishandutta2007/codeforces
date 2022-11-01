/*
Id: interes1
PROG: shopping
LANG: C++
*/
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

double h,m,s;
double t1,t2;
void ok(){
	cout << "YES" << endl;
	exit(0);
}
bool can1 = 1 , can2 = 1;
int main(){
	cin >> h >> m >> s >> t1 >> t2;
	h *= 5.00; t1 *= 5.00; t2 *= 5.00;
	m += s / 60.00;
	if( m > 60.00 ) m -= 60.00;
	h += m / 12.00;
	if( h >= 60.00 ) h -= 60.00;
	if( t1 >= 60.00 ) t1 -= 60.00;
	if( t2 >= 60.00 ) t2 -= 60.00;
	if( s > 60.00 ) s -= 60.00;
	if( h == t1  ||  m == t1  ||  s == t1 ) can1 = can2 = 0;
	if( h == t2  ||  m == t2  ||  s == t2 ) can1 = can2 = 0;
	if( t1 > t2 ) swap(t1,t2);
	if( h > t1  &&  h < t2 ) can1 = 0;
	if( h < t1  || h > t2 ) can2 = 0;
	if( m > t1  &&  m < t2 ) can1 = 0;
	if( m < t1  || m > t2  ) can2 = 0;
	if( s > t1  &&  s < t2 ) can1 = 0;
	if( s < t1  || s > t2  ) can2 = 0;
	//cout << h << endl << m << endl << s << endl << t1 << endl << t2 << endl;
	if( can1 | can2 ) ok();
	cout << "NO\n";
	return 0;
}