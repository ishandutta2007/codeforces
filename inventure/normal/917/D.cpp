#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 5;
const int mod = 1e9 + 7;
int G[maxn][maxn] , A[maxn][maxn] , n , dp[maxn] , g[maxn] , w[maxn] , q[maxn];

int Power( int x , int y ){
	int ret = 1;
	while( y ){
		if( y & 1 ) ret = 1ll * ret * x % mod;
		y >>= 1;
		x = 1ll * x * x % mod;
	}
	return ret;
}

int Det( int A[maxn][maxn] , int n ){
	int ans = 1 , sgn = 0;
	for(int i = 0 , cur = 0 ; i < n ; ++ i){
		int nxt = -1;
		for(int j = cur ; j < n ; ++ j) 
			if( A[j][i] ){
				nxt = j;
				break;
			}
		if( nxt == -1 ) continue;
		if( cur != nxt ) sgn ^= 1;
		for(int j = 0 ; j < n ; ++ j) swap( A[cur][j] , A[nxt][j] );
		int t = Power( A[cur][i] , mod - 2 );
		for(int j = cur + 1 ; j < n ; ++ j){
			int z = 1ll * A[j][i] * t % mod;
			for(int k = i ; k < n ; ++ k)
				A[j][k] = ( A[j][k] - 1ll * A[cur][k] * z % mod + mod ) % mod;
		}
		++ cur;
	}
	for(int i = 0 ; i < n ; ++ i) ans = 1ll * ans * A[i][i] % mod;
	if( sgn && ans ) ans = mod - ans;
	return ans;
}

int Solve( int x ){
	memset( A , 0 , sizeof( A ) );
	for(int i = 0 ; i < n ; ++ i){
		int sum = 0;
		for(int j = 0 ; j < n ; ++ j)
			if( i != j ){
				if( G[i][j] == 1 )
					A[i][j] = x;
				else
					A[i][j] = 1;
				sum += A[i][j];
				A[i][j] = mod - A[i][j];
			}
		A[i][i] = sum;
	}
	return Det( A , n - 1 );
}

inline void Update( int & x , int y ){
	x += y;
	if( x >= mod ) x -= mod;
}

int main( int argc , char * argv[] ){
	scanf( "%d" , & n );
	for(int i = 0 ; i < n ; ++ i)
		for(int j = i + 1 ; j < n ; ++ j)
			G[i][j] = G[j][i] = 1;
	for(int i = 2 ; i <= n ; ++ i){
		int u , v;
		scanf( "%d%d" , & u , & v );
		-- u , -- v;
		G[u][v] = G[v][u] = 0;
	}
	for(int i = 0 ; i < n ; ++ i) g[i] = Solve( i );
	for(int i = 0 ; i < n ; ++ i){
		memset( dp , 0 , sizeof( dp ) );
		int y = g[i];
		dp[0] = 1;
		for(int j = 0 ; j < n ; ++ j)
			if( i != j ){
				y = 1ll * y * Power( i - j + mod , mod - 2 ) % mod;
				for(int k = n - 1 ; k >= 0 ; -- k){
					Update( dp[k + 1] , dp[k] );
					dp[k] = 1ll * dp[k] * (mod - j) % mod;
				}
			}
		for(int e = 0 ; e < n ; ++ e)
			for(int j = 0 ; j <= e ; ++ j) 
				Update( w[e] , 1ll * dp[j] * y % mod );
	}
	q[0] = w[0];
	for(int i = 1 ; i < n ; ++ i) q[i] = ( w[i] - w[i - 1] + mod ) % mod;
	for(int i = n - 1 ; i >= 0 ; -- i)
		printf( "%d " , q[i] );
	puts( "" );
	return 0;
}