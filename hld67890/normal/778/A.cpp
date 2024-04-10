#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 210000;
int l1 , l2;
char z1[maxn] , z2[maxn];
int a[maxn];
int f[maxn];
bool check ( int x ) {
	int i , t;
	for ( i = 1 ; i <= l1 ; i++ ) f[i] = 0;
	for ( i = 1 ; i <= x ; i++ ) f[a[i]] = 1;
	t = 0;
	for ( i = 1 ; i <= l1 ; i++ ) {
		while ( f[i] == 1 ) i++;
		if ( t < l2 && z1[i] == z2[t+1] ) t++;
	}
	if ( t == l2 ) return true;
	return false;
}
void work () {
	int i , l , r , mid;
	scanf ( "%s" , z1 + 1 );
	scanf ( "%s" , z2 + 1 );
	l1 = strlen ( z1 + 1 ); l2 = strlen ( z2 + 1 );
	for ( i = 1 ; i <= l1 ; i++ ) scanf ( "%d" , &a[i] );
	l = 0; r = l1;
	while ( l + 1 < r ) {
		mid = (l+r)/2;
		if ( check ( mid ) == true ) l = mid;
		else r = mid;
	}
	if ( check ( r ) == true ) printf ( "%d\n" , r );
	else printf ( "%d\n" , l );
}
int main () {
	work ();
	return 0;
}