#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 50;

int f[maxn] , g[maxn];
vector < int > vi[10];

int getf( int x ){
	if( ~f[x] ) return f[x];
	int & ans = f[x] = 1;
	while( x ){
		int t = x % 10;
		x /= 10;
		if( t ) ans = ans * t;
	}
	return ans;
}

int getg( int x ){
	if( ~g[x] ) return g[x];
	int & ans = g[x] = 0;
	if( x < 10 ) return ans = x;
	return ans = getg( getf( x ) );
}

int main( int argc , char * argv[] ){
	memset( f , -1 , sizeof( f ) );
	memset( g , -1 , sizeof( g ) );
	for(int i = 1 ; i <= 1000000 ; ++ i){
		int w = getg( i );
		if( w >= 1 && w <= 9 )
			vi[w].push_back( i );
	}
	int Q;
	scanf( "%d" , & Q );
	while( Q -- ){
		int l , r , x;
		scanf( "%d%d%d" , & l , & r , & x );
		printf( "%d\n" , upper_bound( vi[x].begin() , vi[x].end() , r ) - lower_bound( vi[x].begin() , vi[x].end() , l ) );
	}
	return 0;
}