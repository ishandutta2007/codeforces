#include <stdio.h>

using namespace std;

int n , q;
int a[1200000];
int s[4100000];
void buildtree ( int id , int l , int r ) {
	if ( l == r ) {
		s[id] = a[l];
		return ;
	}
	int mid = (l+r)/2;
	buildtree ( id * 2 , l , mid );
	buildtree ( id * 2 + 1 , mid + 1 , r );
	s[id] = s[id*2] + s[id*2+1];
}
void change ( int id , int l , int r , int x ) {
	s[id]++;
	if ( l == r ) {
		return ;
	}
	int mid = (l+r)/2;
	if ( x <= mid ) change ( id * 2 , l , mid , x );
	else change ( id * 2 + 1 , mid + 1 , r , x );
}
void del ( int id , int l , int r , int x ) {
	s[id]--;
	if ( l == r ) {
		return ;
	}
	int mid = (l+r)/2;
	if ( s[id*2] >= x ) del ( id * 2 , l , mid , x );
	else del ( id * 2 + 1 , mid + 1 , r , x - s[id*2] );
}
int output ( int id , int l , int r ) {
	if ( l == r ) return l;
	int mid = (l+r)/2;
	if ( s[id*2] ) return output ( id * 2 , l , mid );
	else return output ( id * 2 + 1 , mid + 1 , r );
}
void work () {
	int i , x;
	scanf ( "%d%d" , &n , &q );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &x );
		a[x]++;
	}
	buildtree ( 1 , 1 , n );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%d" , &x );
		if ( x > 0 ) change ( 1 , 1 , n , x );
		else {
			x = -x;
			del ( 1 , 1 , n , x );
		}
	}
	if ( s[1] == 0 ) printf ( "0\n" );
	else printf ( "%d\n" , output ( 1 , 1 , n ) );
}
int main () {
	work ();
	return 0;
}