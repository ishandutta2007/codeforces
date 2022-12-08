#include <stdio.h>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

//long long
struct node {
	long long v;
	node *next;
} pool[1200000] , *g[120000];
long long top;
long long n;
long long a[120000];
long long ex[120000] , tot;
map < pair<long long,long long> , long long > ma;
queue < long long > q;
long long vis[120000] , dis[120000] , from[120000];
long long ans;
void add ( long long u , long long v ) {
	//printf ( "%I64d %I64d\n" , u , v );
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void work () {
	long long i , k;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
	}
	for ( i = 0 ; i <= 60 ; i++ ) {
		tot = 0;
		for ( long long j = 1 ; j <= n ; j++ ) {
			if ( a[j]&(1ll<<i)) ex[++tot] = j;
		}
		if ( tot >= 3 ) {
			printf ( "3\n" );
			return ;
		}
		if ( tot == 2 ) {
			if ( ex[1] > ex[2] ) swap ( ex[1] , ex[2] );
			if ( ma[make_pair(ex[1],ex[2])] == 0 ) {
				add ( ex[1] , ex[2] );
				add ( ex[2] , ex[1] );
			}
			ma[make_pair(ex[1],ex[2])] = 1;
		}
	}
	ans = 999999;
	for ( i = 1 ; i <= n ; i++ ) {
		q.push ( i );
		tot = 0;
		vis[i] = 1;
		while ( q.size () ) {
			k = q.front (); q.pop ();
			ex[++tot] = k;
			for ( node *j = g[k] ; j ; j = j -> next ) {
				if ( j -> v == from[k] ) continue;
				if ( !vis[j->v] ) {
					dis[j->v] = dis[k] + 1;
					vis[j->v] = 1;
					from[j->v] = k;
					q.push ( j -> v );
				}
				else {
					ans = min ( ans , dis[k] + dis[j->v] + 1 );
				}
			}
		}
		//printf ( "\n");
		//for( int j = 1 ; j<= n ; j++ ) printf ( "%I64d %I64d\n" , vis[j] , dis[j] );
		//printf ( "%I64d\n" , ans );
		vis[i] = 0;
		for ( long long j = 1 ; j <= tot ; j++ ) {
			vis[ex[j]] = dis[ex[j]] = 0;
			from[ex[j]] = 0;
		}
	}
	if ( ans == 999999 ) ans = -1;
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}