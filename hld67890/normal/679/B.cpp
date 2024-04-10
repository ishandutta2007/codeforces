#include <iostream>
#include <stdio.h>

using namespace std;

long long m;
long long ans , t;
void sol ( long long x , long long w , long long use ) {
	if ( x <= 7 ) {
		if ( w + x > ans ) {
			ans = w + x;
			t = use + x;
		}
		else if ( w + x == ans ) t = max ( t , use );
		return ;
	}
	long long a;
	a = 1;
	while ( a*a*a <= x ) a++;
	a--;
	sol ( x - a*a*a , w + 1 , use + a*a*a );
	if ( a >= 2 ) sol ( a*a*a - 1 - (a-1)*(a-1)*(a-1) , w + 1 , use + (a-1)*(a-1)*(a-1) );
}
void work () {
	scanf ( "%I64d" , &m );
	sol ( m , 0 , 0 );
	printf ( "%I64d %I64d\n" , ans , t );
}
int main () {
	work ();
	return 0;
}