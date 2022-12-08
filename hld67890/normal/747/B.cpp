#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int maxn = 260;
int n;
char z[maxn];
int f[20];
void work () {
	int i , t;
	scanf ( "%d" , &n );
	scanf ( "%s" , z + 1 );
	if ( n % 4 != 0 ) {
		printf ( "===\n" );
		return ;
	}
	t = n / 4;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( z[i] == 'A' ) f[1]++;
		if ( z[i] == 'G' ) f[2]++;
		if ( z[i] == 'C' ) f[3]++;
		if ( z[i] == 'T' ) f[4]++;
	}
	for ( i = 1 ; i <= 4 ; i++ ) {
		if ( f[i] > t ) {
			printf ( "===\n" );
			return ;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) 
		if ( f[1] < t && z[i] == '?' ) z[i] = 'A', f[1]++;
	for ( i = 1 ; i <= n ; i++ ) 
		if ( f[2] < t && z[i] == '?' ) z[i] = 'G', f[2]++;
	for ( i = 1 ; i <= n ; i++ ) 
		if ( f[3] < t && z[i] == '?' ) z[i] = 'C', f[3]++;
	for ( i = 1 ; i <= n ; i++ ) 
		if ( f[4] < t && z[i] == '?' ) z[i] = 'T', f[4]++;
	printf ( "%s\n" , z + 1 );
}
int main () {
	work ();
	return 0;
}