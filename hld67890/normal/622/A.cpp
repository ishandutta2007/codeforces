#include <stdio.h>
#include <algorithm>

using namespace std;

long long n;
void work () {
	long long i;
	scanf ( "%I64d" , &n );
	i = 1;
	while ( i < n ) {
		n -= i;
		i++;
	}
	printf ( "%I64d\n" , n );
}
int main () {
	work ();
	return 0;
}