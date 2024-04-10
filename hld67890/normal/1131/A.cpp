#include <stdio.h>
#include <algorithm>

using namespace std;

void work () {
	int a , b , c , d;
	scanf ( "%d%d%d%d" , &a , &b , &c , &d );
	printf ( "%d\n" , a + b + b + c + d + d + a - c - 1 + 5 );
}
int main () {
	work ();
	return 0;
}