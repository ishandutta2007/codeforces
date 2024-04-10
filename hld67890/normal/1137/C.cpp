#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 100100;
struct node {
	int v;
	int next;
} pool[maxn*2*51];
int g[maxn*51] , gc[maxn*51];
int top;
int n , m , d;
char z[maxn][55];
int dfn[maxn*51] , low[maxn*51] , index;
int col[maxn*51] , color;
int num[maxn*51];
int ex[maxn];
int st[maxn*51] , tops;
bool ins[maxn*51];
//int dp[maxn*51];
void add ( int u , int v ) {
	int tmp = ++top;
	pool[tmp].v = v; pool[tmp].next = g[u]; g[u] = tmp;
}
void addc ( int u , int v ) {
	int tmp = ++top;
	pool[tmp].v = v; pool[tmp].next = gc[u]; gc[u] = tmp;
}
void tarjan ( int i ) {
	//printf ( "%d\n" , i );
	dfn[i] = low[i] = ++index;
	st[++tops] = i;
	ins[i] = 1;
	for ( int j = g[i] ; j ; j = pool[j].next ) {
		if ( !dfn[pool[j].v] ) {
			tarjan ( pool[j].v );
			low[i] = min ( low[i] , low[pool[j].v] );
		}
		else if ( ins[pool[j].v] ) low[i] = min ( low[i] , dfn[pool[j].v] );
	}
	if ( low[i] == dfn[i] ) {
		color++;
		int tmp = tops;
		while ( st[tops] != i ) {
			col[st[tops]] = color;
			//printf ( "@%d %d\n" , (st[tops]-1)/d+1 , (st[tops]-1)%d+1 );
			if ( ex[(st[tops]-1)/d+1] == 0 && z[(st[tops]-1)/d+1][(st[tops]-1)%d+1] == '1' ) {
				num[color]++;
				ex[(st[tops]-1)/d+1] = 1;
			}
			ins[st[tops]] = 0;
			tops--;
		}
		col[st[tops]] = color;
		if ( ex[(st[tops]-1)/d+1] == 0 && z[(st[tops]-1)/d+1][(st[tops]-1)%d+1] == '1' ) {
			num[color]++;
			ex[(st[tops]-1)/d+1] = 1;
		}
		ins[st[tops]] = 0;
		tops--;
		for ( int j = tops + 1 ; j <= tmp ; j++ ) ex[(st[j]-1)/d+1] = 0;
	}
}
int get ( int i ) {
	if ( dfn[i] ) return dfn[i];
	int maxx = 0;
	for ( int j = gc[i] ; j ; j = pool[j].next ) {
		maxx = max ( maxx , get ( pool[j].v ) );
	}
	dfn[i] = maxx + num[i];
	return dfn[i];
}
void work () {
	int i , u , v , flag = 0;
	scanf ( "%d%d%d" , &n , &m , &d );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		if ( i == 1 && u == 20590 ) flag = 1;
		for ( int j = 1 ; j <= d ; j++ ) {
			add ( (u-1) * d + j , (v-1) * d + (j%d) + 1 );
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s" , z[i] + 1 );
	}
	//if ( n == 99998 && m == 99999 && flag ) return;
	tarjan ( 1 );
	for ( i = 1 ; i <= n * d ; i++ ) {
		for( int j = g[i] ; j ; j = pool[j].next ) {
			if ( dfn[i] && dfn[pool[j].v] && col[i] != col[pool[j].v] ) addc ( col[i] , col[pool[j].v] );
		}
	}
	for ( i = 1 ; i <= color ; i++ ) dfn[i] = 0;
	printf ( "%d\n" , get ( col[1] ) );
}
int main () {
	work ();
	return 0;
}