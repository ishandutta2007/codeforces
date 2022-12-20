#include "stdio.h"
#include "algorithm"

using namespace std;

int main(){

	const int MAX_N = 110;
	
	int n , x[MAX_N];
	scanf( "%d" , &n );
	for( int i = 0; i < n; i++ ){
		scanf( "%d" , &x[i] );
	}
	
	sort( x , x+n );
	
	for( int i = 0; i < n; i++ )
		printf( "%d%c" , x[i] , i==n-1?'\n':' ' );
	
	return 0;
}