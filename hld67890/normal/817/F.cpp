#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long NN = 100010;
struct node {
	int l , r , s , cover , rev;
	node *ll , *rr;
} pool[NN*40] , *t;
struct so {
	long long x , i , f;
} s[NN*8];
long long top;
long long n;
long long op[NN] , le[NN] , ri[NN];
long long tot;
long long rev[NN*8];
bool cmp ( so x1 , so x2 ) {
	return x1.x < x2.x;
}
void buildtree ( node *id , long long l , long long r ) {
	//printf ( "%d %I64d\n" , id , r );
	id -> l = l; id -> r = r;
	id -> cover = -1;
	if ( l == r ) return ;
	long long mid = (l+r)/2;
	id -> ll = &pool[++top]; id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
}
void pushdown ( node *id ) {
	if ( id -> rev ) {
		if ( id -> ll -> cover != -1 ) id -> ll -> cover ^= 1;
		else id -> ll -> rev ^= 1;
		id -> ll -> s = (id->ll->r-id->ll->l+1) - id -> ll -> s;
		if ( id -> rr -> cover != -1 ) id -> rr -> cover ^= 1;
		else id -> rr -> rev ^= 1;
		id -> rr -> s = (id->rr->r-id->rr->l+1) - id -> rr -> s;
		id -> rev = 0;
	}
	if ( id -> cover != -1 ) {
		id -> ll -> cover = id -> cover;
		id -> ll -> rev = 0;
		id -> ll -> s = (id->ll->r-id->ll->l+1) * id -> cover;
		id -> rr -> cover = id -> cover;
		id -> rr -> rev = 0;
		id -> rr -> s = (id->rr->r-id->rr->l+1) * id -> cover;
		id -> cover = -1;
	}
}
void update ( node *id ) {
	id -> s = id -> ll -> s + id -> rr -> s;
}
void change ( node *id , long long l , long long r , long long kind ) {
	if ( id -> l == l && id -> r == r ) {
		if ( kind == -1 ) {
			if ( id -> cover != -1 ) id -> cover ^= 1;
			else id -> rev ^= 1;
			id -> s = (id->r-id->l+1) - id -> s;
		}
		else {
			id -> cover = kind;
			id -> s = (id->r-id->l+1)*kind;
			id -> rev = 0;
		}
		return ;
	}
	pushdown ( id );
	long long mid = (id->l+id->r)/2;
	if ( r <= mid ) change ( id -> ll , l , r , kind );
	else {
		if ( l > mid ) change ( id -> rr , l , r , kind );
		else {
			change ( id -> ll , l , mid , kind );
			change ( id -> rr , mid + 1 , r , kind );
		}
	}
	update ( id );
}
long long query ( node *id ) {
	//printf ( " %I64d %I64d %I64d\n" , id -> l , id -> r , id -> s );
	if ( id -> l == id -> r ) return id -> l;
	pushdown ( id );
	if ( id -> ll -> s != (id->ll->r-id->ll->l+1) ) return query ( id -> ll );
	else return query ( id -> rr );
}
void work () {
	long long i , k;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d%I64d%I64d" , &op[i] , &le[i] , &ri[i] );
		if ( le[i] - 1 != 0 ) s[++tot].x = le[i] - 1;
		s[++tot].x = le[i];
		s[tot].i = i; s[tot].f = 1;
		s[++tot].x = le[i] + 1;
		if ( ri[i] - 1 != 0 ) s[++tot].x = ri[i] - 1;
		s[++tot].x = ri[i];
		s[tot].i = i; s[tot].f = 2;
		s[++tot].x = ri[i] + 1;
	}
	s[++tot].x = 1;
	sort ( s + 1 , s + 1 + tot , cmp );
	k = 0;
	for ( i = 1 ; i <= tot ; i++ ) {
		if ( i == 1 || s[i].x != s[i-1].x ) k++;
		if ( s[i].f == 1 ) le[s[i].i] = k;
		if ( s[i].f == 2 ) ri[s[i].i] = k;
		rev[k] = s[i].x;
	}
	//printf ( "%I64d %I64d\n" , top , k );
	t = &pool[++top];
	buildtree ( t , 1 , k );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( op[i] == 1 ) change ( t , le[i] , ri[i] , 1 );
		if ( op[i] == 2 ) change ( t , le[i] , ri[i] , 0 );
		if ( op[i] == 3 ) change ( t , le[i] , ri[i] , -1 );
		printf ( "%I64d\n" , rev[query ( t )] );
	}
}
int main () {
	//FILE *fpr = freopen ( "f.in" , "r" , stdin );
	//FILE *fpw = freopen ( "f.out" , "w" , stdout );
	work ();
	return 0;
}