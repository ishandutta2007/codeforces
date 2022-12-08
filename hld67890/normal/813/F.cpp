#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 120000;
struct link {
	int x , y;
	link *next , *pre;
} pooll[maxn*30];
struct node {
	int l , r , flag;
	link *t;
	node *ll , *rr;
} pool[maxn*2] , *t;
int top , topl;
int n , q;
map < pair <int,int> , int > ma;
map < pair <int,int> , int >::iterator it;
int c[maxn] , siz[maxn] , del[maxn];
int ans[maxn];
void buildtree ( node *id , int l , int r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) return ;
	int mid = (l+r)/2;
	id -> ll = &pool[++top]; id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
}
void addedge ( node *id , int l , int r , int x , int y ) {
	//printf ( "%d %d %d %d\n" , id -> l , id -> r , l , r );
	if ( id -> l == l && id -> r == r ) {
		link *tmp = &pooll[++topl];
		tmp -> x = x; tmp -> y = y;
		tmp -> next = id -> t;
		if ( id -> t ) id -> t -> pre = tmp;
		id -> t = tmp;
		return ;
	}
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) addedge ( id -> ll , l , r , x , y );
	else {
		if ( l > mid ) addedge ( id -> rr , l , r , x , y );
		else {
			addedge ( id -> ll , l , mid , x , y );
			addedge ( id -> rr , mid + 1 , r , x , y );
		}
	}
}
pair<int,int> find ( int x ) {
	int i;
	pair<int,int> ret;
	ret.second = 0;
	for ( i = x ; c[i] > 0 ; i = c[i] ) ret.second ^= del[i];
	ret.first = i;
	return ret;
}
void undo ( int x ) {
	int i;
	//printf ( "%d\n" , x );
	for ( i = c[x] ; c[i] > 0 ; i = c[i] ) siz[i] -= siz[x];
	siz[i] -= siz[c[x]];
	c[x] = -1; del[x] = 0;
}
void travel ( node *id ) {
	pair<int,int> tmp1 , tmp2;
	link *last , *j;
	last = NULL;
	for ( j = id -> t ; j ; j = j -> next ) {
		last = j;
		tmp1 = find ( j -> x );
		tmp2 = find ( j -> y );
		if ( tmp1.first == tmp2.first ) {
			if ( tmp1.second == tmp2.second ) {
				id -> flag = -1;
				for ( j = j -> pre ; j ; j = j -> pre ) {
					if ( j -> x != -1 ) undo ( j -> x );
				}
				return ;
			}
			else {
				j -> x = -1;
			}
		}
		else {
			if ( siz[tmp1.first] < siz[tmp2.first] ) swap ( tmp1 , tmp2 );
			//printf ( " %d %d\n" , tmp1.first , tmp2.first );
			c[tmp2.first] = tmp1.first;
			del[tmp2.first] = 1 ^ tmp1.second ^ tmp2.second;
			siz[tmp1.first] += siz[tmp2.first];
			j -> x = tmp2.first;
		}
	}
	if ( id -> l == id -> r ) id -> flag = 1;
	else {
		travel ( id -> ll ); travel ( id -> rr );
	}
	for ( j = last ; j ; j = j -> pre ) {
		//printf ( "%d %d\n" , j -> x , j -> y );
		if ( j -> x != -1 ) undo ( j -> x );
	}
}
void getans ( node *id ) {
	if ( id -> l == id -> r ) {
		ans[id->l] = id -> flag;
		return ;
	}
	if ( id -> flag == -1 ) {
		id -> ll -> flag = -1;
		id -> rr -> flag = -1;
	}
	getans ( id -> ll ); getans ( id -> rr );
}
void work () {
	int i , x , y;
	pair<int,int> tmp;
	scanf ( "%d%d" , &n , &q );
	for ( i = 1 ; i <= n ; i++ ) {
		c[i] = -1; siz[i] = 1;
	}
	t = &pool[++top];
	buildtree ( t , 1 , q );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%d%d" , &x , &y );
		if ( x > y ) swap ( x , y );
		tmp = make_pair ( x , y );
		if ( ma[tmp] == 0 ) {
			ma[tmp] = i;
		}
		else {
			addedge ( t , ma[tmp] , i - 1 , x , y );
			ma.erase ( tmp );
		}
	}
	for ( it = ma.begin () ; it != ma.end () ; it++ ) {
		addedge ( t , it -> second , q , it -> first.first , it -> first.second );
	}
	travel ( t );
	getans ( t );
	for ( i = 1 ; i <= q ; i++ ) printf ( "%s\n" , ans[i]==1?"YES":"NO" );
}
int main () {
	work ();
	return 0;
}