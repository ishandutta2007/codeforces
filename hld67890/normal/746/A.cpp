#include <stdio.h>
#include <algorithm>

using namespace std;

int ans , a , b , c;
void work () {
	scanf ( "%d%d%d" , &a , &b , &c );
	while ( a >= 1 && b >= 2 && c >= 4 ) {
		ans += 7;
		a--; b -= 2; c -= 4;
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
}