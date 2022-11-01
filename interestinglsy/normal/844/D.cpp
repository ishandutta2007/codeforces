#include <assert.h>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#define F first
#define S second
#define qq queue
#define dq deque
#define vc vector
#define INF ((int)(2e9))
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
#define MAXN 500100

int n , x , st;

int cnt = 0;
pii ask( int x ){
	cnt++;
	printf("? %d\n",x);
	fflush(stdout);
	int a , b;
	scanf("%d %d",&a,&b);
	fflush(stdout);
	return mp( a , b );
}
void printans( int a ){
	printf("! %d\n",a);
	fflush(stdout);
	exit(0);
}
int Rand(){
	ll rett = ( rand() * rand() ) % n + 1;
	int ret = rett;
	return ret;
}

bool cantask[MAXN];
int ans = 0 , anspos = -1;

int main(){
	srand( time(0) );
	ms( cantask );
	cantask[0] = 1;

	scanf("%d %d %d",&n,&st,&x);

	while(1){
		if( cnt >= min( 1000 , n ) ) break;

		int nowask = 0;
		while( cantask[nowask] ) nowask = Rand();

		pii ret = ask( nowask );
		if( ret.F == x )
			printans(x);

		cantask[nowask] = 1;
		if( ret.F < x ){
			if( ans < ret.F ){
				ans = ret.F;
				anspos = nowask;
			}
		}else{
			if( ret.S != -1 )
				cantask[ret.S] = 1;
		}

		cnt++;
	}
	//cout << "Anspos " << anspos << endl;
	if( ans == 0 ) anspos = st;

	int nowask = anspos;
	int nowval = 0;
	cnt = 0;
	while(1){
		pii ret = ask( nowask );
		nowval = ret.F;
		if( nowval >= x ) printans( nowval );
		cnt++;
		if( cnt >= n  ||  cnt >= 990  ||  ret.S == -1 ) printans(-1);
		nowask = ret.S;
	}
	printans( Rand() );

	return 0;
}