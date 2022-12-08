#include <stdio.h>
#include <algorithm>

using namespace std;

const long long NN = 5100;
struct node {
	long long v;
	node *next;
} pool[NN*2] , *g[NN];
long long top;
long long n , b;
long long c[NN] , d[NN];
long long dp[NN][NN][2];
long long tmp[NN][2];
long long siz[NN];
void add ( long long u , long long v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( long long i , long long from ) {
	long long k , l;
	siz[i] = 1;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dfs ( j -> v , i );
		if ( siz[i] == 1 ) {
			for ( k = 0 ; k <= siz[j->v] ; k++ ) {
				dp[i][k][0] = dp[j->v][k][0];
				dp[i][k][1] = dp[j->v][k][1];
			}
		}
		else {
			for ( k = 0 ; k < siz[i] + siz[j->v] ; k++ ) {
				tmp[k][0] = tmp[k][1] = 100000000000007ll;
			}
			for ( k = 0 ; k < siz[i] ; k++ ) {
				for ( l = 0 ; l <= siz[j->v] ; l++ ) {
					tmp[k+l][0] = min ( tmp[k+l][0] , dp[i][k][0] + dp[j->v][l][0] );
					tmp[k+l][1] = min ( tmp[k+l][1] , dp[i][k][1] + dp[j->v][l][1] );
					tmp[k+l][1] = min ( tmp[k+l][1] , dp[i][k][1] + dp[j->v][l][0] );
					tmp[k+l][1] = min ( tmp[k+l][1] , dp[i][k][0] + dp[j->v][l][1] );
				}
			}
			for ( k = 0 ; k < siz[i] + siz[j->v] ; k++ ) {
				dp[i][k][0] = tmp[k][0];
				dp[i][k][1] = tmp[k][1];
			}
		}
		siz[i] += siz[j->v];
	}
	if ( siz[i] == 1 ) {
		dp[i][1][0] = c[i];
		dp[i][1][1] = c[i] - d[i];
	}
	else {
		for ( k = siz[i] ; k >= 1 ; k-- ) {
			dp[i][k][0] = min ( dp[i][k][0] , dp[i][k-1][0] + c[i] );
			dp[i][k][1] = min ( dp[i][k-1][1] , dp[i][k-1][0] ) + c[i] - d[i];
		}
		dp[i][0][1] = 100000000000007ll;
	}
}
void work () {
	long long i , j , fa;
	scanf ( "%I64d%I64d" , &n , &b );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d%I64d" , &c[i] , &d[i] );
		if ( i != 1 ) {
			scanf ( "%I64d" , &fa );
			add ( i , fa ); add ( fa , i );
		}
	}
	for ( i = 1 ; i <= n ; i++ ) for ( j = 1 ; j <= n ; j++ ) {
		dp[i][j][0] = dp[i][j][1] = 100000000000007ll;
	}
	dfs ( 1 , -1 );
	for ( i = n ; i >= 0 ; i-- ) {
		if ( dp[1][i][0] <= b || dp[1][i][1] <= b ) {
			printf ( "%I64d\n" , i );
			break;
		}
	}
}
int main () {
	work ();
	return 0;
}