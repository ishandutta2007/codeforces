#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int now;
char z[50];
void work () {
	int i , x , f;
	scanf ( "%d" , &n );
	now = 0;
	f = 1;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d%s" , &x , z + 1 );
		if ( now == 0 ) {
			if ( z[1] != 'S' ) {
				f = 0;
				break;
			}
			now += x;
			if ( now > 20000 ) {
				f = 0;
				break;
			}
		}
		else {
			if ( now == 20000 ) {
				if ( z[1] != 'N' ) {
					f = 0;
					break;
				}
				now -= x;
				if ( now < 0 ) {
					f = 0;
					break;
				}
			}
			else {
				if ( z[1] == 'N' ) {
					now -= x;
					if ( now < 0 ) {
						f = 0;
						break;
					}
				}
				else {
					if ( z[1] == 'S' ) {
						now += x;
						if ( now > 20000 ) {
							f = 0;
							break;
						}
					}
				}
			}
		}
	}
	if ( now != 0 ) f = 0;
	if ( f == 1 ) printf ( "YES\n" );
	else printf ( "NO\n" );
}
int main () {
	work ();
	return 0;
}