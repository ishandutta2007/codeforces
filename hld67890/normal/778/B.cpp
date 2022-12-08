#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

const int maxn = 5100;
int n , m;
char z[4][maxn][1200];
int op[maxn] , opa[maxn] , opb[maxn];
map < string , int > ma;
int ans1[maxn] , ans2[maxn];
int f[maxn];
int check ( int pos , int x ) {
	int i , ret = 0 , x1 , x2;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( op[i] == -2 ) {
			f[i] = z[1][i][pos] - '0';
		}
		else {
			if ( opa[i] == -1 ) x1 = x;
			else x1 = f[opa[i]];
			if ( opb[i] == -1 ) x2 = x;
			else x2 = f[opb[i]];
			if ( op[i] == 0 ) {
				f[i] = x1 & x2;
			}
			if ( op[i] == 1 ) {
				f[i] = x1 | x2;
			}
			if ( op[i] == 2 ) {
				f[i] = x1 ^ x2;
			}
		}
		//printf ( "%d %d %d %d\n" , op[i] , opa[i] , opb[i] , f[i] );
		if ( f[i] ) ret++;
	}
	return ret;
}
void work () {
	int i , t1 , t2;
	char tmp[6];
	string s;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s" , z[0][i] + 1 );
		s = z[0][i] + 1;
		ma[s] = i;
		scanf ( "%s" , tmp + 1 );
		scanf ( "%s" , z[1][i] + 1 );
		if ( z[1][i][1] == '0' || z[1][i][1] == '1' ) {
			op[i] = -2;
			continue;
		}
		if ( z[1][i][1] == '?' ) opa[i] = -1;
		else {
			s = z[1][i] + 1;
			opa[i] = ma[s];
		}
		if ( z[1][i][1] != '0' && z[1][i][1] != '1' ) {
			scanf ( "%s" , tmp + 1 );
			scanf ( "%s" , z[2][i] + 1 );
			if ( z[2][i][1] == '?' ) opb[i] = -1;
			else {
				s = z[2][i] + 1;
				opb[i] = ma[s];
			}
			if ( tmp[1] == 'A' ) op[i] = 0;
			if ( tmp[1] == 'O' ) op[i] = 1;
			if ( tmp[1] == 'X' ) op[i] = 2;
		}
	}
	for ( i = 1 ; i <= m ; i++ ) {
		t1 = check ( i , 0 );
		t2 = check ( i , 1 );
		//printf ( "%d %d\n" , t1 , t2 );
		if ( t1 == t2 ) {
			ans1[i] = ans2[i] = 0;
		}
		else {
			if ( t1 > t2 ) {
				ans1[i] = 1;
				ans2[i] = 0;
			}
			else {
				ans1[i] = 0;
				ans2[i] = 1;
			}
		}
	}
	for ( i = 1 ; i <= m ; i++ ) printf ( "%d" , ans1[i] );
	printf ( "\n" );
	for ( i = 1 ; i <= m ; i++ ) printf ( "%d" , ans2[i] );
	printf ( "\n" );
}
int main () {
	work ();
	return 0;
}