#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

//long long
const long long maxn = 320000;
long long n;
char z[maxn];
long long l[maxn] , r[maxn] , emp;
long long ans;
void work () {
	long long i , j , len , ll , rr , x;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s" , z + 1 );
		len = strlen ( z + 1 );
		ll = 0; rr = 0; x = 0;
		for ( j = 1 ; j <= len ; j++ ) {
			if ( z[j] == '(' ) x++;
			else x--;
			ll = min ( ll , x );
		}
		ll = -ll;
		x = 0;
		for ( j = len ; j >= 1 ; j-- ) {
			if ( z[j] == '(' ) x++;
			else x--;
			rr = max ( rr , x );
		}
		if ( ll == 0 && rr == 0 ) emp++;
		else {
			if ( ll == 0 ) l[rr]++;
			if ( rr == 0 ) r[ll]++;
		}
	}
	ans = emp * emp;
	for ( i = 1 ; i <= 300000 ; i++ ) ans += l[i] * r[i];
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}