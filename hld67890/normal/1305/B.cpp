#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;

int n;
char z[120000];
stack < pair<char,int> > q;
int ans[120000] , cnt;
void work () {
	int i , j;
	scanf ( "%s" , z + 1 );
	n = strlen ( z + 1 );
	i = 1; j = n;
	while ( i < j ) {
		while ( i < j && z[i] == ')' ) i++;
		while ( i < j && z[j] == '(' ) j--;
		if ( z[i] == '(' && z[j] == ')' ) {
			cnt += 2;
			ans[i] = ans[j] = 1;
			i++; j--;
		}
	}
	if ( cnt == 0 ) {
		printf ( "0\n" );
		return ;
	}
	printf ( "%d\n" , 1 );
	printf ( "%d\n" , cnt );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( ans[i] == 1 ) printf ( "%d " , i );
	}
}
int main () {
	work ();
	return 0;
}