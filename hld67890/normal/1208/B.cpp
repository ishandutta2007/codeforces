#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int n;
int a[12000];
map < int , int > m , mm;
int cnt , cntt;
int ans;
void work () {
	int i , j;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		mm[a[i]]++;
		if ( mm[a[i]] == 2 ) cntt++;
	}
	if ( cntt == 0 ) {
		printf ( "0\n" );
		return ;
	}
	ans = n - 1;
	for ( i = 1 ; i <= n ; i++ ) {
		cnt = cntt; 
		m = mm;
		for ( j = i ; j <= n ; j++ ) {
			m[a[j]]--;
			if ( m[a[j]] == 1 ) cnt--;
			//if ( cnt == 0 ) printf ( "%d %d\n" , i , j );
			if ( cnt == 0 ) break;
		}
		if ( j != n + 1 ) ans = min ( ans , j - i + 1 );
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}