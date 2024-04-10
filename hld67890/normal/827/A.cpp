#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int NN = 1200000;
int n;
char z[NN];
int l[NN] , r[NN] , len[NN];
int pos[NN] , from[NN];
char ans[NN];
void work () {
	int i , j , last , k , x , left , now;
	int maxx;
	scanf ( "%d" , &n );
	last = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s%d" , z + last + 1 , &k );
		l[i] = last + 1;
		r[i] = strlen ( z + l[i] );
		len[i] = r[i];
		last = last + r[i];
		for ( j = 1 ; j <= k ; j++ ) {
			scanf ( "%d" , &x );
			maxx = max ( maxx , x + len[i] - 1 );
			if ( len[pos[x]] < len[i] ) {
				pos[x] = i;
			}
		}
	}
	left = 0; now = 0; k = 0;
	for ( i = 1 ; i <= maxx ; i++ ) {
		if ( left < len[pos[i]] ) {
			now = pos[i];
			left = len[pos[i]];
			k = 1;
		}
		//printf ( "%d %d\n" , left , pos[i] );
		if ( left ) {
			ans[i] = z[l[now]+k-1];
			k++;
			left--;
		}
		else ans[i] = 'a';
	}
	printf ( "%s\n" , ans + 1 );
}
int main () {
	work ();
	//system ( "pause" );
	return 0;
}