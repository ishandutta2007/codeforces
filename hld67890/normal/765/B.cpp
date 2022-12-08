#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 510;
int n;
char z[maxn];
int f[30];
int flag;
void work () {
	int i , j;
	scanf ( "%s" , z + 1 );
	n = strlen ( z + 1 );
	f[0] = 1; j = 1;
	flag = 1;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( f[z[i]-'a'+1] == 0 ) {
			if ( f[z[i]-'a'] == 0 ) flag = 0;
			f[z[i]-'a'+1] = 1;
		}
	}
	if ( flag == 0 ) printf ( "NO\n" );
	else printf ( "YES\n" );
}
int main () {
	work ();
	return 0;
}