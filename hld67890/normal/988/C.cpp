#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 220000;
int k;
int n[maxn];
int a[maxn] , s;
map < int , pair<int,int> > m;
void work () {
	int i , j;
	pair<int,int> tmp;
	scanf ( "%d" , &k );
	for ( i = 1 ; i <= k ; i++ ) {
		scanf ( "%d" , &n[i] );
		s = 0;
		for ( j = 1 ; j <= n[i] ; j++ ) {
			scanf ( "%d" , &a[j] );
			s += a[j];
		}
		for ( j = 1 ; j <= n[i] ; j++ ) {
			tmp.first = i; tmp.second = j;
			if ( m.find ( s - a[j] ) != m.end () ) {
				if ( m[s-a[j]].first != i ) {
					printf ( "YES\n" );
					printf ( "%d %d\n" , i , j );
					printf ( "%d %d\n" , m[s-a[j]].first , m[s-a[j]].second );
					return ;
				}
			}
			else {
				m[s-a[j]] = tmp;
			}
		}
	}
	printf ( "NO\n" );
}
int main () {
	work ();
	return 0;
}