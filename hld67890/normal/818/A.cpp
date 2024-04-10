#include <stdio.h>
#include <algorithm>

using namespace std;

long long n , k;
void work () {
	long long x;
	scanf ( "%I64d%I64d" , &n , &k );
	x = n/2/(k+1);
	printf ( "%I64d %I64d %I64d\n" , x , x * k , n - x - x * k );
}
int main () {
	work ();
	return 0;
}