#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1e5;
const int mod = 1e9 + 7;

int n , f[maxn + 1] , g[maxn + 1] , ans[maxn + 1] , w1[maxn + 1] , w2[maxn + 1];
vector < int > G[maxn + 1];

inline void Update( int & x , int y ){
	x += y;
	if( x >= mod )
		x -= mod;
}

int Power( int x , int y ){
	int ret = 1;
	x %= mod;
	while( y ){
		if( y & 1 ) ret = 1LL * ret * x % mod;
		y >>= 1;
		x = 1LL * x * x % mod;
	}
	return ret;
}

void Dfs( int u , int fa = 0 ){
	f[u] = g[u] = w1[u] = w2[u] = 1;
	if( G[u].size() == 1 && u != 1 ) return;
	for(auto && v : G[u]){
		if( v == fa )
			continue;
		Dfs( v , u );
		f[u] = 1LL * f[u] * f[v] % mod;
		g[u] = 1LL * g[u] * g[v] % mod;
	}
	w1[u] = f[u] , w2[u] = g[u];
	f[u] = g[u] = ( f[u] + g[u] ) % mod;
}

void Dfs2( int u , int _f , int _g , int fa = 0 ){
	int p1 = 1LL * w1[u] * _f % mod , p2 = 1LL * w2[u] * _g % mod;
    Update( ans[u] , p1 + p2 );
 	for(auto && v : G[u]){
		if( v == fa )
			continue;
		int c1 = 1LL * w1[u] * Power( f[v] , mod - 2 ) % mod * _f % mod;
		int c2 = 1LL * w2[u] * Power( g[v] , mod - 2 ) % mod * _g % mod;
		c1 = c2 = ( c1 + c2 ) % mod;
		if( u == 1 && G[u].size() == 1 ) c1 = c2 = 1;
		Dfs2( v , c1 , c2 , u );
	}
}

int main( int argc , char * argv[] ){
	scanf( "%d" , & n );
	if( n == 1 ){
		puts( "1" );
		return 0;
	}
	for(int i = 2 ; i <= n ; ++ i){
		int u , v;
		scanf( "%d%d" , & u , & v );
		G[u].emplace_back( v );
		G[v].emplace_back( u );
	}
	Dfs( 1 );
	Dfs2( 1 , 1 , 1 );
	int ret = 0;
	for(int i = 1 ; i <= n ; ++ i) Update( ret , ans[i] );
	printf( "%d\n" , ret );
	return 0;
}