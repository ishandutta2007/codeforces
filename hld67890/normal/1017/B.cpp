#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 120000;
long long n;
char s1[maxn] , s2[maxn];
long long a , b , c , d;
void work () {
	long long i;
	scanf ( "%I64d" , &n );
	scanf ( "%s" , s1 + 1 );
	scanf ( "%s" , s2 + 1 );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( s1[i] == '0' && s2[i] == '0' ) a++;
		if ( s1[i] == '0' && s2[i] == '1' ) b++;
		if ( s1[i] == '1' && s2[i] == '0' ) c++;
		if ( s1[i] == '1' && s2[i] == '1' ) d++;
	}
	printf ( "%I64d\n" , a * c + a * d + b * c );
}
int main () {
	work ();
	return 0;
}