#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
	int l , r , s[3][3];
	node *ll , *rr;
} pool[800000] , *t;
int top;
int n , m;
char map[4][600000];
void buildtree ( node *id , int l , int r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		id -> s[0][0] = map[1][l] == '.' ? 0 : 99999999;
		id -> s[1][1] = map[2][l] == '.' ? 0 : 99999999;
		id -> s[0][1] = id -> s[1][0] = map[1][l] == map[2][l] && map[1][l] == '.' ? 1 : 99999999;
	}
	else {
		id -> ll = &pool[++top]; id -> rr = &pool[++top];
		int mid = (l+r)/2;
		buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
		id -> s[0][0] = min ( id -> ll -> s[0][0] + id -> rr -> s[0][0] , id -> ll -> s[0][1] + id -> rr -> s[1][0] ) + 1;
		id -> s[0][1] = min ( id -> ll -> s[0][0] + id -> rr -> s[0][1] , id -> ll -> s[0][1] + id -> rr -> s[1][1] ) + 1;
		id -> s[1][0] = min ( id -> ll -> s[1][0] + id -> rr -> s[0][0] , id -> ll -> s[1][1] + id -> rr -> s[1][0] ) + 1;
		id -> s[1][1] = min ( id -> ll -> s[1][0] + id -> rr -> s[0][1] , id -> ll -> s[1][1] + id -> rr -> s[1][1] ) + 1;
		if ( id -> s[0][0] > 9999999 ) id -> s[0][0] = 99999999;
		if ( id -> s[0][1] > 9999999 ) id -> s[0][1] = 99999999;
		if ( id -> s[1][0] > 9999999 ) id -> s[1][0] = 99999999;
		if ( id -> s[1][1] > 9999999 ) id -> s[1][1] = 99999999;
	}
}
node merge ( node x1 , node x2 ) {
	node tmp;
	tmp.s[0][0] = min ( x1.s[0][0] + x2.s[0][0] , x1.s[0][1] + x2.s[1][0] ) + 1;
	tmp.s[0][1] = min ( x1.s[0][0] + x2.s[0][1] , x1.s[0][1] + x2.s[1][1] ) + 1;
	tmp.s[1][0] = min ( x1.s[1][0] + x2.s[0][0] , x1.s[1][1] + x2.s[1][0] ) + 1;
	tmp.s[1][1] = min ( x1.s[1][0] + x2.s[0][1] , x1.s[1][1] + x2.s[1][1] ) + 1;
	if ( tmp.s[0][0] > 9999999 ) tmp.s[0][0] = 99999999;
	if ( tmp.s[0][1] > 9999999 ) tmp.s[0][1] = 99999999;
	if ( tmp.s[1][0] > 9999999 ) tmp.s[1][0] = 99999999;
	if ( tmp.s[1][1] > 9999999 ) tmp.s[1][1] = 99999999;
	return tmp;
}
node query ( node *id , int l , int r ) {
	//cout << id -> l << " " << id -> r << " " << l << " " << r << endl;
	if ( id -> l == l && id -> r == r ) {
		return *id;
	}
	int mid = (id->l+id->r)/2;
	if ( mid >= r ) return query ( id -> ll , l , r );
	else {
		if ( mid < l ) return query ( id -> rr , l , r );
		else {
			return merge ( query ( id -> ll , l , mid ) , query ( id -> rr , mid + 1 , r ) );
		}
	}
}
void work () {
	int i , a , b;
	node ans;
	scanf ( "%d%d" , &n , &m );
	scanf ( "%s" , map[1] + 1 );
	scanf ( "%s" , map[2] + 1 );
	t = &pool[++top];
	buildtree ( t , 1 , n );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &a , &b );
		if ( (a-1) % n+1 > (b-1) % n+1 ) swap ( a , b );
		ans = query ( t , (a-1) % n+1 , (b-1) % n+1 );
		if ( ans.s[(a-1)/n][(b-1)/n] >= 99999999 ) ans.s[(a-1)/n][(b-1)/n] = -1;
		printf ( "%d\n" , ans.s[(a-1)/n][(b-1)/n] );
	}
}
int main () {
	work ();
	return 0;
}