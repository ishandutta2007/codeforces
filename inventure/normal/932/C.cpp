#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e6 + 10;

int n , a , b , ans[maxn];

int main( int argc , char * argv[] ){
	scanf( "%d%d%d" , & n , & a , & b );
	int tx = -1 , ty = -1;
	for(int i = 0 ; i * a <= n ; ++ i)
		if( ( n - i * a ) % b == 0 ){
			tx = i;
			ty = ( n - i * a ) / b;
		}
	if( tx == -1 ){
		puts( "-1" );
		return 0;
	}
	for(int i = 1 ; i <= n ; )
		if( tx ){
			for(int j = 0 ; j < a ; ++ j)
				ans[i + j] = i + ( j + 1 ) % a;
			-- tx;
			i += a;
		}else{
			for(int j = 0 ; j < b ; ++ j)
				ans[i + j] = i + ( j + 1 ) % b;
			-- ty;
			i += b;
		}
	for(int i = 1 ; i <= n ; ++ i){
		if( i > 1 ) putchar( 32 );
		printf( "%d" , ans[i] );
	}
	puts( "" );
	return 0;
}