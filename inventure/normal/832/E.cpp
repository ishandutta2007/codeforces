#include <bits/stdc++.h>

using namespace std;

const int maxn = 500 + 15;

const int mod = 5;
const int mod2 = 1e9 + 7;

int A[maxn][maxn];

inline int mul( int x , int y ){
	return 1LL * x * y % mod;
}

inline void upd( int & x , int y ){
	x += y;
	if( x >= mod )
		x -= mod;
}

int power_mod( int x , int y ){
	int ret = 1;
	while( y ){
		if( y & 1 )
			ret = mul( ret , x );
		y >>= 1;
		x = mul( x , x );
	}
	return ret;
}

int power_mod2( int x , int y ){
	int ret = 1;
	while( y ){
		if( y & 1 )
			ret = 1LL * ret * x % mod2;
		y >>= 1;
		x = 1LL * x * x % mod2;
	}
	return ret;
}

void Gauss( int N , int M , int mat[][maxn] ){
	int cur = 0;
	for(int j = 0 ; j < M ; ++ j){
		int nxt = -1;
		for(int i = cur ; i < N ; ++ i)
			if( mat[i][j] ){
				nxt = i;
				break;
			}
		if( nxt == -1 )
			continue;
		for(int i = 0 ; i < M ; ++ i)
			swap( mat[cur][i] , mat[nxt][i] );
		for(int k = 0 ; k < N ; ++ k)
			if( mat[k][j] && k != cur ){
				int z = mul( power_mod( mat[cur][j] , mod - 2 ) , mat[k][j] );
				for(int v = j ; v <= M ; ++ v)
					upd( mat[k][v] , mod - mul( z , mat[cur][v] ) );
			}
		++ cur;
	}
}

int n , m , has[maxn];
char s[maxn];

void Display(){
	for(int i = 0 ; i < n ; ++ i){
		for(int j = 0 ; j < m ; ++ j)
			printf( "%d " , A[i][j] );
		puts( "" );
	}
}

vector < int > f;

int main( int argc , char * argv[] ){
	scanf( "%d%d" , & n , & m );
	for(int i = 0 ; i < n ; ++ i){
		scanf( "%s" , s );
		for(int j = 0 ; j < m ; ++ j)
			A[i][j] = s[j] - 'a';
	}
	Gauss( n , m , A );
	int q ;
	scanf( "%d" , & q );
	int cnt = 0;
	for(int i = 0 ; i < n ; ++ i){
		int ok = 1;
		for(int j = 0 ; j < m ; ++ j){
			ok &= ( A[i][j] == 0 );

		}
		if( ok )
			++ cnt;
		else
			f.emplace_back( i );
	}
	int base = power_mod2( 5 , cnt );
	while( q -- ){
		scanf( "%s" , s );
		int ans = 1;
		for(int i = 0 ; i < m ; ++ i)
			s[i] -= 'a';
		for(auto x : f){
			int z ;
			for(int j = 0 ; j < m ; ++ j)
				if( A[x][j] != 0 ){
					z = j;
					break;
				}
			int ww = mul( power_mod( A[x][z] , mod - 2 ) , s[z] );
			for(int j = 0 ; j < m ; ++ j)
				s[j] = ( s[j] - ww * A[x][j] + 5 ) % 5;
		}
		for(int i = 0 ; i < m ; ++ i)
			if( s[i] ){
				ans = 0;
				break;
			}
		ans = 1LL * ans * base % mod2;
		printf( "%d\n" , ans );
	}
	return 0;
}