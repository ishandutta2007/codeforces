#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long NN = 220000;
const long long mod = 1000000007;
long long n;
long long fact[NN] , rev[NN];
long long a[NN];
long long ans;
long long pow ( long long f , long long x ) {
	long long s = 1;
	while ( x ) {
		if ( x % 2 == 1 ) s = (s*f) % mod;
		f = (f*f) % mod; x >>= 1;
	}
	return s;
}
void predo () {
	long long i;
	fact[0] = 1;
	rev[0] = 1;
	for ( i = 1 ; i <= 200000 ; i++ ) {
		fact[i] = (fact[i-1]*i) % mod;
	}
	rev[200000] = pow ( fact[200000] , mod - 2 );
	for ( i = 200000 - 1 ; i >= 1 ; i-- ) {
		rev[i] = (rev[i+1] * (i+1)) % mod;
	}
}
long long C ( long long a , long long b ) {
	if ( b < 0 ) return 0;
	//printf ( "%Id\n" ,b );
	return (fact[a]*((rev[b]*rev[a-b])%mod)) % mod;
}
void work () {
	long long i , co , x , y;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
		x = n - 1; y = n - 1 - i + 1;
		if ( n % 2 == 0 ) {
			co = C(x/2,(y)/2);
			if ( x % 4 == 3 && y % 2 == 0 ) co = (mod - co);
		}
		else {
			if ( n % 4 == 1 ) {
				if ( i % 2 == 0 ) co = 0;
				else co = C(x/2,(i-1)/2);
			}
			else {
				if ( i % 2 == 0 ) {
					co = (2*C((n-3)/2,(i-2)/2)) % mod;
				}
				else {
					co = (  C((n-3)/2,i/2) - C((n-3)/2,i/2-1) + mod  ) %mod;
					//printf ( "      %I64d %I64d %I64d\n" ,C((n-3)/2,i/2), C((n-3)/2 , i/2-1) , co  );
				}
			}
		}
		//printf ( "%I64d\n" , co );
		ans = (ans + a[i] * co) % mod;
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	predo ();
	work ();
	return 0;
}