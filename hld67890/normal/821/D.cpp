#include <stdio.h>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

const int NN = 12000;
struct node {
	int v , c;
	node *next;
} pool[NN*60] , *g[NN*50];
int top;
int r , c , n;
int x[NN] , y[NN];
int S , T;
int dis[NN*50];
map < pair<int,int> , int > m;
void add ( int u , int v , int c ) {
	//printf ( "%d %d %d\n" , u , v , c );
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> c = c; tmp -> next = g[u]; g[u] = tmp;
}
void spfa () {
	int i , k;
	deque < int > q;
	for ( i = 1 ; i <= n + r + c + 1 ; i++ ) {
		dis[i] = 99999999;
	}
	dis[S] = 0; q.push_back ( S );
	while ( q.size () ) {
		k = q.front (); q.pop_front ();
		for ( node *j = g[k] ; j ; j = j -> next ) {
			if ( dis[j->v] > dis[k] + j -> c ) {
				dis[j->v] = dis[k] + j -> c;
				if ( j -> c == 0 ) q.push_front ( j -> v );
				else q.push_back ( j -> v );
			}
		}
	}
	if ( dis[T] != 99999999 ) printf ( "%d\n" , dis[T] );
	else printf ( "-1\n" );
}
void work () {
	int i;
	scanf ( "%d%d%d" , &r , &c , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d%d" , &x[i] , &y[i] );
		m[make_pair(x[i],y[i])] = i;
		if ( x[i] != 1 ) add ( i , n + x[i] - 1  , 1 );
						 add ( i , n + x[i] , 1 );
		if ( x[i] != r ) add ( i , n + x[i] + 1 , 1 );
		if ( y[i] != 1 ) add ( i , n + r + y[i] - 1 , 1 );
						 add ( i , n + r + y[i] , 1 );
		if ( y[i] != c ) add ( i , n + r + y[i] + 1 , 1 );
		if ( x[i] != 1 ) add ( n + x[i] - 1 , i , 0 );
						 add ( n + x[i] , i , 0 );
		if ( x[i] != r ) add ( n + x[i] + 1 , i , 0 );
		if ( y[i] != 1 ) add ( n + r + y[i] - 1 , i , 0 );
						 add ( n + r + y[i] , i , 0 );
		if ( y[i] != c ) add ( n + r + y[i] + 1 , i , 0 );
		if ( x[i] == 1 && y[i] == 1 ) S = i;
		if ( x[i] == r && y[i] == c ) T = i;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( m[make_pair(x[i]-1,y[i])] != 0 ) add ( i , m[make_pair(x[i]-1,y[i])] , 0 );
		if ( m[make_pair(x[i]+1,y[i])] != 0 ) add ( i , m[make_pair(x[i]+1,y[i])] , 0 );
		if ( m[make_pair(x[i],y[i]-1)] != 0 ) add ( i , m[make_pair(x[i],y[i]-1)] , 0 );
		if ( m[make_pair(x[i],y[i]+1)] != 0 ) add ( i , m[make_pair(x[i],y[i]+1)] , 0 );
	}
	if ( m[make_pair(r,c)] == 0 ) {
		add ( n + r , n + r + c + 1 , 0 );
		add ( n + r + c , n + r + c + 1 , 0 );
		T = n + r + c + 1;
	}
	spfa ();
}
int main () {
	//FILE *fpr = freopen ( "d.in" , "r" , stdin );
	work ();
	return 0;
}