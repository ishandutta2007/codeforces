#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int a[310000] , b[310000];
char z[610000];
int mxa , mna , mxb , mnb , mxm , mnm;
int xl , xr , yl , yr , ml , mr;
int ans , ansi , ansj;
int dis ( int s , int t , int i ) {
	int ret = 0;
	if ( (a[i]<=s) == (b[i]<=t) ) {
		ret = max ( abs(a[i]-s) , abs(b[i]-t) );
	}
	else {
		ret = abs(a[i]-s) + abs(b[i]-t);
	}
	return ret;
}
int chkpos ( int x , int y ) {
	if ( x < xl ) x = xl;
	if ( x > xr ) x = xr;
	if ( y < yl ) y = yl;
	if ( y > yr ) y = yr;
	if ( xl <= x && x <= xr && yl <= y && y <= yr && ml <= x - y && x - y <= mr ) {
		ansi = x;
		ansj = y;
		return 1;
	}
	return 0;
}
int check ( int x ) {
	int i , j , ret = 0;
	xl = mxa - x; xr = mna + x;
	yl = mxb - x; yr = mnb + x;
	ml = mxm - x; mr = mnm + x;
	//if ( x == 1 ) printf ( "%d %d %d %d %d %d\n" , xl , xr , yl , yr , ml , mr );
	if ( xl > xr ) return 0;
	if ( yl > yr ) return 0;
	if ( ml > mr ) return 0;
	if ( xl < 0 ) xl = 0;
	if ( yl < 0 ) yl = 0;
	if ( chkpos ( xl , yl ) || chkpos ( xl , yr ) || chkpos ( xr , yl ) || chkpos ( xr , yr ) || chkpos ( xl , xl - ml ) || chkpos ( xl , xl - mr ) || chkpos ( xr , xr - ml ) || chkpos ( xr , xr - mr ) || chkpos ( yl + ml , yl ) || chkpos ( yl + mr , yl ) || chkpos ( yr + ml , yr ) || chkpos ( yr + mr , yr ) ) {
		ans = x;
		return 1;
	}
	return 0;
}
void work () {
	int i , j , l , r , mid;
	scanf ( "%d" , &n );
	mna = mnb = mnm = 999999;
	mxm = -999999;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s" , z + 1 );
		l = strlen ( z + 1 );
		for ( j = 1 ; j <= l ; j++ ) {
			if ( z[j] == 'B' ) a[i]++;
			else b[i]++;
		}
		mxa = max ( mxa , a[i] );
		mna = min ( mna , a[i] );
		mxb = max ( mxb , b[i] );
		mnb = min ( mnb , b[i] );
		mxm = max ( mxm , a[i] - b[i] );
		mnm = min ( mnm , a[i] - b[i] );
	}
	ans = 999999;
	l = 0; r = 999999;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		if ( check ( mid ) ) r = mid;
		else l = mid;
	}
	check ( l );
	printf ( "%d\n" , ans );
	if ( ansi == 0 && ansj == 0 ) {
		ansi = ansj = 1;
	}
	for ( i = 1 ; i <= ansi ; i++ ) {
		printf ( "B" );
	}
	for ( i = 1 ; i <= ansj ; i++ ) {
		printf ( "N" );
	}
	printf ( "\n" );
}
int main () {
	work ();
	return 0;
}