#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 910000;
struct node {
	int x;
	int next[30] , fa;
} g[maxn];
int n;
queue < int > q;
int dep[maxn] , siz[maxn] , del[maxn];
char z[5];
int ans[maxn];
int stack[maxn] , top;
int getnew () {
	int t = q.front ();
	q.pop ();
	return t;
}
void add ( int u , int v , int x ) {
	g[u].next[x] = v;
	g[v].fa = u;
	g[v].x = x;
}
void solve ( int i , int id , int idd ) {
	int t;
	for ( int j = 1 ; j <= 26 ; j++ ) if ( g[idd].next[j] ) {
		if ( g[id].next[j] ) {
			del[i]++;
			solve ( i , g[id].next[j] , g[idd].next[j] );
		}
		else {
			t = getnew ();
			add ( id , t , j );
			stack[++top] = t;
			solve ( i , g[id].next[j] , g[idd].next[j] );
		}
	}
}
void dfs ( int i ) {
	int maxi = 0;
	siz[i] = 1;
	for ( int j = 1 ; j <= 26 ; j++ ) if ( g[i].next[j] ) {
		dep[g[i].next[j]] = dep[i] + 1;
		dfs ( g[i].next[j] );
		siz[i] += siz[g[i].next[j]];
		if ( siz[g[i].next[j]] > siz[maxi] ) maxi = g[i].next[j];
	}
	for ( int j = 1 ; j <= 26 ; j++ ) if ( g[i].next[j] ) {
		if ( g[i].next[j] != maxi ) {
			solve ( i , maxi , g[i].next[j] );
		}
	}
	while ( top ) {
		g[g[stack[top]].fa].next[g[stack[top]].x] = 0;
		for ( int j = 1 ; j <= 26 ; j++ ) g[stack[top]].next[j] = 0;
		g[stack[top]].fa = g[stack[top]].x = 0;
		q.push ( stack[top] );
		top--;
	}
}
void work () {
	int i , u , v , maxi , maxdep;
	scanf ( "%d" , &n );
	for ( i = n + 1 ; i <= 900000 ; i++ ) q.push ( i );
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d%s" , &u , &v , z + 1 );
		add ( u , v , z[1] - 'a' + 1 );
	}
	dep[1] = 0;
	dfs ( 1 );
	maxdep = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		ans[dep[i]]++;
		ans[dep[i]+1] += del[i];
		maxdep = max ( maxdep , dep[i] );
	}
	//for ( i = 1 ; i <= n ; i++ ) printf ( "%d %d %d\n" , i , dep[i] , del[i] );
	//for ( i = 1 ; i <= n ; i++ ) printf ( "%d %d\n" , i , ans[i] );
	maxi = 1;
	for ( i = 1 ; i <= maxdep ; i++ ) {
		if ( ans[maxi] < ans[i] ) maxi = i;
	}
	printf ( "%d\n%d\n" , n - ans[maxi] , maxi );
}
int main () {
	//FILE *fpr = freopen ( "c.in" , "r" , stdin );
	work ();
	return 0;
}