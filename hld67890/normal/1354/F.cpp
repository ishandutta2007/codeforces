#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
	int v , f , c;
	node *next , *rev;
} pool[1200000] , *g[12000] , *from[12000];
int top;
int n , num;
int sum , flow , sum1;
int a[80] , b[80];
int s , t;
int dis[12000] , f[12000];
int gt[100] , sm[100];
void clear () {
	int i;
	for ( i = 1 ; i <= top ; i++ ) {
		pool[i] = pool[0];
	}
	for ( i = 1 ; i <= t ; i++ ) {
		g[i] = from[i] = NULL;
		dis[i] = f[i] = 0;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		gt[i] = sm[i] = 0;
	}
	top = 0;
	s = t = 0;
	sum = flow = sum1 = 0;
}
void add ( int u , int v , int f , int c ) {
	node *tmp1 = &pool[++top] , *tmp2 = &pool[++top];
	tmp1 -> v = v; tmp1 -> f = f; tmp1 -> c = c; tmp1 -> next = g[u]; g[u] = tmp1; tmp1 -> rev = tmp2;
	tmp2 -> v = u; tmp2 -> f = 0; tmp2 -> c = -c; tmp2 -> next = g[v]; g[v] = tmp2; tmp2 -> rev = tmp1;
}
bool spfa () {
	int i , k;
	queue < int > q;
	for ( i = 1 ; i <= t ; i++ ) dis[i] = 9999999, f[i] = 0;
	dis[s] = 0; f[s] = 1; q.push ( s );
	while ( q.size () != 0 ) {
		k = q.front (); q.pop (); f[k] = 0;
		for ( node *j = g[k] ; j ; j = j -> next )
			if ( j -> f && dis[j->v] > dis[k] + j -> c ) {
				dis[j->v] = dis[k] + j -> c;
				from[j->v] = j;
				if ( f[j->v] == 0 ) q.push ( j -> v );
				f[j->v] = 1;
			}
	}
	if ( dis[t] != 9999999 ) return true;
	return false;
}
int find () {
	int i , f = 999999;
	for ( i = t ; i != s ; i = from[i] -> rev -> v ) f = min ( f , from[i] -> f );
	flow += f;
	for ( i = t ; i != s ; i = from[i] -> rev -> v ) from[i] -> f -= f, from[i] -> rev -> f += f;
	return f * dis[t];
}
void dinic () {
	int ans = 0;
	while ( spfa () == true ) ans += find ();
	//printf ( "%d\n" , flow );
	//printf ( "%d\n" , -ans );
}
void work () {
	int i , j , x , y;
	scanf ( "%d%d" , &n , &num );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d%d" , &a[i] , &b[i] );
	}
	s = 1; t = 1 + n + num + 1 + 1;
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= num ; j++ ) {
			add ( 1 + i , 1 + n + j , 1 , -a[i] - (j-1) * b[i] );
		}
		add ( 1 + i , 1 + n + num + 1 , 1 , -(num-1) * b[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		add ( 1 , 1 + i , 1 , 0 );
	}
	for ( i = 1 ; i <= num ; i++ ) {
		add ( 1 + n + i , t , 1 , 0 );
	}
	add ( 1 + n + num + 1 , t , n - num , 0 );
	dinic ();
	for ( i = 1 ; i <= n ; i++ ) {
		for ( node *k = g[1+i] ; k ; k = k -> next ) {
			//printf ( "!!%d %d %d\n" , i , k -> v , k -> f  );
			if ( k -> v >= 1 + n + 1 && k -> v <= 1 + n + num && k -> f == 0 ) {
				gt[k->v-1-n] = i;
				sm[i] = 1;
			}
		}
	}
	printf ( "%d\n" , n + n - num );
	for ( i = 1 ; i <= num - 1 ; i++ ) {
		printf ( "%d " , gt[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( sm[i] == 0 ) {
			printf ( "%d %d " , i , -i );
		}
	}
	printf ( "%d\n" , gt[num] );
	clear ();
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}