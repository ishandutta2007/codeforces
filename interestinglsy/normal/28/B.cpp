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
#define MAXN 150

int n;
int dsu[MAXN];
void init(){
	//out "pppppp" << n ln;
	for( int i = 1 ; i <= n ; i++ )
		dsu[i] = i;
}
int getfa( int pos ){
	if( dsu[pos] == pos ) return pos;
	return dsu[pos] = getfa( dsu[pos] );
}
void unite( int a , int b ){
	a = getfa( a );
	b = getfa( b );
	dsu[b] = a;
}
bool same( int a , int b ){
	return getfa(a) == getfa(b);
}

int final[MAXN];
int chg[MAXN];

int main(){
	//fin( "dsu_m.txt" );
	fastio;
	in n; //out n ln;
	init();
	//for( int i = 1 ; i <= n ; i++ ){
	//	cout << dsu[i];
	//	out " ";
	//}
	//cout << endl;
	for( int i = 1 ; i <= n ; i++ )
		in final[i];
	for( int i = 1 ; i <= n ; i++ ){
		int x;
		in x;
		if( i-x >= 1 ) unite( i-x , i );
		if( i+x <= n ) unite( i+x , i );
	}
	for( int i = 1 ; i <= n ; i++ )
		if( !same( i , final[i] ) ){
			out "NO" ln;
			return 0;
		}//
	out "YES" ln;
	return 0;
}