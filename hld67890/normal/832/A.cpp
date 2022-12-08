#include <stdio.h>
#include <algorithm>

using namespace std;

long long n , k;
void work () {
	scanf ( "%I64d%I64d" , &n , &k );
	if ( (n/k) % 2 == 1 ) printf ( "YES\n" );
	else printf ( "NO\n" );
}
int main () {
	work ();
	return 0;
}