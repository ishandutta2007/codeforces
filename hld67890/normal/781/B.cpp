#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 1200;
int n;
char z[4][maxn][100];
int f[600000];
int num[1000][1200];
int ans[maxn];
int flag , ff;
void work () {
	int i , j , k , l , tmp , t , mask , tk , mask1 , mask2;
	scanf ( "%d" , &n );
	flag = 1;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s%s" , z[1][i] + 1 , z[2][i] + 1 );
		tmp = (z[1][i][1] - 'A') * 30 + (z[1][i][2] - 'A');
		f[tmp]++;
		num[tmp][++num[tmp][0]] = i;
		if ( f[tmp] >= 27 ) flag = 0;
	}
	if ( flag == 0 ) {
		printf ( "NO\n" );
		return ;
	}
	ff = 1;
	for ( i = 0 ; i < 26 ; i++ ) for ( j = 0 ; j < 26 ; j++ ) {
		if ( ff == 0 ) break;
		tmp = i*30+j;
		if ( num[tmp][0] ) {
			t = (1<<num[tmp][0]) - 1;
			for ( k = t ; k >= 0 ; k-- ) {
				//printf ( "%d\n" , k );
				mask = 0; tk = k; flag = 1; mask1 = 0; mask2 = 0;
				for ( l = 1 ; l <= num[tmp][0] ; l++ ) {
					//printf ( "%d %d %d\n" , mask , mask1 , mask2 );
					if ( tk % 2 == 0 ) {
						if ( mask1 & (1<<(z[1][num[tmp][l]][3]-'A')) ) {
							flag = 0;
							break;
						}
						if ( mask & (1<<(z[1][num[tmp][l]][3]-'A')) ) {
							flag = 0;
							break;
						}
						else mask |= (1<<(z[1][num[tmp][l]][3]-'A'));
						mask2 |= (1<<(z[1][num[tmp][l]][3]-'A'));
					}
					else {
						if ( mask2 & (1<<(z[1][num[tmp][l]][3]-'A')) ) {
							flag = 0;
							break;
						}
						if ( mask & (1<<(z[2][num[tmp][l]][1]-'A')) ) {
							flag = 0;
							break;
						}
						else mask |= (1<<(z[2][num[tmp][l]][1]-'A'));
						mask1 |= (1<<(z[1][num[tmp][l]][3]-'A'));
					}
					tk >>= 1;
				}
				//printf ( "##%d\n" , flag );
				if ( flag == 1 ) {
					tk = k;
					for ( l = 1 ; l <= num[tmp][0] ; l++ ) {
						if ( tk % 2 == 0 ) ans[num[tmp][l]] = 0;
						else ans[num[tmp][l]] = 1;
						tk >>= 1;
					}
					break;
				}
			}
			if ( k == -1 ) ff = 0;
		}
	}
	if ( ff == 0 ) {
		printf ( "NO\n" );
		return ;
	}
	else {
		printf ( "YES\n" );
		for ( i = 1 ; i <= n ; i++ ) printf ( "%c%c%c\n" , z[1][i][1] , z[1][i][2] , ans[i]==0?z[1][i][3]:z[2][i][1] );
	}
}
int main () {
	work ();
	return 0;
}