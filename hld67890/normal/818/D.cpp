#include <stdio.h>
#include <algorithm>

using namespace std;

const int NN = 1200000;
int n , a;
int c[NN] , need[NN] , cnt[NN];
int taboo[NN];
void work () {
	int i;
	scanf ( "%d%d" , &n , &a );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &c[i] );
		need[i] = need[i-1] + (c[i]==a?1:0);
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( c[i] != a ) {
			cnt[c[i]]++;
			if ( cnt[c[i]] - 1 < need[i] ) {
				taboo[c[i]] = 1;
			}
		}
	}
	taboo[a] = 1;
	for ( i = 1 ; i <= 1000000 ; i++ ) {
		if ( cnt[i] < need[n] ) taboo[i] = 1;
		if ( taboo[i] == 0 ) {
			printf ( "%d\n" , i );
			return ;
		}
	}
	printf ( "-1\n" );
}
int main () {
	work ();
	return 0;
}