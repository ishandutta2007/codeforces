#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

const long long NN = 120000;
struct node {
	long long v;
	node *next;
} pool[NN*2] , *g[NN];
long long top;
long long n;
long long a[NN];
long long b[NN] , tot;
long long rdep[NN];
map < long long , long long > m;
long long sxor , ans;
void add ( long long u , long long v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( long long i , long long from ) {
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dfs ( j -> v , i );
		rdep[i] = rdep[j->v] ^ 1;
	}
	if ( rdep[i] == 1 ) m[a[i]]++;
	else {
		b[++tot] = a[i];
		sxor ^= a[i];
	}
}
void work () {
	long long i , fa;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
	}
	for ( i = 2 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &fa );
		add ( fa , i ); add ( i , fa );
	}
	sxor = 0;
	dfs ( 1 , -1 );
	//printf ( "%I64d\n" , sxor );
	if ( sxor == 0 ) {
		ans = (n-tot)*(n-tot-1)/2;
		ans += tot*(tot-1)/2;
		for ( i = 1 ; i <= tot ; i++ ) {
			ans += m[b[i]];
		}
	}
	else {
		ans = 0;
		for ( i = 1 ; i <= tot ; i++ ) {
			ans += m[sxor^b[i]];
		}
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}