#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[120000];
int next[1200][10][1200];
int last[10];
int need[10];
int p[10];
int ans;
bool check ( int x , int s ) {
	int i , t , now;
	if ( x == 0 && s == 0 ) return true;
	//printf ( "%d %d\n" , x , s );
	for ( i = 1 ; i <= 8 ; i++ ) {
		need[i] = x + (s % 2);
		s = s / 2;
	}
	for ( i = 1 ; i <= 8 ; i++ ) p[i] = i;
	do {
		now = 1;
		if ( p[1] == a[1] ) need[a[1]]--;
		for ( i = 1 ; i <= 8 ; i++ ) now = next[now][p[i]][need[p[i]]];
		if ( now != 0 ) return true;
		if ( p[1] == a[1] ) need[a[1]]++;
	} while ( next_permutation ( p + 1 , p + 1 + 8 ) );
	return false;
}
void solve ( int x ) {
	int i , s , t;
	ans = x * 8;
	for ( i = 0 ; i <= 255 ; i++ ) {
		if ( check ( x , i ) == true ) {
			s = 0; t = i;
			while ( t ) {
				if ( t % 2 ) s++;
				t >>= 1;
			}
			ans = max ( ans , x * 8 + s );
		}
	}
	printf ( "%d\n" , ans );
}
void work () {
	int i , j , k , l , r , mid;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	for ( i = n ; i >= 1 ; i-- ) {
		for ( j = 1 ; j <= 8 ; j++ ) next[i][j][1] = last[j];
		last[a[i]] = i;
	}
	for ( i = 1 ; i <= n ; i++ ) for ( j = 1 ; j <= 8 ; j++ ) for ( k = 2 ; k <= n ; k++ ) {
		next[i][j][k] = next[next[i][j][k-1]][j][1];
		if ( next[i][j][k] == 0 ) break;
	}
	for ( i = 1 ; i <= n ; i++ ) for ( j = 1 ; j <= 8 ; j++ ) next[i][j][0] = i;
	l = 0; r = n;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		if ( check ( mid , 0 ) == true ) l = mid;
		else r = mid;
	}
	if ( check ( r , 0 ) == true ) solve ( r );
	else solve ( l );
}
int main () {
	work ();
	return 0;
}