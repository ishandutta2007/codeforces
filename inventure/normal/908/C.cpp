#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 15;

int n , R , x[maxn];
double y[maxn];

int main( int argc , char * argv[] ){
	scanf( "%d%d" , & n , & R );
	for(int i = 1 ; i <= n ; ++ i)
		scanf( "%d" , x + i );
	for(int i = 1 ; i <= n ; ++ i){
		double mx = R;
		for(int j = 1 ; j < i ; ++ j)
			if( abs( x[i] - x[j] ) <= 2 * R ){
				int dx = abs( x[i] - x[j] );
				double dy = sqrt( 4.0 * R * R - 1.0 * dx * dx );
				mx = max( mx , dy + y[j] );
			}
		y[i] = mx;
		printf( "%.10f " , y[i] );
	}
	puts( "" );
	return 0;
}