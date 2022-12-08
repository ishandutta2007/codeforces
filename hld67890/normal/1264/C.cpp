#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

const long long mod = 998244353;
struct info {
	long long c[3];//E(k)=c[0]E(k+1)+c[1]E(checkpoint)+c[2]
};
struct node {
	long long l , r;
	info t;
	node *ll , *rr;
} pool[410000] , *t;
long long top;
long long n , q;
long long a[220000];
set < long long > s;
set < long long >::iterator it1 , it2;
long long ans;
long long ksm ( long long f , long long x ) {
	long long s = 1;
	while ( x ) {
		if ( x % 2 ) s = s * f % mod;
		f = f * f % mod; x = x / 2;
	}
	return s % mod;
}
long long inv ( long long x ) {
	return ksm ( x , mod - 2 );
}
info merge ( info x1 , info x2 ) {
	info y;
	y.c[0] = x1.c[0] * x2.c[0] % mod;
	y.c[1] = ( x1.c[0] * x2.c[1] + x1.c[1]) % mod;
	y.c[2] = ( x1.c[0] * x2.c[2] + x1.c[2]) % mod;
	return y;
}
void buildtree ( node *id , long long l , long long r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		id -> t.c[0] = a[l];
		id -> t.c[1] = (1-a[l]+mod) % mod;
		id -> t.c[2] = 1;
		return ;
	}
	long long mid = (l+r)/2;
	id -> ll = &pool[++top];
	id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid );
	buildtree ( id -> rr , mid + 1 , r );
	id -> t = merge ( id -> ll -> t , id -> rr -> t );
}
info query ( node *id , long long l , long long r ) {
	if ( id -> l == l && id -> r == r ) return id -> t;
	long long mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r );
	else {
		if ( l > mid ) return query ( id -> rr , l , r );
		else return merge ( query ( id -> ll , l , mid ) , query ( id -> rr , mid + 1 , r ) );
	}
}
long long solve ( long long l , long long r ) {
	info ret = query ( t , l , r );
	return ret.c[2] * inv ( (1-ret.c[1]+mod) % mod ) % mod;
}
void work () {
	long long i , u;
	scanf ( "%lld%lld" , &n , &q );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &a[i] );
		a[i] = (a[i]*inv(100)) % mod;
	}
	t = &pool[++top];
	buildtree ( t , 1 , n );
	s.insert ( 1 );
	s.insert ( n + 1 );
	ans = solve ( 1 , n );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%lld" , &u );
		it1 = it2 = s.find ( u );
		if ( it1 != s.end () ) {
			it1--;
			it2++;
			ans = (ans - solve ( *it1 , u - 1 ) + mod) % mod;
			ans = (ans - solve ( u , *it2 - 1 ) + mod) % mod;
			ans = (ans + solve ( *it1 , *it2 - 1 ) ) % mod;
			s.erase ( u ); 
		}
		else {
			s.insert ( u );
			it1 = it2 = s.find ( u );
			it1--; it2++;
			ans = (ans - solve(*it1,*it2-1) + mod) % mod;
			ans = (ans + solve(*it1,u-1) ) % mod;
			ans = (ans + solve(u,*it2-1) ) % mod;
		}
		printf ( "%lld\n" , ans );
	}
}
int main () {
	work ();
	return 0;
}