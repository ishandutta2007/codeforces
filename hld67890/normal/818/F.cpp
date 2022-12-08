#include <stdio.h>
#include <algorithm>

using namespace std;

long long n;
long long ans;
long long check ( long long x ) {
	long long bri , edg , ver;
	bri = x;
	ver = n - x;
	edg = min ( x , ver*(ver-1)/2 );
	if ( x < ver*(ver-1)/2 ) return -1;
	return bri + edg;
}
void work () {
	long long l , r , mid , i , ver;
	scanf ( "%I64d" , &n );
	l = 0; r = n - 1;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		if ( check ( mid ) == -1 ) l = mid;
		else r = mid;
	}
	ans = 0;
	//printf ( "%I64d %I64d\n" , l , r );
	for ( i = max (l-10,0ll) ; i <= min (r+10,n-1) ; i++ ) {
		ver = n - i;
		ans = max ( ans , i + min ( i , ver*(ver-1)/2 ) );
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}