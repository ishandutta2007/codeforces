#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m;
int a[120000] , f[120000];
int b[120000];
int time[120000];
bool check ( int x ) {
	int i , need , sum;
	for ( i = 1 ; i <= m ; i++ ) f[i] = 0;
	for ( i = 1 ; i <= n ; i++ ) time[i] = 0;
	for ( i = x ; i >= 1 ; i-- ) {
		if ( a[i] != 0 && f[a[i]] == 0 ) {
			time[i] = 1;
			f[a[i]] = 1;
		}
	}
	need = 0; sum = 0;
	for ( i = 1 ; i <= x ; i++ ) {
		if ( time[i] == 1 ) need += b[a[i]] + 1, sum++;
		if ( need > i ) return false;
	}
	if ( sum < m ) return false;
	return true;
}
void work () {
	int i , l , r , mid , ans;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	for ( i = 1 ; i <= m ; i++ ) scanf ( "%d" , &b[i] );
	l = 1; r = n + 1;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		if ( check ( mid ) == true ) r = mid;
		else l = mid;
	}
	if ( check ( l ) == true ) ans = l;
	else ans = r;
	if ( ans == n + 1 ) ans = -1;
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}