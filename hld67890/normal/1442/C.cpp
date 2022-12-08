#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

const int mod = 998244353;
const int lim = 26;
struct so {
	so ():v(0),flip(0),len(0),c(0){}
	so (int _v, int _flip , int _len , int _c) {
		v = _v;
		flip = _flip;
		len = _len;
		c = _c;
	}
	
	int v , flip , len , c;
};
struct node {
	int v , c;
	node *next;
} pool[410000] , *g[210000];
int top;
int n , m;
int dis[210000][40][3];
pair <int,int> far[210000][3];
int ans;
void add ( int u , int v , int c ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> c = c; tmp -> next = g[u]; g[u] = tmp;
}
int get ( int flip , int len ) {
	int i , ret = 0 , pw = 1;
	for ( i = 1 ; i <= flip ; i++ ) {
		ret = (ret + pw) % mod;
		pw = (pw * 2) % mod;
	}
	return (ret+len) % mod;
}
bool operator < ( so x1 , so x2 ) {
	if ( x1.flip <= lim && x2.flip <= lim ) {
		if ( x1.flip == x2.flip ) {
			return x1.len > x2.len;
		}
		else {
			return x1.flip > x2.flip;
		}
	}
	if ( x1.flip > lim && x2.flip > lim ) {
		return x1.flip > x2.flip;
	}
	if ( x1.flip <= lim ) return 0;
	return 1;
}
void dij () {
	int i , j;
	priority_queue < so > q;
	so k , tmp;
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 0 ; j <= lim ; j++ ) {
			dis[i][j][0] = dis[i][j][1] = 0x3f3f3f3f;
		}
		far[i][0] = far[i][1] = {9999999,9999999};
	}
	dis[1][0][0] = 0;
	q.push ( so(1 , 0 , 0 , 0) );
	while ( q.size () ) {
		k = q.top (); q.pop ();
		//printf ( "%d %d %d %d\n" , k.v , k.flip , k.len , k.c );
		for ( node *j = g[k.v] ; j ; j = j -> next ) {
			tmp = k;
			tmp.v = j -> v;
			tmp.len++;
			tmp.flip += (j -> c!=k.c);
			tmp.c = j -> c;
			if ( k.flip <= lim - 1 ) {
				if ( dis[j->v][tmp.flip][tmp.c] > tmp.len ) {
					dis[j->v][tmp.flip][tmp.c] = tmp.len;
					q.push ( tmp );
				}
			}
			else {
				if ( far[tmp.v][tmp.c] > make_pair(tmp.flip,tmp.len) ) {
					far[tmp.v][tmp.c] = {tmp.flip,tmp.len};
					q.push ( tmp );
				}
			}
		}
	}
}
void work () {
	int i , j , u , v;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v , 0 );
		add ( v , u , 1 );
	}
	dij ();
	/*for ( i = n ; i <= n ; i++ ) {
		for ( j = 0 ; j <= lim ; j++ ) {
			printf ( "dis[%d,%d,%d] = %d\n" , i , j , 0 , dis[i][j][0] );
			printf ( "dis[%d,%d,%d] = %d\n" , i , j , 1 , dis[i][j][1] );
		}
	}*/
	ans = 2147483647;
	for ( j = 0 ; j <= lim ; j++ ) {
		if ( dis[n][j][0] != 0x3f3f3f3f )
			ans = min ( ans , get ( j , dis[n][j][0] ) );
		if ( dis[n][j][1] != 0x3f3f3f3f )
			ans = min ( ans , get ( j , dis[n][j][1] ) );
		//printf ( "%d %d\n" , ans , j );
	}
	if ( ans != 2147483647 ) {
		printf ( "%d\n" , ans % mod );
	}
	else {
		//printf ( "%d %d\n" , far[n][0].first , far[n][0].second );
		//printf ( "%d %d\n" , far[n][1].first , far[n][1].second );
		if ( far[n][0].first < far[n][1].first ) {
			printf ( "%d\n" , get ( far[n][0].first , far[n][0].second ) );
		}
		else {
			printf ( "%d\n" , get ( far[n][1].first , far[n][1].second ) );
		}
	}
}
int main () {
	work ();
	return 0;
}