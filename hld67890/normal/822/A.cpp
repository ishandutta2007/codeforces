#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m;
int ans;
void work () {
	int i;
	scanf ( "%d%d" , &n , &m );
	if ( n > m ) swap ( n , m );
	ans = 1;
	for ( i = 1 ; i <= n ; i++ ) ans = ans * i;
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}