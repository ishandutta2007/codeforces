#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
long long x , y , l , r;
long long xx[200] , yy[200];
long long s[20000];
long long ans;
void work () {
	long long i , j , kx , ky , k;
	scanf ( "%I64d%I64d%I64d%I64d" , &x , &y , &l , &r );
	kx = ky = k = 0;
	for ( i = 1 ; r / i >= x ; i = i * x ) {
		xx[++kx] = i;
	}
	if ( i <= r ) xx[++kx] = i;
	for ( i = 1 ; r / i >= y ; i = i * y ) {
		yy[++ky] = i;
	}
	if ( i <= r ) yy[++ky] = i;
	for ( i = 1 ; i <= kx ; i++ ) for ( j = 1 ; j <= ky ; j++ ) {
		if ( l <= xx[i] + yy[j] && xx[i] + yy[j] <= r ) s[++k] = xx[i] + yy[j];
	}
	sort ( s + 1 , s + 1 + k );
	s[0] = l - 1; s[k+1] = r + 1;
	ans = 0;
	for ( i = 1 ; i <= k + 1 ; i++ ) {
		ans = max ( ans , s[i] - s[i-1] - 1 );
		//printf ( "%I64d\n" , s[i] );
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}