#include <stdio.h>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

struct node {
	int v;
	long long f;
	node *next , *rev;
} pool[120000] , *g[120000];
int top;
int n;
int x[1200] , y[1200];
long long c[1200];
int s , t;
int level[120000];
long long tot;
map < pair<int,int> , int > m;
void add ( int u , int v , long long f ) {
	node *tmp1 = &pool[++top] , *tmp2 = &pool[++top];
	//printf ( "%d %d %lld\n" , u , v , f );
	tmp1 -> v = v; tmp1 -> f = f; tmp1 -> next = g[u]; g[u] = tmp1; tmp1 -> rev = tmp2;
	tmp2 -> v = u; tmp2 -> f = 0; tmp2 -> next = g[v]; g[v] = tmp2; tmp2 -> rev = tmp1;
}
bool makelevel () {
	int i , k;
	queue < int > q;
	for ( i = 1 ; i <= t ; i++ ) {
		level[i] = -1;
	}
	level[s] = 1; q.push ( s );
	while ( q.size () ) {
		k = q.front (); q.pop ();
		for ( node *j = g[k] ; j ; j = j -> next )
			if ( j -> f && level[j->v] == -1 ) {
				level[j->v] = level[k] + 1;
				if ( j -> v == t ) return true;
				q.push ( j -> v );
			}
	}
	return false;
}
long long find ( int k , long long key ) {
	if ( k == t ) return key;
	long long flow , sum = 0;
	for ( node *j = g[k] ; j ; j = j -> next ) {
		if ( j -> f && level[j->v] == level[k] + 1 && sum < key ) {
			flow = find ( j -> v , min ( j -> f , key - sum ) );
			j -> f -= flow;
			j -> rev -> f += flow;
			sum += flow;
		}
	}
	if ( sum == 0 ) level[k] = -1;
	return sum;
}
void dinic () {
	long long ans = 0;
	while ( makelevel () == true ) ans += find ( s , 214748364777777ll );
	printf ( "%lld\n" , tot - ans );
}
void work () {
	int i , k , tx , ty , tmp;
	scanf ( "%d" , &n );
	s = n * 2 + 1; t = n * 2 + 1 + 1;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d%d%lld" , &x[i] , &y[i] , &c[i] );
		add ( i * 2 - 1 , i * 2 , c[i] );
		m[make_pair(x[i],y[i])] = i;
		tot += c[i];
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( k = -1 ; k <= 1 ; k += 2 ) {
			if ( abs(x[i]) % 2 == 0 && abs(y[i]) % 2 == 0 ) {
				tx = x[i]; ty = y[i] + k;
			}
			if ( abs(x[i]) % 2 == 1 && abs(y[i]) % 2 == 0 ) {
				tx = x[i] + k; ty = y[i];
			}
			if ( abs(x[i]) % 2 == 0 && abs(y[i]) % 2 == 1 ) {
				tx = x[i] + k; ty = y[i];
			}
			if ( abs(x[i]) % 2 == 1 && abs(y[i]) % 2 == 1 ) {
				continue;
			}
			tmp = m[make_pair(tx,ty)];
			if ( tmp ) {
				add ( i * 2 , tmp * 2 - 1 , 214748364777777ll );
			}
		}
		if ( abs(x[i]) % 2 == 1 && abs(y[i]) % 2 == 0 ) {
			add ( s , i * 2 - 1 , 214748364777777ll );
		}
		if ( abs(x[i]) % 2 == 1 && abs(y[i]) % 2 == 1 ) {
			add ( i * 2 , t , 214748364777777ll );
		}
	}
	dinic ();
}
int main () {
	work ();
	return 0;
}