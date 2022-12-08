#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
long long m , b;
long long ans;
long long linsum ( long long x ) {
	return x*(x+1)/2;
}
void work () {
	long long i , x , y;
	scanf ( "%I64d%I64d" , &m , &b );
	for ( i = b ; i >= 0 ; i-- ) {
		y = i;
		x = (b-y)*m;
		//printf ( "%I64d %I64d\n" , x , y );
		ans = max ( ans , linsum ( x ) * (y+1) + linsum ( y ) * (x+1) );
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}