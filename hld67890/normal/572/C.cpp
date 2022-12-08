#include <iostream>
#include <stdio.h>

using namespace std;

long long a , b , c , l;
long long ans , maxx , x;
void work () {
	long long i , j;
	scanf ( "%I64d%I64d%I64d%I64d" , &a , &b , &c , &l );
	maxx = (l+1)*(l+2)*(l+3)/6;
	for ( i = max ( 0ll , c + b - a ) ; i <= l ; i++ ) {
		x = min ( l - i , a - b - c + i );
		ans += (x+1)*(x+2)/2;
	}
	for ( i = max ( 0ll , c + a - b ) ; i <= l ; i++ ) {
		x = min ( l - i , b - a - c + i );
		ans += (x+1)*(x+2)/2;
	}
	for ( i = max ( 0ll , a + b - c ) ; i <= l ; i++ ) {
		x = min ( l - i , c - b - a + i );
		ans += (x+1)*(x+2)/2;
	}
	//cout << maxx << " " << ans << endl;
	printf ( "%I64d\n" , maxx - ans );
}
int main () {
	work ();
	return 0;
}