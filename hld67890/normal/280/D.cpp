#include <iostream>
#include <stdio.h>

using namespace std;

struct info {
	int lmx , rmx , mx , lmn , rmn , mn;
	int lmxl , lmxr , rmxl , rmxr;
	int lmnl , lmnr , rmnl , rmnr;
	int mxl , mxr , mnl , mnr;
	int sum;
} tmp;
struct node {
	int l , r , neg;
	info t;
	node *ll , *rr;
} pool[800000] , *t;
int top;
int n , m;
int a[120000];
int bufl[30] , bufr[30];
void output ( node *id ) {
	if ( id -> ll ) output ( id -> ll );
	cout << id -> l << " " << id -> r << " " << id -> t.mxl << " " << id -> t.mxr << endl;
	if ( id -> rr ) output ( id -> rr );
}
info merge ( info x1 , info x2 ) {
	info y;
	y.sum = x1.sum + x2.sum;
	
	y.mx = x1.rmx + x2.lmx; y.mxl = x1.rmxl; y.mxr = x2.lmxr;
	if ( x1.mx > y.mx ) {
		y.mx = x1.mx; y.mxl = x1.mxl; y.mxr = x1.mxr;
	}
	if ( x2.mx > y.mx ) {
		y.mx = x2.mx; y.mxl = x2.mxl; y.mxr = x2.mxr;
	}
	y.mn = x1.rmn + x2.lmn; y.mnl = x1.rmnl; y.mnr = x2.lmnr;
	if ( x1.mn < y.mn ) {
		y.mn = x1.mn; y.mnl = x1.mnl; y.mnr = x1.mnr;
	}
	if ( x2.mn < y.mn ) {
		y.mn = x2.mn; y.mnl = x2.mnl; y.mnr = x2.mnr;
	}
	
	y.lmx = x1.sum + x2.lmx; y.lmxl = x1.lmxl; y.lmxr = x2.lmxr;
	if ( x1.lmx > y.lmx ) {
		y.lmx = x1.lmx; y.lmxl = x1.lmxl; y.lmxr = x1.lmxr;
	}
	y.lmn = x1.sum + x2.lmn; y.lmnl = x1.lmnl; y.lmnr = x2.lmnr;
	if ( x1.lmn < y.lmn ) {
		y.lmn = x1.lmn; y.lmnl = x1.lmnl; y.lmnr = x1.lmnr;
	}
	
	y.rmx = x2.sum + x1.rmx; y.rmxl = x1.rmxl; y.rmxr = x2.rmxr;
	if ( x2.rmx > y.rmx ) {
		y.rmx = x2.rmx; y.rmxl = x2.rmxl; y.rmxr = x2.rmxr;
	}
	y.rmn = x2.sum + x1.rmn; y.rmnl = x1.rmnl; y.rmnr = x2.rmnr;
	if ( x2.rmn < y.rmn ) {
		y.rmn = x2.rmn; y.rmnl = x2.rmnl; y.rmnr = x2.rmnr;
	}
	return y;
}
info infswap ( info t ) {
	swap ( t.lmx , t.lmn );
	swap ( t.rmx , t.rmn );
	swap ( t.mx , t.mn );
	swap ( t.mxl , t.mnl );
	swap ( t.mxr , t.mnr );
	swap ( t.lmxl , t.lmnl );
	swap ( t.lmxr , t.lmnr );
	swap ( t.rmxl , t.rmnl );
	swap ( t.rmxr , t.rmnr );
	t.lmx *= -1; t.rmx *= -1; t.mx *= -1;
	t.lmn *= -1; t.rmn *= -1; t.mn *= -1;
	t.sum *= -1;
	return t;
}
void pushup ( node *id ) {
	id -> t = merge ( id -> ll -> t , id -> rr -> t );
}
void pushdown ( node *id ) {
	id -> neg = 0;
	id -> ll -> neg ^= 1; id -> rr -> neg ^= 1;
	id -> ll -> t = infswap ( id -> ll -> t );
	id -> rr -> t = infswap ( id -> rr -> t );
}
void buildtree ( node *id , int l , int r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		id -> t.sum = a[l];
		id -> t.lmx = id -> t.rmx = id -> t.mx = a[l];
		id -> t.lmn = id -> t.rmn = id -> t.mn = a[l];
		id -> t.lmxl = id -> t.lmxr = id -> t.rmxl = id -> t.rmxr = l;
		id -> t.lmnl = id -> t.lmnr = id -> t.rmnl = id -> t.rmnr = l;
		id -> t.mxl = id -> t.mxr = id -> t.mnl = id -> t.mnr = l;
		return ;
	}
	int mid = (l+r)/2;
	id -> ll = &pool[++top]; id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
	pushup ( id );
}
void change ( node *id , int x , int y ) {
	if ( id -> l == id -> r ) {
		id -> t.sum = id -> t.lmx = id -> t.rmx = id -> t.mx = id -> t.lmn = id -> t.rmn = id -> t.mn = y;
		return ;
	}
	if ( id -> neg ) pushdown ( id );
	int mid = (id->l+id->r)/2;
	if ( x <= mid ) change ( id -> ll , x , y );
	else change ( id -> rr , x , y );
	pushup ( id );
}
void neg ( node *id , int l , int r ) {
	if ( id -> l == l && id -> r == r ) {
		id -> neg ^= 1;
		id -> t = infswap ( id -> t );
		return ;
	}
	if ( id -> neg ) pushdown ( id );
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) neg ( id -> ll , l , r );
	else {
		if ( l > mid ) neg ( id -> rr , l , r );
		else {
			neg ( id -> ll , l , mid );
			neg ( id -> rr , mid + 1 , r );
		}
	}
	pushup ( id );
}
info query ( node *id , int l , int r ) {
	//cout << id -> l << " " << id -> r << " " << l << " " << r << " " << id -> t.mxl << " " << id->t.mxr << endl;
	if ( id -> l == l && id -> r == r ) return id -> t;
	if ( id -> neg ) pushdown ( id );
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r );
	else {
		if ( l > mid ) return query ( id -> rr , l , r );
		else return merge ( query ( id -> ll , l , mid ) , query ( id -> rr , mid + 1 , r ) );
	}
}
void work () {
	int i , j , op , l , r , k , sum;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	t = &pool[++top];
	buildtree ( t , 1 , n );
	scanf ( "%d" , &m );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d" , &op );
		if ( op == 0 ) {
			scanf ( "%d%d" , &l , &k );
			change ( t , l , k );
		}
		else {
			scanf ( "%d%d%d" , &l , &r , &k );
			sum = 0;
			//output ( t );
			//cout << endl;
			for ( j = 1 ; j <= k ; j++ ) {
				tmp = query ( t , l , r );
				if ( tmp.mx < 0 ) break;
				sum += tmp.mx;
				bufl[j] = tmp.mxl; bufr[j] = tmp.mxr;
				//cout << i << " " << tmp.mxl << " " << tmp.mxr << endl;
				neg ( t , tmp.mxl , tmp.mxr );
			}
			//output ( t );
			//cout << endl;
			for ( j-- ; j >= 1 ; j-- ) {
				neg ( t , bufl[j] , bufr[j] );
			}
			//output ( t );
			//cout << endl;
			printf ( "%d\n" , sum );
		}
	}
}
int main () {
	work ();
	return 0;
}