#include <stdio.h>
#include <algorithm>
#define $ if(0)

using namespace std;

//long long
long long n;
long long c[1200000];
void work () {
	long long i;
	long long w , tmp , k;
	char z[10];
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s%I64d" , z , &w );
		tmp = 0; k = 1;
		while ( w ) {
			if ( w % 2 ) tmp += k;
			w = w / 10; k <<= 1;
		}
		$ printf ( "%d\n" , tmp );
		if ( z[0] == '+' ) c[tmp]++;
		if ( z[0] == '-' ) c[tmp]--;
		if ( z[0] == '?' ) printf ( "%I64d\n" , c[tmp] );
	}
}
int main () {
	work ();
	return 0;
}