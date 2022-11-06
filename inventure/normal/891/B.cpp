#include <bits/stdc++.h>

using namespace std;

int n , a[55] , b[55] , mx = 0;

int main( int argc , char * argv[] ){
	cin >> n;
	for(int i = 1 ; i <= n ; ++ i){
		cin >> a[i] , b[i] = a[i];
		mx = max( mx , a[i] );
	}
	sort( b + 1 , b + n + 1 );;
	for(int i = 1 ; i <= n ; ++ i)
		for(int j = 1 ; j <= n ; ++ j)
			if( a[i] - b[j] == 0 ){
				if( j == 1 ) printf( "%d " , mx );
				else printf( "%d " , b[j - 1] );
				break;
			}
	puts( "" );
	return 0;
}