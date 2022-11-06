#include <bits/stdc++.h>

using namespace std;
const int maxn = 100 + 5;
int n , m , vis[maxn][maxn] , dir[4][2] = {-1,0,1,0,0,-1,0,1};
char s[maxn][maxn];
pair < int , int > lft , rht;
set < pair < int , int > > fk;

inline bool inmap( int x , int y ){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

int get( char c ){
	if( c == 'R' ) return 0;
	else if( c == 'G' ) return 1;
	return 2;
}

void Dfs( int x , int y ){
	lft = min( lft , make_pair( x , y ) );
	rht = max( rht , make_pair( x , y ) );
	for(int i = 0 ; i < 4 ; ++ i){
		int newx = x + dir[i][0] , newy = y + dir[i][1];
		if( inmap( newx , newy ) && s[newx][newy] == s[x][y] && !vis[newx][newy] ){
			vis[newx][newy] = 1;
			Dfs( newx , newy );
		}
	}
}

int main( int argc , char * argv[] ){
	scanf( "%d%d" , & n , & m );
	for(int i = 1 ; i <= n ; ++ i) scanf( "%s" , s[i] + 1 );
	int cnt = 0 , mask = 0;
	for(int i = 1 ; i <= n ; ++ i)
		for(int j = 1 ; j <= m ; ++ j)
			if( !vis[i][j] ){
				++ cnt , mask |= (1 << get( s[i][j] ) );
				lft = rht = make_pair( i , j );
				vis[i][j] = 1;
				Dfs( i , j );
				for(int r = lft.first ; r <= rht.first ; ++ r)
					for(int c = lft.second ; c <= rht.second ; ++ c)
						if( s[r][c] != s[i][j] ){
							puts( "NO" );
							return 0;
						}
				fk.insert( make_pair( rht.first - lft.first , rht.second - lft.second ) );
			}
	if( cnt == 3 && mask == 7 && fk.size() == 1 )
		puts( "YES" );
	else
		puts( "NO" );
	return 0;
}