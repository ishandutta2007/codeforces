#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int n , v[5000] , d[5000] , p[5000] , f[5000] , ans;
queue < int > q;
void work () {
	int i , j , k;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d%d%d" , &v[i] , &d[i] , &p[i] );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( f[i] == 0 ) {
			f[i] = 1;
			for ( j = i + 1 , k = v[i] ; j <= n && k > 0 ; j++ , k-- ) {
				p[j] -= k;
				if ( f[j] == -1 ) k++;
				if ( p[j] < 0 && f[j] != -1 ) q.push ( j ), f[j] = -1;
			}
			while ( q.size () != 0 ) {
				k = q.front ();
				q.pop ();
				for ( j = k + 1 ; j <= n ; j++ ) {
					p[j] -= d[k];
					if ( p[j] < 0 && f[j] != -1 ) f[j] = -1, q.push ( j );
				}
			}
		}
	}
	ans = 0;
	for ( i = 1 ; i <= n ; i++ ) ans += f[i]==1 ;
	printf ( "%d\n" , ans );
	for ( i = 1 ; i <= n ; i++ ) if ( f[i] == 1 ) printf ( "%d " , i );
}
int main () {
	work ();
	return 0;
}