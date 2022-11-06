#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 15;

int n , a[maxn];

int main( int argc , char * argv[] ){
	scanf( "%d" , & n );
	int gcd = 0;
	for(int i = 1 ; i <= n ; ++ i){
		scanf( "%d" , a + i );
		gcd = __gcd( gcd , a[i] );
	}
	if( gcd > 1 ){
		puts( "-1" );
		return 0;
	}
	if( n == 1 ){
		puts( "0" );
		return 0;
	}
	int ans = 0x3f3f3f3f , cnt = 0;
	for(int i = 1 ; i <= n ; ++ i)
		if( a[i] == 1 )
			++ cnt;
	if( cnt ){
		printf( "%d\n" , n - cnt );
		return 0;
	}
	for(int i = 1 ; i <= n ; ++ i){
		int lft = a[i];
		for(int j = i + 1 ; j <= n ; ++ j){
			int x = __gcd( lft , a[j] );
			if( x > 1 ) lft = x;
			else{
				ans = min( ans , j - i );
				break;
			}
		}
	}
	printf( "%d\n" , ans + n - 1 );
	return 0;
}