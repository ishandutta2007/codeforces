#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n , l;
char z[120000];
int a[30];
int check ( int x ) {
	int i , j , last = -1;
	for ( i = 1 ; i <= n ; i++ ) if ( z[i] <= 'a' + x - 1 ) last = i;
	if ( last == -1 ) return 0;
	for ( i = last + 1 ; i <= l - n + 1 ; i++ ) {
		//printf ( "%d\n" , last );
		if ( z[i] <= 'a' + x - 1 ) last = i;
		if ( i > last ) {
			//printf ( "%d %d %d\n" , i , last , l );
			for ( j = i + 1 ; j <= i + n - 1 && j <= l ; j++ ) {
				if ( z[j] <= 'a' + x - 1 ) last = j;
				//printf ( "%d\n" , j );
			}
			if ( i > last ) return 0;
		}
	}
	return 1;
}
int solve ( int x ) {
	int i , j , last = -1 , sum , lp;
	sum = 0;
	lp = -1;
	x--;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( z[i] <= 'a' + x - 1 ) last = i;
		if ( z[i] == 'a' + x ) lp = i;
	}
	if ( last == -1 ) last = lp, sum++;
	//printf ( "%d\n" , last );
	for ( i = last + 1 ; i <= l - n + 1 ; i++ ) {
		if ( z[i] <= 'a' + x - 1 ) last = i;
		if ( z[i] == 'a' + x ) lp = i;
		if ( i > last ) {
			for ( j = i + 1 ; j <= i + n - 1 && j <= l ; j++ ) {
				if ( z[j] <= 'a' + x - 1 ) last = j;
				if ( z[j] == 'a' + x ) lp = j;
			}
			if ( i > last ) {
				sum++;
				last = lp;
			}
		}
	}
	return sum;
}
void work () {
	int i , j , ans , ansi;
	scanf ( "%d" , &n );
	scanf ( "%s" , z + 1 );
	l = strlen ( z + 1 );
	for ( i = 1 ; i <= 26 ; i++ ) {
		if ( check ( i ) == 1 ) {
			//printf ( "%d\n" , i );
			ans = solve ( i );
			ansi = i;
			break;
		}
	}
	//printf ( "%d %d\n" , ans , ansi );
	for ( i = 1 ; i <= l ; i++ ) {
		a[z[i]-'a'+1]++;
	}
	for ( i = 1 ; i < ansi ; i++ )
		for ( j = 1 ; j <= a[i] ; j++ ) printf ( "%c" , 'a' + i - 1 );
	for ( i = 1 ; i <= ans ; i++ ) printf ( "%c" , 'a' + ansi - 1 );
	printf ( "\n" );
}
int main () {
	work ();
	return 0;
}