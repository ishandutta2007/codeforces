#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 120000;
int n;
int a[maxn] , pos[maxn];
int ans;
void work () {
	int i , j , k , tmp;
	scanf ( "%d" , &n );
	ans = 200000;
	for ( i = 1 ; i <= n ; i++ ) {
		ans = min ( ans , i + (n/i) + ((n%i)==0?0:1) );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( ans == (i + (n/i) + ((n%i)==0?0:1)) ) {
			k = 0;
			pos[0] = 1;
			for ( j = 1 ; j <= i ; j++ ) {
				tmp = j * ((n/i) + ((n%i)==0?0:1));
				if ( tmp > n ) tmp = n;
				while ( k < n ) {
					if ( pos[tmp] ) {
						break;
					}
					k++;
					//printf ( "%d %d\n" , k , tmp );
					a[k] = tmp;
					pos[tmp] = 1;
					tmp--;
				}
			}
			break;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		printf ( "%d%c" , a[i] , i==n?'\n':' ' );
	}
}
int main () {
	work ();
	return 0;
}