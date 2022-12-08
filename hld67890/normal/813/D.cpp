#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 5100;
struct node {
	int v , f , c;
	node *next , *rev;
} pool[maxn*20*2] , *g[maxn*6] , *pre[maxn*6];
int top;
int n;
int a[maxn];
int S , T;
int dis[maxn*6] , f[maxn*6];
void add ( int u , int v , int f , int c ) {
	node *tmp1 = &pool[++top] , *tmp2 = &pool[++top];
	tmp1 -> v = v; tmp1 -> f = f; tmp1 -> c = c; tmp1 -> next = g[u]; g[u] = tmp1; tmp1 -> rev = tmp2;
	tmp2 -> v = u; tmp2 -> f = 0; tmp2 -> c = -c; tmp2 -> next = g[v]; g[v] = tmp2; tmp2 -> rev = tmp1;
}
bool spfa () {
	int i , k;
	queue < int > q;
	for ( i = S ; i <= T ; i++ ) {
		dis[i] = -9999999;
		f[i] = 0;
	}
	dis[S] = 0; q.push ( S ); f[S] = 0;
	while ( q.size () ) {
		k = q.front (); q.pop (); f[k] = 0;
		for ( node *j = g[k] ; j ; j = j -> next )
			if ( j -> f && dis[j->v] < dis[k] + j -> c ) {
				dis[j->v] = dis[k] + j -> c;
				pre[j->v] = j;
				if ( !f[j->v] ) q.push ( j -> v );
				f[j->v] = 1;
			}
	}
	if ( dis[T] != -9999999 && dis[T] > 0 ) return true;
	return false;
}
int find () {
	int i , minn = 999999;
	for ( i = T ; i != S ; i = pre[i] -> rev -> v ) {
		minn = min ( minn , pre[i] -> f );
	}
	for ( i = T ; i != S ; i = pre[i] -> rev -> v ) {
		pre[i] -> f -= minn;
		pre[i] -> rev -> f += minn;
	}
	return minn * dis[T];
}
void dinic () {
	int ret = 0;
	while ( spfa () == true ) ret += find ();
	printf ( "%d\n" , ret );
}
void work () {
	int i , j;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = i + 1 ; j <= n ; j++ ) {
			if ( a[i] % 7 == a[j] % 7 ) {
				add ( 1 + 1 + n + n + n + i , 1 + 1 + n + n + n + j , 9999 , 0 );
				break;
			}
		}
		for ( j = i + 1 ; j <= n ; j++ ) {
			if ( a[i] == a[j] ) {
				add ( 1 + 1 + n + n + i , 1 + 1 + n + n + j , 9999 , 0 );
				break;
			}
		}
		for ( j = i + 1 ; j <= n ; j++ ) {
			if ( a[i] + 1 == a[j] ) {
				add ( 1 + 1 + n + i , 1 + 1 + n + n + j , 9999 , 0 );
				break;
			}
		}
		for ( j = i + 1 ; j <= n ; j++ ) {
			if ( a[i] - 1 == a[j] ) {
				add ( 1 + 1 + n + i , 1 + 1 + n + n + j , 9999 , 0 );
				break;
			}
		}
		for ( j = i + 1 ; j <= n ; j++ ) {
			if ( a[i] % 7 == a[j] % 7 ) {
				add ( 1 + 1 + n + i , 1 + 1 + n + n + n + j , 9999 , 0 );
				break;
			}
		}
		add ( 1 + 1 + n + n + i , 1 + 1 + i , 9999 , 0 );
		add ( 1 + 1 + n + n + n + i , 1 + 1 + i , 9999 , 0 );
		add ( 1 + 1 + i , 1 + 1 + n + i , 1 , 1 );
		add ( 1 + 1 + n + i , 1 + 1 + n + n + n + n + 1 , 1 , 0 );
		add ( 1 + 1 , 1 + 1 + i , 9999 , 0 );
	}
	add ( 1 , 2 , 2 , 0 );
	S = 1; T = 1 + 1 + n + n + n + n + 1;
	dinic ();
}
int main () {
	//FILE *fpr = freopen ( "d.in" , "r" , stdin );
	work ();
	return 0;
}