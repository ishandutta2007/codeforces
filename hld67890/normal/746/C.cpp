#include <stdio.h>
#include <algorithm>

using namespace std;

int s , x1 , x2;
int t1 , t2;
int p , d;
int f[1200];
int ans , sum;
void work () {
	int i;
	scanf ( "%d%d%d" , &s , &x1 , &x2 );
	scanf ( "%d%d" , &t1 , &t2 );
	scanf ( "%d%d" , &p , &d );
	ans = abs(x2-x1) * t2;
	sum = 0;
	while ( 1 ) {
		f[p] = 1;
		if ( p == x2 ) {
			if ( f[x1] == 1 ) {
				ans = min ( ans , sum * t1 );
				break;
			}
		}
		p += d;
		if ( p == s ) d = -d;
		if ( p == 0 ) d = -d;
		sum++;
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
}