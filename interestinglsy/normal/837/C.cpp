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
#define INF (1e9)
#define in cin >>
#define LINF (1e18)
#define out cout <<
#define ln  << endl
#define pb push_back
#define mp make_pair
#define ll long long
#define sint short int
#define ull unsigned ll
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
#define MAXN 120

int n , xsize , ysize;

struct Yin{
	int x; int y;
};
Yin getyin( int xx , int yy ){
	Yin ret;
	ret.x = xx; ret.y = yy;
	return ret;
}
Yin yin[MAXN*2];

bool ok( int id1 , int id2 ){
	if( yin[id1].x + yin[id2].x > xsize )
		if( yin[id1].y + yin[id2].y > ysize ) return 0;
	if( yin[id1].x > xsize  ||  yin[id1].y > ysize ) return 0;
	if( yin[id2].x > xsize  ||  yin[id2].y > ysize ) return 0;
	return 1;
}
int getans( int id1 , int id2 ){
	int s1 = yin[id1].x * yin[id1].y;
	int s2 = yin[id2].x * yin[id2].y;
	return s1+s2;
}

int ans = 0;
int main(){
	//fin("C.txt");
	read3( n , xsize , ysize );
	for( int i = 1 ; i <= n ; i++ ){
		int a , b;
		read2( a , b );
		yin[i] = getyin( a , b );
		yin[i+n] = getyin( b , a );
	}
	for( int i = 1; i < n*2 ; i++ )
		for( int j = i+1 ; j <= n*2 ; j++ )
			if( i+n != j )
				if( ok( i , j ) )
					ans = max( ans , getans( i , j ) );
	printf("%d\n",ans);
}