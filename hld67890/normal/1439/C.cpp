#include <stdio.h>
#include <algorithm>

using namespace std;

struct tup {
	int num , sum , stop;
	
	tup (){num=sum=stop=0;}
	tup ( int _num , int _sum , int _stop ) {
		num = _num;
		sum = _sum;
		stop = _stop;
	}
};
struct node {
	int l , r , mx , mn , cov;
	long long sum;
	node *ll , *rr;
} pool[410000] , *t;
int top;
int n , q;
int a[220000];
int ans;
tup operator + (tup x1 , tup x2 ) {
	x1.num += x2.num;
	x1.sum += x2.sum;
	x1.stop = x2.stop;
	return x1;
}
void update ( node *id ) {
	id -> mx = id -> ll -> mx;
	id -> mn = id -> rr -> mn;
	id -> sum = id -> ll -> sum + id -> rr -> sum;
}
void pushdown ( node *id ) {
	if ( id -> ll ) {
		if ( id -> cov ) {
			id -> ll -> cov = id -> ll -> mn = id -> ll -> mx = id -> cov;
			id -> ll -> sum = 1ll * (id->ll->r-id->ll->l+1) * id -> cov;
			id -> rr -> cov = id -> rr -> mn = id -> rr -> mx = id -> cov;
			id -> rr -> sum = 1ll * (id->rr->r-id->rr->l+1) * id -> cov;
			id -> cov = 0;
		}
	}
}
void buildtree ( node *id , int l , int r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		id -> mx = id -> mn = id -> sum = a[l];
		return ;
	}
	int mid = (l+r)/2;
	id -> ll = &pool[++top];
	id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid );
	buildtree ( id -> rr , mid + 1 , r );
	update ( id );
}
void change ( node *id , int l , int r , int x ) {
	pushdown ( id );
	if ( id -> mn > x ) return ;
	if ( id -> l == l && id -> r == r ) {
		if ( id -> mx <= x ) {
			id -> mn = id -> mx = x;
			id -> sum = 1ll * (id->r-id->l+1) * x;
			id -> cov = x;
		}
		else {
			change ( id -> ll , l , id -> ll -> r , x );
			change ( id -> rr , id -> rr -> l , r , x );
			update ( id );
		}
		return ;
	}
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) change ( id -> ll , l , r , x );
	else {
		if ( l > mid ) change ( id -> rr , l , r , x );
		else {
			change ( id -> ll , l , mid , x );
			change ( id -> rr , mid + 1 , r , x );
		}
	}
	update ( id );
}
tup query ( node *id , int l , int r , int y ) {
	pushdown ( id );
	//printf ( "%d %d %d %d %d\n" , id -> l , id -> r , l , r , y );
	if ( id -> l == l && id -> r == r ) {
		if ( y < id -> mx ) return tup(0,0,1);
		if ( y >= id -> sum ) {
			return tup(id->r-id->l+1,id->sum,0);
		}
		tup ret = query ( id -> ll , l , id -> ll -> r , y );
		y -= ret.sum;
		if ( ret.stop == 0 )
			return ret + query ( id -> rr , id -> rr -> l , r , y );
		else return ret;
	}
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r , y );
	else {
		if ( l > mid ) return query ( id -> rr , l , r , y );
		else {
			tup ret = query ( id -> ll , l , mid , y );
			y -= ret.sum;
			if ( ret.stop == 0 )
				return ret + query ( id -> rr , mid + 1 , r , y );
			else return ret;
		}
	}
}
int querynxt ( node *id , int x ) {
	if ( x < id -> mn ) return n + 1;
	if ( id -> l == id -> r ) {
		if ( id -> mx <= x ) return id -> l;
		return n + 1;
	}
	pushdown ( id );
	int ret = querynxt ( id -> ll , x );
	if ( ret <= n ) return ret;
	return querynxt ( id -> rr , x );
}
void work () {
	int i , op , x , y;
	tup ret;
	scanf ( "%d%d" , &n , &q );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
	}
	t = &pool[++top];
	buildtree ( t , 1 , n );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%d%d%d" , &op , &x , &y );
		if ( op == 1 ) {
			change ( t , 1 , x , y );
		}
		else {
			ans = 0;
			while ( y > 0 && x <= n ) {
				ret = query ( t , x , n , y );
				ans += ret.num;
				y -= ret.sum;
				if ( x + ret.num > n ) break;
				//printf ( "%d %d %d %d %d\n" , x , y , ret.num , ret.sum , ans );
				x = querynxt ( t , y );
			}
			printf ( "%d\n" , ans );
		}
	}
}
int main () {
	work ();
	return 0;
}