#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

const int maxn = 100 + 15;

int n , m , f[maxn][maxn][26];
vector < pair < int , char > > G[maxn];
char s[5];

int Dfs( int a , int b , int c ){
	if( ~f[a][b][c] ) return f[a][b][c];
	int & ans = f[a][b][c] = 0;
	for(auto it : G[a])
		if( it.second >= c && !Dfs( b , it.first , it.second ) ){
			ans = 1;
			break;
		}
	return ans;
}

int main( int argc , char * argv[] ){
	scanf( "%d%d" , & n , & m );
	memset( f , -1 , sizeof( f ) );
	for(int i = 1 ; i <= m ; ++ i){
		int u , v;
		scanf( "%d%d%s" , & u , & v , s );
		G[u].push_back( make_pair( v , s[0] - 'a' ) );
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j)
			if( Dfs( i , j , 0 ) )
				putchar( 'A' );
			else
				putchar( 'B' );
		puts( "" );
	}
	return 0;
}