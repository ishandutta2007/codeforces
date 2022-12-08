#include <stdio.h>
#include <algorithm>

using namespace std;

int a , b;
void work () {
	scanf ( "%d%d" , &a , &b );
	printf ( "%d %d\n" , a - 1 , b );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}