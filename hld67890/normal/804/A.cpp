#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
void work () {
	scanf ( "%d" , &n );
	printf ( "%d\n" , (n-1) / 2 );
}
int main () {
	work ();
	return 0;
}