#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	int siz , i;
} s[600];
int n;
int u1[600] , u2[600] , cnt;
int v[600] , cv;
bool cmp ( node x1 , node x2 ) {
	return x1.siz < x2.siz;
}
int ask ( int i , int lim ) {
	int j , ret;
	if ( lim == 0 ) return 0;
	printf ( "1\n1\n" );
	printf ( "%d\n" , lim );
	for ( j = 1 ; j <= lim ; j++ ) {
		printf ( "%d%c" , v[j] , j==lim?'\n':' ' );
	}
	printf ( "%d\n" , i );
	fflush(stdout);
	scanf ( "%d" , &ret );
	return ret;
}
void work () {
	int i , j , k , l , r , mid;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		printf ( "1\n1\n%d\n" , n - 1 );
		for ( j = 2 ; j <= n ; j++ ) {
			printf ( "%d%c" , j , j==n?'\n':' ' );
		}
		printf ( "%d\n" , i );
		fflush(stdout);
		scanf ( "%d" , &s[i].siz );
		s[i].i = i;
	}
	s[1].siz = n;
	sort ( s + 1 , s + 1 + n , cmp );
	for ( i = 1 ; i <= n ; i++ ) {
		//printf ( "##ask k:\n" );
		if ( s[i].siz == 1 ) {
			v[++cv] = s[i].i;
			continue;
		}
		k = ask ( s[i].i , cv );
		for ( j = 1 ; j <= k ; j++ ) {
			l = 0; r = cv;
			while ( l < r - 1 ) {
				mid = (l+r)/2;
				//printf ( "ask %d %d\n" , j , mid );
				if ( ask ( s[i].i , mid ) >= 1 ) r = mid;
				else l = mid;
			}
			cnt++;
			u1[cnt] = s[i].i; u2[cnt] = v[r];
			for ( l = r ; l < cv ; l++ ) {
				v[l] = v[l+1];
			}
			cv--;
		}
		v[++cv] = s[i].i;
		//for ( j = 1 ; j <= cv ; j++ ) {
		//	printf ( "%d " , v[j] );
		//}
		//printf ( "\n" );
	}
	printf ( "ANSWER\n" );
	for ( i = 1 ; i < n ; i++ ) {
		printf ( "%d %d\n" , u1[i] , u2[i] );
	}
	fflush(stdout);
}
int main () {
	work ();
	return 0;
}