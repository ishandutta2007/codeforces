#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

long long a1 , b1 , a2 , b2 , l , r;
long long x , g;
long long gcd ( long long x , long long y ) {
	long long t;
	if ( x < y ) swap ( x , y );
	while ( y ) {
		t = x % y;
		x = y;
		y = t;
	}
	return x;
}
long long pow ( long long f , long long x , long long mod ) {
	long long s = 1;
	while ( x ) {
		if ( x % 2 ) s = (s*f) % mod;
		f = (f*f) % mod; x >>= 1;
	}
	return s;
}
long long phi ( long long x ) {
	long long i , ret = 1;
	for ( i = 2 ; i * i <= x ; i++ ) {
		if ( x % i == 0 ) {
			ret = ret * (i-1);
			x = x / i;
			while ( x % i == 0 ) {
				ret = ret * i;
				x = x / i;
			}
		}
	}
	if ( x > 1 ) {
		ret = ret * (x-1);
	}
	return ret;
}
long long inv ( long long x , long long mod ) {
	return pow ( x , phi ( mod ) - 1 , mod );
}
long long mul ( long long f , long long x , long long mod ) {
	long long s = 0;
	while ( x ) {
		if ( x % 2 ) s = (s+f) % mod;
		f = (f+f) % mod; x >>= 1;
	}
	return s;
}
void work () {
	long long mod , k;
	scanf ( "%I64d%I64d%I64d%I64d%I64d%I64d" , &a1 , &b1 , &a2 , &b2 , &l , &r );
	g = gcd ( a1 , a2 );
	if ( (max(b1,b2) - min(b1,b2)) % g != 0 ) {
		printf ( "0\n" );
		return ;
	}
	mod = a1*a2/g;
	x = ( b1 + mul ( mul ( (b2-b1)/g , inv ( a1/g , a2/g ) , a2/g ) , a1 , mod ) ) % mod;
	//x = inv(a1/g,a2/g)*((b2-b1)/g)%(a2/g)*a1+b1;
	if ( l < b1 ) l = b1;
	if ( l < b2 ) l = b2;
	if ( r < b1 || r < b2 ) {
		printf ( "0\n" );
		return ;
	}
	//printf ( "%I64d %I64d\n" , x , mod );
	if ( x >= l ) x -= ((x-l)/mod+1) * mod;
	printf ( "%I64d\n" , ((r-x)/mod) - ((l-1-x)/mod) );
}
int main () {
	work ();
	return 0;
}