#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1000 + 15;

int power( int x , int y ){
	int ret = 1;
	while( y ){
		if( y & 1 ) ret = 1ll * ret * x % mod;
		y >>= 1;
		x = 1ll * x * x % mod;
	}
	return ret;
}

int k , ta , tb , pa , pb , f[maxn][maxn] , ans;

inline void ins( int & x , int y ){
	if( ( x += y ) >= mod ) x -= mod;
}

int main( int argc , char * argv[] ){
	scanf( "%d%d%d" , & k , & ta , & tb );
	pa = 1ll * ta * power( ta + tb , mod - 2 ) % mod;
	pb = 1ll * tb * power( ta + tb , mod - 2 ) % mod;
	f[1][0] = 1;
	for(int i = 1 ; i < k ; ++ i)
		for(int j = 0 ; j < k ; ++ j)
			if( f[i][j] ){
				ins( f[i + 1][j] , 1ll * f[i][j] * pa % mod );
				if( i + j >= k ) ins( ans , 1ll * f[i][j] * pb % mod * (i + j) % mod );
				else ins( f[i][i + j] , 1ll * f[i][j] * pb % mod );
			}
	for(int j = 0 ; j < k ; ++ j)
		if( f[k][j] ){
			int K = k + j;
			int z = 1ll * pb * ( ( ( 1ll * pa * K % mod - K - pa ) % mod + mod ) % mod ) % mod * power( pa - 1 + mod , mod - 2 ) % mod * power( pa - 1 + mod , mod - 2 ) % mod * f[k][j] % mod;
			ins( ans , mod - z );
		}
	printf( "%d\n" , ans );
	return 0;
}