#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

//long long
const long long mod = 998244353;
const long long root = 3;
const long long maxn = 102;
struct matrix {
	long long n , m;
	long long a[maxn][maxn];
} t , tmp;
long long n , m , k;
map < long long , long long > ma;
long long gx , gy;
long long ans;
matrix operator * ( matrix x1 , matrix x2 ) {
	matrix y;
	long long i , j , l;
	y.n = x1.n; y.m = x2.m;
	for ( i = 1 ; i <= y.n ; i++ ) for ( j = 1 ; j <= y.m ; j++ ) y.a[i][j] = 0;
	for ( i = 1 ; i <= x1.n ; i++ )
		for ( j = 1 ; j <= x1.m ; j++ )
			for ( l = 1 ; l <= x2.m ; l++ )
				y.a[i][l] = (y.a[i][l] + x1.a[i][j] * x2.a[j][l]) % (mod-1);
	return y;
}
long long pow ( long long f , long long x ) {
	long long s = 1;
	while ( x ) {
		if ( x % 2 ) s = ( s * f ) % mod;
		f = ( f * f ) % mod; x = x / 2;
	}
	return s;
}
long long inv ( long long x ) {
	return pow ( x , mod - 2 );
}
matrix pow ( matrix f , long long x ) {
	matrix s;
	long long i , j;
	s.n = s.m = f.n;
	for ( i = 1 ; i <= s.n ; i++ )
		for ( j = 1 ; j <= s.m ; j++ )
			s.a[i][j] = 0;
	for ( i = 1 ; i <= s.n ; i++ ) s.a[i][i] = 1;
	while ( x ) {
		if ( x % 2 ) {
			s = s * f;
		}
		f = f * f; x = x / 2;
	}
	return s;
}
long long getlog ( long long x ) {
	long long i , f = pow ( root , 32000ll ) , s , ret;
	s = 1;
	for ( i = 0 ; i <= 32000 ; i++ ) {
		ma[s] = i;
		s = ( s * f ) % mod;
	}
	s = 1; f = inv ( root );
	ret = 0;
	for ( i = 0 ; i <= 32000 ; i++ ) {
		if ( ma.find ( (x*s) % mod ) != ma.end () ) {
			ret = ma[(x*s)%mod] * 32000 + i;
			break;
		}
		s = ( s * f ) % mod;
	}
	if ( ret > mod - 1 ) ret -= mod - 1;
	return ret;
}
long long exgcd ( long long a , long long b ) {
	if ( b == 0 ) {
		gx = 1; gy = 0;
		return a;
	}
	long long ret , xx , yy;
	if ( a < b ) {
		ret = exgcd ( b , a );
		swap ( gx , gy );
		return ret;
	}
	ret = exgcd ( b , a % b );
	xx = gy;
	yy = gx - (a/b)*gy;
	gx = xx; gy = yy;
	return ret;
}
long long getans ( long long a , long long r ) {
	long long gcd = exgcd ( a , mod - 1 );
	while ( gx < 0 ) gx += mod - 1;
	if ( r % gcd == 0 ) return (gx * r / gcd) % (mod-1);
	else return -1;
}
void work () {
	long long i;
	scanf ( "%I64d" , &k );
	t.n = t.m = k;
	for ( i = 1 ; i <= k ; i++ ) {
		scanf ( "%I64d" , &t.a[k-i+1][k] );
	}
	for ( i = 1 ; i < k ; i++ ) {
		t.a[i+1][i] = 1;
	}
	scanf ( "%I64d%I64d" , &n , &m );
	tmp = pow ( t , n - k );
	if ( tmp.a[k][k] == 0 ) {
		if ( tmp.a[k][k] == getlog ( m ) ) {
			printf ( "1\n" );
		}
		else printf ( "-1\n" );
		return ;
	}
	ans = getans ( tmp.a[k][k] , getlog ( m ) );
	if ( ans == -1 ) printf ( "-1\n" );
	else printf ( "%I64d\n" , pow ( root , ans ) );
}
int main () {
	work ();
	return 0;
}