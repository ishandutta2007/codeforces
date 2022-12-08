#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long NN = 510000;
long long n , p , q , r;
long long xy[NN] , xz[NN] , yx[NN] , yz[NN] , zx[NN] , zy[NN];
long long sum;
long long ans;
void work () {
	long long i , j , k , x , y , z;
	scanf ( "%I64d%I64d%I64d%I64d" , &n , &p , &q , &r );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d%I64d%I64d" , &x , &y , &z );
		xy[x] = max ( xy[x] , y );
		xz[x] = max ( xz[x] , z );
		yx[y] = max ( yx[y] , x );
		yz[y] = max ( yz[y] , z );
		zx[z] = max ( zx[z] , x );
		zy[z] = max ( zy[z] , y );
	}
	for ( i = p ; i >= 1 ; i-- ) {
		xy[i] = max ( xy[i] , xy[i+1] );
		xz[i] = max ( xz[i] , xz[i+1] );
	}
	for ( i = q ; i >= 1 ; i-- ) {
		yx[i] = max ( yx[i] , yx[i+1] );
		yz[i] = max ( yz[i] , yz[i+1] );
	}
	for ( i = r ; i >= 1 ; i-- ) {
		zx[i] = max ( zx[i] , zx[i+1] );
		zy[i] = max ( zy[i] , zy[i+1] );
	}
	for ( i = 1 ; i <= p ; i++ ) {
		ans += xz[i] * q;
	}
	for ( i = 1 ; i <= q ; i++ ) {
		ans += yz[i] * p;
	}
	for ( i = 1 ; i <= p ; i++ ) {
		ans += xy[i] * r;
	}
	//printf ( "%I64d\n" , ans );
	for ( i = 1 ; i <= p ; i++ ) {
		ans -= xz[i] * xy[i];
	}
	for ( i = 1 ; i <= q ; i++ ) {
		ans -= yx[i] * yz[i];
	}
	for ( i = 1 ; i <= r ; i++ ) {
		ans -= zx[i] * zy[i];
	}
	//printf ( "%I64d\n" , ans );
	j = xy[1];
	sum = 0; k = 0;
	for ( i = 1 ; i <= xy[1] ; i++ ) {
		sum += min ( xz[1] , yz[i] );
		if ( yz[i] >= xz[1] ) k++;
	}
	ans += sum;
	for ( i = 2 ; i <= p ; i++ ) {
		while ( j > xy[i] ) {
			sum -= min ( xz[i-1] , yz[j] );
			j--;
		}
		if ( k > j ) k = j;
		sum -= k * (xz[i-1]-xz[i]);
		while ( k < j && yz[k+1] >= xz[i] ) {
			sum -= yz[k+1] - xz[i];
			k++;
		}
		//printf ( "%I64d\n" , sum );
		ans += sum;
	}
	//printf ( "%I64d\n" , ans );
	printf ( "%I64d\n" , p * q * r - ans );
}
int main () {
	//FILE *fpr = freopen ( "d.in" , "r" , stdin );
	//FILE *fpw = freopen ( "d.out" , "w" , stdout );
	work ();
	return 0;
}