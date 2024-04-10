#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 120;
int n;
int a[maxn];
int b[maxn];
void work () {
	int i , k;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	sort ( a + 1 , a + 1 + n );
	k = 0;
	for ( i = n ; i >= 1 ; i -= 2 ) {
		b[++k] = a[i];
	}
	k = n;
	for ( i = n - 1 ; i >= 1 ; i -= 2 ) {
		b[k--] = a[i];
	}
	for ( i = 1 ; i <= n ; i++ ) printf ( "%d%c" , b[i] , i==n?'\n':' ' );
}
int main () {
	work ();
	return 0;
}