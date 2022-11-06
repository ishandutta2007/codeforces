#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1000 + 50;
const int inf = 0x3f3f3f3f;
 
template < typename T >
void Read( T & x ){
	x=0;
	char ch;
	for( ch = getchar() ; ch < '0' || ch > '9' ; ch = getchar() );
	for( ; ch <= '9' && ch >= '0' ; ch = getchar() ) x = x * 10 + ch - '0';
}

int a[55];

int main( int argc , char * argv[] ){
	//freopen( "Sample" , "r" , stdin );
	int n;
	Read( n );
	for(int i = 1 ; i <= n ; ++ i) Read( a[i] );
	sort( a + 1 , a + n + 1 );
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i)
		ans += ( a[i] - a[i - 1] - 1 );
	ans -= (25 - n);
	cout << max( 0 , ans ) << endl;
	return 0;
}