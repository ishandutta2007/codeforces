#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int q;
map < long long , long long > m;
long long ans;
int log ( long long x ) {
	int k = 0;
	while ( x != 1 ) {
		k++; x >>= 1;
	}
	return k;
}
void work () {
	long long i , op , u , v , w , d1 , d2;
	scanf ( "%d" , &q );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%I64d%I64d%I64d" , &op , &u , &v );
		if ( op == 1 ) {
			scanf ( "%I64d" , &w );
			d1 = log ( u ); d2 = log ( v );
			if ( d1 < d2 ) swap ( d1 , d2 ), swap ( u , v );
			while ( d1 > d2 ) {
				m[u] += w;
				u >>= 1; d1--;
			}
			while ( u != v ) {
				m[u] += w; m[v] += w;
				u >>= 1; v >>= 1;
			}
		}
		else {
			ans = 0;
			d1 = log ( u ); d2 = log ( v );
			if ( d1 < d2 ) swap ( d1 , d2 ), swap ( u , v );
			while ( d1 > d2 ) {
				ans += m[u];
				u >>= 1; d1--;
			}
			while ( u != v ) {
				ans += m[u] + m[v];
				u >>= 1; v >>= 1;
			}
			printf ( "%I64d\n" , ans );
		}
	}
}
int main () {
	work ();
	return 0;
}