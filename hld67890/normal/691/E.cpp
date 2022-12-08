#include <iostream>
#include <stdio.h>

using namespace std;

//long long
const long long mod = 1000000007;
struct matrix {
	long long n , m;
	long long a[120][120];
} tmp , tmp1;
matrix operator * ( matrix x1 , matrix x2 ) {
	matrix y;
	long long i , j , k;
	y.n = x1.n; y.m = x2.m;
	for ( i = 1 ; i <= y.n ; i++ ) for ( j = 1 ; j <= y.m ; j++ ) y.a[i][j] = 0;
	for ( i = 1 ; i <= y.n ; i++ ) for ( j = 1 ; j <= y.m ; j++ ) for ( k = 1 ; k <= x1.m ; k++ )
		y.a[i][j] = (y.a[i][j] + x1.a[i][k] * x2.a[k][j]) % mod; 
	return y;
}
long long n , k;
long long a[120];
long long ans;
matrix pow ( matrix t , long long x ) {
	matrix s , f;
	long long i , j;
	f = t;
	s.n = s.m = f.n;
	for ( i = 1 ; i <= s.n ; i++ ) for ( j = 1 ; j <= s.m ; j++ ) s.a[i][j] = 0;
	for ( i = 1 ; i <= s.n ; i++ ) s.a[i][i] = 1;
	while ( x ) {
		if ( x % 2 ) s = s * f;
		f = f * f; x >>= 1;
	}
	return s;
}
void work () {
	long long i , j , t , sum;
	scanf ( "%I64d%I64d" , &n , &k );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%I64d" , &a[i] );
	tmp.n = tmp.m = n;
	for ( i = 1 ; i <= n ; i++ ) for ( j = 1 ; j <= n ; j++ ) {
		t = a[i] ^ a[j]; sum = 0;
		while ( t ) {
			if ( t % 2 ) sum++;
			t >>= 1;
		}
		if ( sum % 3 == 0 ) tmp.a[i][j] = 1;
	}
	//for ( i = 1 ; i <= n ; i++ , cout<<endl ) for ( j = 1 ; j <= n ;j++ ) cout << tmp.a[i][j] << " ";
	tmp1.n = 1; tmp1.m = n;
	for ( i = 1 ; i <= n ; i++ ) tmp1.a[1][i] = 1;
	tmp1 = tmp1 * pow ( tmp , k - 1 );
	//for ( i = 1 ; i <= n ; i++ ) cout << tmp1.a[1][i] << " ";
	//cout << endl;
	for ( i = 1 ; i <= n ; i++ ) ans = (ans + tmp1.a[1][i]) % mod;
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}