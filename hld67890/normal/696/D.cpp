#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

//long long
struct node {
	long long v , index;
	node *next[30] , *fail;
} pool[12000] , *t;
struct matrix {
	long long n , m;
	long long a[300][300];
} tmp , tmp1;
matrix operator * ( matrix x1 , matrix x2 ) {
	matrix y;
	long long i , j , k;
	y.n = x1.n; y.m = x2.m;
	for ( i = 1 ; i <= y.n ; i++ ) for ( j = 1 ; j <= y.m ; j++ ) y.a[i][j] = -99999999;
	for ( i = 1 ; i <= y.n ; i++ ) for ( j = 1 ; j <= y.m ; j++ ) for ( k = 1 ; k <= x1.m ; k++ )
		y.a[i][j] = max ( y.a[i][j] , x1.a[i][k] + x2.a[k][j] );
	return y;
}
long long top , cnt;
long long n , l;
long long v[1200];
char z[1200];
void insert ( node *id , long long i , long long val ) {
	if ( z[i] == '\0' ) {
		id -> v += val;
		return ;
	}
	if ( !id -> next[z[i]-'a'+1] ) {
		id -> next[z[i]-'a'+1] = &pool[++top];
		id -> next[z[i]-'a'+1] -> index = ++cnt;
	}
	insert ( id -> next[z[i]-'a'+1] , i + 1 , val );
}
void bfs () {
	long long i;
	node *j , *k;
	queue < node* > q;
	q.push ( t );
	t -> fail = t;
	while ( q.size() != 0 ) {
		j = q.front (); q.pop ();
		if ( j == t ) {
			for ( i = 1 ; i <= 26 ; i++ ) {
				if ( j -> next[i] ) {
					j -> next[i] -> fail = t;
					q.push ( j -> next[i] ); 
				}
			}
			continue;
		}
		for ( i = 1 ; i <= 26 ; i++ )
			if ( j -> next[i] ) {
				k = j -> fail;
				while ( k != t ) {
					if ( k -> next[i] ) break;
					k = k -> fail;
				}
				if ( k -> next[i] ) j -> next[i] -> fail = k -> next[i];
				else j -> next[i] -> fail = k;
				j -> next[i] -> v += j -> next[i] -> fail -> v;
				q.push ( j -> next[i] );
			}
	}
}
void dfs ( node *id ) {
	long long i;
	node *k;
	for ( i = 1 ; i <= 26 ; i++ )
		if ( id -> next[i] ) {
			tmp.a[id->index][id->next[i]->index] = id -> next[i] -> v;
			dfs ( id -> next[i] );
		}
		else {
			k = id -> fail;
			while ( k != t ) {
				if ( k -> next[i] ) break;
				k = k -> fail;
			}
			if ( k -> next[i] ) tmp.a[id->index][k->next[i]->index] = k -> next[i] -> v;
			else tmp.a[id->index][t->index] = k -> v;
		}
}
matrix pow ( matrix t , long long x ) {
	matrix s , f;
	s = t; x--; f = t;
	while ( x ) {
		if ( x % 2 ) s = s * f;
		f = f * f;
		x >>= 1;
	}
	return s;
}
void work () {
	long long i , j , ans;
	scanf ( "%I64d%I64d" , &n , &l );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%I64d" , &v[i] );
	t = &pool[++top];
	t -> index = ++cnt;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s" , z + 1 );
		insert ( t , 1 , v[i] );
	}
	bfs ();
	tmp.n = tmp.m = cnt;
	for ( i = 1 ; i <= cnt ; i++ ) for ( j = 1 ; j <= cnt ; j++ ) tmp.a[i][j] = -99999999;
	dfs ( t );
	tmp1.n = 1; tmp1.m = cnt;
	for ( i = 1 ; i <= cnt ; i++ ) tmp1.a[1][i] = -99999999;
	tmp1.a[1][1] = 0;
	tmp1 = tmp1 * pow ( tmp , l );
	ans = 0;
	for ( i = 1 ; i <= cnt ; i++ ) ans = max ( ans , tmp1.a[1][i] );
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}