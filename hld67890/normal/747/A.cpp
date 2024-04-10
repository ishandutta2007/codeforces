#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
void work () {
	int t;
	scanf ( "%d" , &n );
	t = sqrt ( n );
	while ( n % t != 0 ) t--;
	printf ( "%d %d\n" , t , n / t );
}
int main () {
	work ();
	return 0;
}