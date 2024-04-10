#include <bits/stdc++.h>

using namespace std;
const int maxn = 100 + 15;
int n , a , b , x[maxn] , y[maxn];

int Check( int x1 , int y1 , int x2 , int y2 ){
	if( x1 + x2 <= a && max( y1 , y2 ) <= b ) return 1;
	if( x1 + x2 <= b && max( y1 , y2 ) <= a ) return 1;
	if( max( x1 , x2 ) <= a && y1 + y2 <= b ) return 1;
	if( max( x1 , x2 ) <= b && y1 + y2 <= a ) return 1;
	return 0;
}

int main( int argc , char * argv[] ){
	scanf( "%d%d%d" , & n , & a , & b );
	for(int i = 1 ; i <= n ; ++ i) scanf( "%d%d" , x + i , y + i );
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i)
		for(int j = i + 1 ; j <= n ; ++ j){
			int ok = 0;
			ok |= Check( x[i] , y[i] , x[j] , y[j] );
			ok |= Check( x[i] , y[i] , y[j] , x[j] );
			ok |= Check( y[i] , x[i] , x[j] , y[j] );
			ok |= Check( y[i] , x[i] , y[j] , x[j] );
			if( ok )
				ans = max( ans , y[i] * x[i] + y[j] * x[j] );
		}
	printf( "%d\n" , ans );
	return 0;
}