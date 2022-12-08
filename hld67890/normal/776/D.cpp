#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 120000;
int n , m;
int a[maxn] , c[maxn*2];
int f[maxn];
int l[maxn] , r[maxn];
int fi[maxn] , se[maxn];
int check ( int x , int flag ) {
	f[x] = flag;
	int other;
	//printf ( "   %d %d\n" , x , flag );
	//for ( int i = 1 ; i <= m ; i++ ) printf ( "%d " , f[i] );
	//printf ( "\n" );
	for ( int i = l[x] ; i <= r[x] ; i++ ) {
		if ( fi[c[i]] == x ) other = se[c[i]];
		else other = fi[c[i]];
		//printf ( "##%d %d %d %d\n" , x , i , other , f[other] );
		if ( f[other] == -1 ) {
			//printf ( "##%d %d %d\n" , x , other);
			if ( check ( other , 1 ^ a[c[i]] ^ flag ) == 0 ) {
				f[x] = -1;
				return 0;
			}
		}
		else {
			//printf ( "%d %d %d %d %d\n" , x , i , a[c[i]] , flag , f[other] );
			if ( a[c[i]] ^ flag ^ f[other] != 1 ) {
				f[x] = -1;
				return 0;
			}
		}
	}
	return 1;
}
void work () {
	int i , j , now , x;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	now = 0;
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d" , &x );
		l[i] = now + 1; r[i] = now + x;
		for ( j = l[i] ; j <= r[i] ; j++ ) {
			scanf ( "%d" , &c[j] );
			if ( fi[c[j]] ) se[c[j]] = i;
			else fi[c[j]] = i;
		}
		now = r[i];
	}
	//for ( i = 1 ; i <= n ; i++ ) printf ( "%d %d\n" , fi[i] , se[i] );
	for ( i = 1 ; i <= m ; i++ ) f[i] = -1;
	for ( i = 1 ; i <= m ; i++ ) {
		if ( f[i] == -1 ) {
			//printf ( "####\n" );
			if ( check ( i , 0 ) == 0 && check ( i , 1 ) == 0 ) {
				printf ( "NO\n" );
				return ;
			}
		}
	}
	//for ( i = 1 ; i <= m ; i++ ) printf ( "%d\n" , f[i] );
	printf ( "YES\n" );
}
int main () {
	work ();
	return 0;
}