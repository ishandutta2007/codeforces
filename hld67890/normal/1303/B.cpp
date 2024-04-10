#include <stdio.h>
#include <algorithm>

using namespace std;

long long n , g , b;
long long check ( long long x ) {
	long long i , good , bad , tot;
	tot = x / (g+b);
	good = tot * g;  bad = tot * b;
	x -= tot * (g+b);
	if ( x > g ) {
		good += g;
		bad += x - g;
	}
	else good += x;
	//printf ( "%lld %lld %lld %lld\n" , x + tot * (g+b), tot , good , bad );
	bad = min ( bad , n / 2 );
	if ( good + bad >= n ) return true;
	return false;
}
void work () {
	long long i , l , r , mid;
	scanf ( "%lld%lld%lld" , &n , &g , &b );
	l = 0; r = 2100000000000000000ll;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		if ( check ( mid ) == true ) r = mid;
		else l = mid;
	}
	printf ( "%lld\n" , r );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}