#include <stdio.h>
#include <algorithm>

using namespace std;

int n , k;
void work () {
	int i = 0;
	scanf ( "%d%d" , &n , &k );
	while ( (i+1) * 5 + k <= 240 && i < n ) {
		k += (i+1)*5;
		i++;
	}
	printf ( "%d\n" , i );
}
int main () {
	work ();
	return 0;
}