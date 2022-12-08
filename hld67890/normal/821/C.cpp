#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

const int NN = 310000;
int n;
priority_queue < int , vector <int> , greater <int> > q;
char z[100];
int s[NN] , tops , last;
int ans;
void work () {
	int i , f , x;
	scanf ( "%d" , &n );
	f = 0;
	for ( i = 1 ; i <= n * 2 ; i++ ) {
		scanf ( "%s" , z + 1 );
		if ( z[1] == 'a' ) {
			scanf ( "%d" , &x );
			s[++tops] = x;
			q.push ( x );
		}
		else {
			if ( s[tops] != q.top () && tops > last ) {
				ans++;
				last = tops;
			}
			tops--;
			if ( tops < last ) last = tops;
			q.pop ();
		}
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}