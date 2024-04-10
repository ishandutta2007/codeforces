#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const int maxn = 220000;
int n , m;
int a[maxn];
void work () {
	int i , left , ans;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" ,&a[i] );
	}
	left = m;
	for ( i = 1 ; i <= n ; i++ ) {
		ans = a[i] / m;
		if ( left > (a[i] % m) ) {
			left -= a[i] % m;
		}
		else {
			left = left + m - (a[i]%m);
			ans++;
		}
		printf ( "%d%c" , ans , i==n?'\n':' ' );
	}
}
int main () {
	work ();
	return 0;
}