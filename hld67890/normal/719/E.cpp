#include <stdio.h>
#include <algorithm>
#define $ if(0)

using namespace std;

//long long
const long long mod = 1000000007;
struct matrix {
	long long a[5][5];
};
struct node {
	long long l , r , s , pres;
	matrix lazy;
	node *ll , *rr;
} pool[800000] , *t;
long long top;
long long n , m;
long long a[120000] , b[120000];
matrix muti ( matrix op1 , matrix op2 ) {
	matrix ret;
	ret.a[1][1] = op1.a[1][1] * op2.a[1][1] + op1.a[1][2] * op2.a[2][1];
	ret.a[1][2] = op1.a[1][1] * op2.a[1][2] + op1.a[1][2] * op2.a[2][2];
	ret.a[2][1] = op1.a[2][1] * op2.a[1][1] + op1.a[2][2] * op2.a[2][1];
	ret.a[2][2] = op1.a[2][1] * op2.a[1][2] + op1.a[2][2] * op2.a[2][2];
	ret.a[1][1] %= mod;ret.a[1][2] %= mod;ret.a[2][1] %= mod;ret.a[2][2] %= mod;
	return ret;
}
matrix pow ( matrix f , long long x ) {
	matrix s;
	s.a[1][1] = s.a[2][2] = 1; s.a[1][2] = s.a[2][1] = 0;
	while ( x ) {
		if ( x % 2 ) s = muti ( s , f );
		f = muti ( f , f ); x >>= 1;
	}
	return s;
}
void buildtree ( node *id , long long l , long long r ) {
	id -> lazy.a[1][1] = id -> lazy.a[2][2] = 1; id -> lazy.a[1][2] = id -> lazy.a[2][1] = 0;
	id -> l = l; id -> r = r;
	if ( l == r ) {
		id -> s = a[l]; id -> pres = b[l];
		return ;
	}
	long long mid = (l+r)/2;
	id -> ll = &pool[++top]; id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
	id -> s = (id -> ll -> s + id -> rr -> s) % mod;
	id -> pres = (id -> ll -> pres + id -> rr -> pres) % mod;
}
long long check ( matrix x ) {
	if ( x.a[1][1] == 1 && x.a[1][2] == 0 && x.a[2][1] == 0 && x.a[2][2] == 1 ) return 0;
	return 1;
}
void pushdown ( node *id ) {
	long long tmp1 , tmp2;
	id -> ll -> lazy = muti ( id -> ll -> lazy , id -> lazy );
	id -> rr -> lazy = muti ( id -> rr -> lazy , id -> lazy );
	tmp1 = ((id -> ll -> pres * id -> lazy.a[1][1])%mod) + ((id -> ll -> s * id -> lazy.a[2][1])%mod);
	tmp2 = ((id -> ll -> pres * id -> lazy.a[1][2])%mod) + ((id -> ll -> s * id -> lazy.a[2][2])%mod);
	id -> ll -> pres = tmp1 % mod; id -> ll -> s = tmp2 % mod;
	tmp1 = ((id -> rr -> pres * id -> lazy.a[1][1])%mod) + ((id -> rr -> s * id -> lazy.a[2][1])%mod);
	tmp2 = ((id -> rr -> pres * id -> lazy.a[1][2])%mod) + ((id -> rr -> s * id -> lazy.a[2][2])%mod);
	id -> rr -> pres = tmp1 % mod; id -> rr -> s = tmp2 % mod;
	id -> lazy.a[1][1] = id -> lazy.a[2][2] = 1; id -> lazy.a[1][2] = id -> lazy.a[2][1] = 0;
}
void change ( node *id , long long l , long long r , matrix x ) {
	long long tmp1 , tmp2;
	if ( id -> l == l && id -> r == r ) {
		id -> lazy = muti ( id -> lazy , x );
		tmp1 = ((id -> pres * x.a[1][1]) % mod) + ((id -> s * x.a[2][1])%mod); tmp2 = ((id -> pres * x.a[1][2])%mod) + ((id -> s * x.a[2][2])%mod);
		//printf ( "##%I64d %I64d %I64d %I64d %I64d %I64d %I64d\n" , l , r , x.a[1][1] , id -> s , id -> pres , tmp1 , tmp2 );
		id -> pres = tmp1 % mod; id -> s = tmp2 % mod;
		//if ( id -> s  < 0 ) printf ( "###" );
		return ;
	}
	if ( check ( id -> lazy ) ) {
		pushdown ( id );
	}
	long long mid = (id->l+id->r)/2;
	if ( r <= mid ) change ( id -> ll , l , r , x );
	else {
		if ( l > mid ) change ( id -> rr , l , r , x );
		else {
			change ( id -> ll , l , mid , x );
			change ( id -> rr , mid + 1 , r , x );
		}
	}
	id -> s = (id -> ll -> s + id -> rr -> s) % mod;
	id -> pres = (id -> ll -> pres + id -> rr -> pres) % mod;
}
long long query ( node *id , long long l , long long r ) {
	$ printf ( "@@%I64d %I64d %I64d\n" , id -> l , id -> r , id -> s );
	if ( id -> l == l && id -> r == r ) {
		return id -> s;
	}
	if ( check ( id -> lazy ) ) {
		pushdown ( id );
	}
	long long mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r );
	else {
		if ( l > mid ) return query ( id -> rr , l , r );
		else {
			return (query ( id -> ll , l , mid ) + query ( id -> rr , mid + 1 , r )) % mod;
		}
	}
}
void work () {
	long long i , op , l , r , x;
	matrix tmp;
	scanf ( "%I64d%I64d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
		tmp.a[1][1] = 0; tmp.a[1][2] = tmp.a[2][1] = tmp.a[2][2] = 1;
		if ( a[i] != 1 ) tmp = pow ( tmp , a[i] - 2 );
		if ( a[i] == 1 ) b[i] = 0;
		else b[i] = (tmp.a[1][1] + tmp.a[2][1])%mod;
		if ( a[i] == 1 ) a[i] = 1;
		else a[i] = (tmp.a[1][2] + tmp.a[2][2])%mod;
	}
	$ for ( i = 1 ; i <= n ; i++ ) printf ( "%I64d\n" , b[i] );
	t = &pool[++top];
	buildtree ( t , 1 , n );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%I64d%I64d%I64d" , &op , &l , &r );
		if ( op == 1 ) {
			scanf ( "%I64d" , &x );
			//printf ( "######" );
			tmp.a[1][1] = 0; tmp.a[1][2] = tmp.a[2][1] = tmp.a[2][2] = 1;
			tmp = pow ( tmp , x );
			change ( t , l , r , tmp );
		}
		else {
			printf ( "%I64d\n" , query ( t , l , r ) % mod );
		}
	}
}
int main () {
	//FILE *fpr = freopen ( "e.in" , "r" , stdin );
	//FILE *fpw = freopen ( "e.out" , "w" , stdout );
	work ();
	return 0;
}