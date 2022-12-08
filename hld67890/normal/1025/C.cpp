#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 120000;
int n;
int pre[maxn] , suf[maxn];
char z[maxn];
int ans;
void work () {
	int i;
	scanf ( "%s" , z + 1 );
	n = strlen ( z + 1 );
	pre[1] = 1;
	ans = 1;
	for ( i = 2 ; i <= n ; i++ ) {
		if ( z[i] != z[i-1] ) pre[i] = pre[i-1] + 1;
		else pre[i] = 1;
		ans = max ( ans , pre[i] );
	}
	suf[n] = 1;
	for ( i = n - 1 ; i >= 1 ; i-- ) {
		if ( z[i] != z[i+1] ) suf[i] = suf[i+1] + 1;
		else suf[i] = 1;
	}
	if ( z[1] != z[n] ) {
		ans = max ( ans , 1 + min(n-1,pre[n]) );
		ans = max ( ans , 1 + min(n-1,suf[1]) );
	}
	for ( i = 2 ; i <= n - 1 ; i++ ) {
		if ( z[1] != z[n] ) {
			ans = max ( ans , min(i,suf[1]) + min(n-i,pre[n]) );
		}
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}