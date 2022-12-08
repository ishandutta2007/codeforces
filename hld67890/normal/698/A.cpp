#include <iostream>
#include <stdio.h>

using namespace std;

int n;
int a[1120];
void work () {
	int i , last , ans;
	scanf ( "%d" , &n );
	last = ans = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		if ( a[i] == 0 ) {
			ans++;
			last = 0;
			continue;
		}
		if ( last == 0 ) {
			if ( a[i] == 3 ) continue;
			last = a[i];
		}
		else {
			if ( a[i] == 3 ) last = 3 - last;
			else {
				if ( last + a[i] == 3 ) last = a[i];
				else {
					last = 0;
					ans++;
				}
			}
		}
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}