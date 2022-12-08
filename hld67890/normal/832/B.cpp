#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int NN = 120000;
int q;
int f[30];
int ls , lz;
char s[NN];
char z[NN];
void work () {
	int i , j , k , t , flag;
	scanf ( "%s" , z + 1 );
	lz = strlen ( z + 1 );
	for ( i = 1 ; i <= lz ; i++ ) f[z[i]-'a'] = 1;
	scanf ( "%s" , s + 1 );
	ls = strlen ( s + 1 );
	scanf ( "%d" , &q );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%s" , z + 1 );
		lz = strlen ( z + 1 );
		flag = 0;
		for ( j = 1 ; j <= lz ; j++ ) {
			if ( s[j] != z[j] ) {
				if ( s[j] == '?' && f[z[j]-'a'] == 1 ) continue;
				flag = 1;
				break;
			}
		}
		if ( flag == 0 ) {
			if ( lz == ls ) {
				printf ( "YES\n" );
			}
			else {
				if ( lz + 1 == ls && s[ls] == '*' ) {
					printf ( "YES\n" );
				}
				else {
					printf ( "NO\n" );
				}
			}
		}
		else {
			if ( s[j] == '*' ) {
				for ( k = lz , t = ls ; k >= j ; k-- , t-- ) {
					if ( s[t] != z[k] ) {
						if ( s[t] == '?' && f[z[k]-'a'] == 1 ) continue;
						break;
					}
				}
				if ( s[t] == '*' ) {
					flag = 1;
					for ( j ; j <= k ; j++ ) {
						if ( f[z[j]-'a'] == 1 ) {
							flag = 0;
							break;
						}
					}
					if ( flag == 1 ) printf ( "YES\n" );
					else printf ( "NO\n" );
				}
				else {
					printf ( "NO\n" );
				}
			}
			else {
				printf ( "NO\n" );
			}
		}
	}
}
int main () {
	work ();
	return 0;
}