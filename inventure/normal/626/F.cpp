#include <bits/stdc++.h>

using namespace std;

const int maxn = 200 + 15;
const int mod = 1e9 + 7;

int n , K , f[maxn][1005] , g[maxn][1005] , a[maxn];

inline void Update( int & x , int y ){
	if( ( x += y ) >= mod ) x -= mod;
}

int main( int argc , char * argv[] ){
	scanf( "%d%d" , & n , & K );
	for(int i = 1 ; i <= n ; ++ i) scanf( "%d" , a + i );
	sort( a + 1 , a + n + 1 );
	auto x = f , y = g;
	x[0][0] = 1;
	for(int i = 1 ; i <= n ; ++ i , swap( x , y ) ){
		memset( y , 0 , sizeof( f ) );
		for(int j = 0 ; j <= n ; ++ j)
			for(int k = 0 ; k <= K ; ++ k)
				if( x[j][k] && k + ( a[i] - a[i - 1] ) * j <= K ){
					int ins = k + ( a[i] - a[i - 1] ) * j;
					Update( y[j][ins] , x[j][k] );
					Update( y[j][ins] , 1ll * x[j][k] * j % mod );
					if( j > 0 )	Update( y[j - 1][ins] , 1ll * x[j][k] * j % mod );
					Update( y[j + 1][ins] , x[j][k] );
				}
	}
	int ans = 0;
	for(int k = 0 ; k <= K ; ++ k)
		Update( ans , x[0][k] );
	printf( "%d\n" , ans );
	return 0;
}