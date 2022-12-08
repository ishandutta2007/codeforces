#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[2200000] , fi[2200000] , se[2200000];
int ans;
void merge ( int i , int j ) {
	if ( fi[j] > se[i] ) se[i] = fi[j];
	if ( se[i] > fi[i] ) swap ( fi[i] , se[i] );
	if ( se[j] > se[i] ) se[i] = se[j];
	if ( se[i] > fi[i] ) swap ( fi[i] , se[i] );
}
void solve ( int l , int r , int k ) {
	//if ( r <= 16 ) printf ( "%d %d %d\n" , l , r , k );
	if ( l == r ) return ;
	solve ( l , (l|(1<<k)) - 1 , k - 1 );
	solve ( l | (1<<k) , r , k - 1 );
	for ( int i = l ; i < (l|(1<<k)) ; i++ ) {
		merge ( i , i | (1<<k) );
	}
}
void work () {
	int i , j , w;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		se[a[i]] = fi[a[i]];
		fi[a[i]] = i;
	}
	solve ( 0 , 2097151 , 20 );
	//printf ( "%d\n" , se[8] );
	for ( i = 1 ; i <= n - 2 ; i++ ) {
		w = 0;
		for ( j = 20 ; j >= 0 ; j-- ) {
			if ( !(a[i]&(1<<j)) ) {
				if ( se[w|(1<<j)] > i ) {
					w |= (1<<j);
				}
				//printf ( "%d %d\n" , j , w );
			}
		}
		ans = max ( ans , w | a[i] );
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}