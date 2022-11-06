#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int maxn = 1e5;
const int mod = 1e9 + 7;
const int mod2 = 1e9 + 9;

int n , m , len;
char t[55];
vector < pair < int , int > > vi;
map < pair < int , int > , int > f;

void Dfs( int x , int y , int z ){
	if( x == len )
		vi.emplace_back( make_pair( y , z ) );
	else{
		if( t[x] == '?' ){
			Dfs( x + 1 , y , z );
			for(int i = 'a' ; i <= 'e' ; ++ i) Dfs( x + 1 , ( 1LL * y * 233 + i ) % mod ,  ( 1LL * z * 237 + i ) % mod2 );
		}else
			Dfs( x + 1 , ( 1LL * y * 233 + t[x] ) % mod , ( 1LL * z * 237 + t[x] ) % mod2 );
	}
}

int main( int argc , char * argv[] ){
	scanf( "%d%d" , & n , & m );
	for(int i = 1 ; i <= n ; ++ i){
		scanf( "%s" , t );
		int z1 = 0 , z2 = 0;
		for( char * p = t ; *p ; ++ p) z1 = ( 1LL * z1 * 233 + *p ) % mod , z2 = ( 1LL * z2 * 237 + *p ) % mod2;
		++ f[make_pair( z1 , z2)];
	}
	while( m -- ){
		vi.clear();
		scanf( "%s" , t );
		len = strlen( t );
		Dfs( 0 , 0 , 0 );
		int ans = 0;
		sort(vi.begin(), vi.end());
		vi.resize(unique(vi.begin(), vi.end()) - vi.begin());
		for(auto && x : vi) if( f.count( x ) ) ans += f[x];
		printf( "%d\n" , ans );
	}
	return 0;
}