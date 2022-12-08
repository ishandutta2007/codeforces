#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int NN = 120000;
struct node {
	int l , r , a[5];
	node *ll , *rr;
} pool[NN*10*2*2] , *t[20][20];
int top;
int q;
int n;
char z[NN] , z1[NN];
int l1;
int ans;
int get1 ( int i , int j , int pos ) {
	while ( (pos+i) % i != (j+i) % i ) pos++;
	return (pos - j) / i + 1;
}
int get2 ( int i , int j , int pos ) {
	while ( (pos+i) % i != (j+i) % i ) pos--;
	return (pos-j) / i + 1;
}
void update ( node *id ) {
	id -> a[1] = id -> ll -> a[1] + id -> rr -> a[1];
	id -> a[2] = id -> ll -> a[2] + id -> rr -> a[2];
	id -> a[3] = id -> ll -> a[3] + id -> rr -> a[3];
	id -> a[4] = id -> ll -> a[4] + id -> rr -> a[4];
}
void buildtree ( node *id , int l , int r , int i , int j ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		if ( i*(l-1)+j > n ) return ;
		if ( z[i*(l-1)+j] == 'A' ) id -> a[1]++;
		if ( z[i*(l-1)+j] == 'G' ) id -> a[2]++;
		if ( z[i*(l-1)+j] == 'C' ) id -> a[3]++;
		if ( z[i*(l-1)+j] == 'T' ) id -> a[4]++;
		return ;
	}
	int mid = (l+r)/2;
	id -> ll = &pool[++top]; id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid , i , j ); buildtree ( id -> rr , mid + 1 , r , i , j );
	update ( id );
}
void change ( node *id , int l , char s ) {
	if ( id -> l == id -> r ) {
		id -> a[1] = id -> a[2] = id -> a[3] = id -> a[4] = 0;
		if ( s == 'A' ) id -> a[1]++;
		if ( s == 'G' ) id -> a[2]++;
		if ( s == 'C' ) id -> a[3]++;
		if ( s == 'T' ) id -> a[4]++;
		return ;
	}
	int mid = (id->l+id->r)/2;
	if ( l <= mid ) change ( id -> ll , l , s );
	else change ( id -> rr , l , s );
	update ( id );
}
int query ( node *id , int l , int r , char s ) {
	//printf ( "%d %d %d %d %d %d\n" , id -> l , id -> r , id -> a[1] , id -> a[2] , id -> a[3] , id -> a[4] );
	if ( id -> l == l && id -> r == r ) {
		if ( s == 'A' ) return id -> a[1];
		if ( s == 'G' ) return id -> a[2];
		if ( s == 'C' ) return id -> a[3];
		if ( s == 'T' ) return id -> a[4];
	}
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r , s );
	else {
		if ( l > mid ) return query ( id -> rr , l , r , s );
		else return query ( id -> ll , l , mid , s ) + query ( id -> rr , mid + 1 , r , s );
	}
}
void work () {
	int i , j , op , le , ri , ql , qr;
	scanf ( "%s" , z + 1 );
	n = strlen ( z + 1 );
	for ( i = 1 ; i <= 10 ; i++ ) {
		for ( j = 1 ; j <= i ; j++ ) {
			t[i][j] = &pool[++top];
			buildtree ( t[i][j] , 1 , n / i + 5 , i , j );
		}
	}
	scanf ( "%d" , &q );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%d%d" , &op , &le );
		if ( op == 1 ) {
			scanf ( "%s" , z1 + 1 );
			for ( j = 1 ; j <= 10 ; j++ ) {
				change ( t[j][(le-1)%j+1] , (le-1)/j+1 , z1[1] );
			}
		}
		else {
			scanf ( "%d%s" , &ri , z1 + 1 );
			l1 = strlen ( z1 + 1 );
			ans = 0;
			for ( j = 1 ; j <= l1 ; j++ ) {
				ql = get1 ( l1 , ( le + j - 1 - 1 ) % l1 + 1 , le ); qr = get2 ( l1 , ( le + j - 1 - 1 ) % l1 + 1 , ri );
				//printf ( "%d %d\n" , ql , qr );
				if ( ql <= qr ) {
					ans += query ( t[l1][( le + j - 1 - 1 ) % l1 + 1] , ql , qr , z1[j] );
				}
			}
			printf ( "%d\n" , ans );
		}
	}
}
int main () {
	work ();
	return 0;
}