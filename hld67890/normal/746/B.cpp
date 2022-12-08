#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 2200;
int n;
char z[maxn] , s[maxn];
void work () {
	int i , l , r;
	scanf ( "%d" , &n );
	scanf ( "%s" , z + 1 );
	if ( n == 1 ) {
		printf ( "%s\n" , z + 1 );
		return ;
	}
	l = n / 2; r = n / 2 + 1; i = 1;
	if ( n % 2 == 1 ) s[l+1] = z[i++], r++;
	while ( 1 ) {
		s[l--] = z[i++];
		s[r++] = z[i++];
		if ( r == n + 1 ) break;
	}
	printf ( "%s\n" , s + 1 );
}
int main () {
	work ();
}