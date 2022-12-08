#include <stdio.h>
#include <algorithm>

using namespace std;

const int NN = 120000;
int n;
int a[NN];
int b[NN] , cnt[NN] , tot;
void work () {
	int i;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	sort ( a + 1 , a + 1 + n );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( i == 1 || a[i] != a[i-1] ) tot++;
		b[tot] = a[i]; cnt[tot]++;
	}
	if ( cnt[1] >= 3 ) {
		printf ( "%I64d\n" , ((long long)cnt[1])*(cnt[1]-1)*(cnt[1]-2)/6 );
	}
	else {
		if ( cnt[1] == 2 ) {
			printf ( "%d\n" , cnt[2] );
		}
		else {
			if ( cnt[2] == 1 ) {
				printf ( "%d\n" , cnt[3] );
			}
			else {
				printf ( "%I64d\n" , ((long long)cnt[2])*(cnt[2]-1)/2 );
			}
		}
	}
}
int main () {
	work ();
	return 0;
}