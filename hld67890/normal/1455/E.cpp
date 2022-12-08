#include <stdio.h>
#include <algorithm>

using namespace std;

struct point {
	long long x , y;
} b[10] , p[12];
long long a[10];
long long ans;
long long check ( long long l ) {
	long long x[10] , y[10];
	x[1] = p[1].x; x[2] = p[2].x - l + 1;
	x[3] = p[3].x; x[4] = p[4].x - l + 1;
	y[1] = p[1].y; y[3] = p[3].y - l + 1;
	y[2] = p[2].y; y[4] = p[4].y - l + 1;
	sort ( x + 1 , x + 1 + 4 );
	sort ( y + 1 , y + 1 + 4 );
	return y[4]+y[3]-y[2]-y[1]+x[4]+x[3]-x[2]-x[1];
}
long long solve () {
	long long i , ret = 21474836477777ll;
	long long l = 0 , r = 2000000000 , m1 , m2;
	long long tl , t1 , t2 , tr;
	while ( l < r - 10 ) {
		m1 = l + (r-l) / 3;
		m2 = l + (r-l) / 3 * 2;
		tl = check ( l );
		t1 = check ( m1 );
		t2 = check ( m2 );
		tr = check ( r );
		if ( tl >= t1 && t1 >= t2 ) {
			l = m1;
		}
		else {
			r = m2;
		}
		//printf ( "@@ %lld %lld\n" , l , r );
	}
	for ( i = max ( 0ll , l - 3 ) ; i <= r + 3 ; i++ ) {
		ret = min ( ret , check ( i ) );
	}
	return ret;
}
void work () {
	long long i;
	for ( i = 1 ; i <= 4 ; i++ ) {
		scanf ( "%lld%lld" , &b[i].x , &b[i].y );
		a[i] = i;
	}
	ans = 21474836477777ll;
	do {
		for ( i = 1 ; i <= 4 ; i++ ) {
			p[i] = b[a[i]];
		}
		ans = min ( ans , solve () );
	} while ( next_permutation ( a + 1 , a + 1 + 4 ) );
	printf ( "%lld\n" , ans );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}