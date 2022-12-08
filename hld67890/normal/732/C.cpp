#include <stdio.h>
#include <algorithm>

using namespace std;

long long a , b , c;
long long ans , maxx;
void work () {
	scanf ( "%I64d%I64d%I64d" , &a , &b , &c );
	maxx = max ( a , max ( b , c ) );
	if ( a == maxx ) {
		if ( b < a - 1 ) ans += (a-1)-b;
		if ( c < a - 1 ) ans += (a-1)-c;
	}
	else {
		if ( b == maxx ) {
			if ( a < b - 1 ) ans += (b-1)-a;
			if ( c < b - 1 ) ans += (b-1)-c;
		}
		else {
			if ( b < c - 1 ) ans += (c-1)-b;
			if ( a < c - 1 ) ans += (c-1)-a;
		}
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}