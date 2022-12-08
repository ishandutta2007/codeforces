#include <stdio.h>
#include <algorithm>

using namespace std;

long long n , d , m;
long long a[120000];
long long x[120000] , y[120000] , cx , cy;
long long ans;
bool cmp ( long long x1 , long long x2 ) {
	return x1 > x2;
}
void work () {
	long long i , j , t;
	scanf ( "%lld%lld%lld" , &n , &d , &m );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &a[i] );
		if ( a[i] <= m ) x[++cx] = a[i];
		else y[++cy] = a[i];
	}
	sort ( x + 1 , x + 1 + cx , cmp );
	sort ( y + 1 , y + 1 + cy , cmp );
	for ( i = 2 ; i <= cx ; i++ ) x[i] += x[i-1];
	for ( i = 2 ; i <= cy ; i++ ) y[i] += y[i-1];
	/*for ( i = 1 ; i <= cx ; i++ ) {
		printf ( "%d " , x[i] );
	}
	printf ( "\n" );
	for ( i = 1 ; i <= cy ; i++ ) {
		printf ( "%d " , y[i] );
	}*/
	j = cy;
	for ( i = 0 ; i <= cx ; i++ ) {
		while ( j > 0 && i + j * (d+1) > n ) {
			j--;
		}
		if ( j != cy && i + j * (d+1) < n ) t = j + 1;
		else t = j;
		//printf ( "%d %d %d\n" , i , j , t );
		ans = max ( ans , x[i] + y[t] );
		//printf ( "%d\n" , ans );
	}
	printf ( "%lld\n" , ans );
}
int main () {
	work ();
	return 0;
}