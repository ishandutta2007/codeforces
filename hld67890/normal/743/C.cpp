#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
void work () {
	scanf ( "%d" , &n );
	if ( n == 1 ) {
		printf ( "-1\n" );
		return ;
	}
	printf ( "%d %d %d\n" , n , n + 1 , n * (n+1) );
}
int main () {
	work ();
	return 0;
}