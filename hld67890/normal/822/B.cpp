#include <stdio.h>
#include <algorithm>

using namespace std;

const int NN = 1200;
int n , m;
char a[NN] , b[NN];
int ans;
void work () {
	int i , j , tmp , tmpi;
	scanf ( "%d%d" , &n , &m );
	scanf ( "%s" , a + 1 );
	scanf ( "%s" , b + 1 );
	ans = 9999999;
	for ( i = 1 ; i <= m - n + 1 ; i++ ) {
		tmp = 0;
		for ( j = 1 ; j <= n ; j++ ) {
			if ( a[j] != b[i+j-1] ) tmp++;
		}
		if ( ans > tmp ) {
			ans = tmp;
			tmpi = i;
		}
	}
	printf ( "%d\n" , ans );
	for ( j = 1 ; j <= n ; j++ ) {
		if ( a[j] != b[tmpi+j-1] ) {
			ans--;
			printf ( "%d%c" , j , ans==0?'\n':' ' );
		}
	}
}
int main () {
	work ();
	return 0;
}