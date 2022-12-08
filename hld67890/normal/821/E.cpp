#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long NN = 120;
const long long mod = 1000000007;
struct matrix {
	long long n , m;
	long long a[20][20];
} pos , tmp;
long long n , tar;
long long a[NN] , b[NN] , c[NN];
matrix operator * ( matrix x1 , matrix x2 ) {
	matrix y;
	long long i , j , k;
	y.n = x1.n; y.m = x2.m;
	for ( i = 1 ; i <= y.n ; i++ ) for ( j = 1 ; j <= y.m ; j++ ) y.a[i][j] = 0;
	for ( i = 1 ; i <= x1.n ; i++ ) for ( j = 1 ; j <= x2.m ; j++ ) for ( k = 1 ; k <= x1.m ; k++ ) {
		y.a[i][j] = (y.a[i][j] + x1.a[i][k] * x2.a[k][j]) % mod;
	}
	return y;
}
matrix pow ( matrix f , long long x ) {
	matrix s;
	long long i , j;
	s.n = s.m = f.n;
	for ( i = 1 ; i <= s.n ; i++ ) for ( j = 1 ; j <= s.m ; j++ ) s.a[i][j] = 0;
	for ( i = 1 ; i <= s.n ; i++ ) s.a[i][i] = 1;
	while ( x ) {
		if ( x % 2 == 1 ) s = s * f;
		f = f * f; x >>= 1;
	}
	return s;
}
void work () {
	long long i , j , k;
	scanf ( "%I64d%I64d" , &n , &tar );
	pos.n = 1; pos.m = 16;
	pos.a[1][1] = 1;
	tmp.n = tmp.m = 16;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d%I64d%I64d" , &a[i] , &b[i] , &c[i] );
		if ( i == n ) b[i] = tar;
		for ( j = 1 ; j <= 16 ; j++ ) for ( k = 1 ; k <= 16 ; k++ ) {
			tmp.a[j][k] = 0;
		}
		for ( j = 1 ; j <= c[i] + 1 ; j++ ) {
			if ( j != 1 ) tmp.a[j-1][j]++;
			tmp.a[j][j]++;
			if ( j != c[i] + 1 ) tmp.a[j+1][j]++;
		}
		//for ( j = 1 ; j <= 15 ; j++ ,printf ("\n")) for ( k = 1 ; k <= 15 ; k++ ) {
		//	printf ( "%I64d " , tmp.a[j][k] );
		//}
		tmp = pow ( tmp , b[i] - a[i] );
		pos = pos * tmp;
		//for ( j = 1 ; j <= 15 ; j++ ) printf ( "%I64d\n" , pos.a[1][j] );
	}
	printf ( "%I64d\n" , pos.a[1][1] );
}
int main () {
	work ();
	return 0;
}