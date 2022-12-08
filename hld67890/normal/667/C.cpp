#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct node {
	char z[5];
} s[240000];
int n;
char z[120000];
int dp[120000][5];
int cnt;
int ans;
bool cmp ( node x1 , node x2 ) {
	if ( x1.z[0] != x2.z[0] ) return x1.z[0] < x2.z[0];
	if ( x1.z[1] != x2.z[1] ) return x1.z[1] < x2.z[1];
	return x1.z[2] < x2.z[2];
}
void work () {
	int i , t;
	scanf ( "%s" , z + 1 );
	n = strlen ( z + 1 );
	dp[n-2][2] = 1; dp[n-3][3] = 1;
	if ( n >= 7 ) {
		s[++cnt].z[0] = z[n-1]; s[cnt].z[1] = z[n];
	}
	if ( n >= 8 ) {
		s[++cnt].z[0] = z[n-2]; s[cnt].z[1] = z[n-1]; s[cnt].z[2] = z[n];
	}
	for ( i = n - 2 ; i >= 5 ; i-- ) {
		if ( dp[i][2] == 1 ) {
			dp[i-3][3] = 1;
			if ( i - 3 >= 5 ) {s[++cnt].z[0] = z[i-2]; s[cnt].z[1] = z[i-1]; s[cnt].z[2] = z[i];}
			t = (z[i-1]==z[i+1]) + (z[i]==z[i+2]);
			if ( t != 2 ) {
				if ( i - 2 < 5 ) continue;
				dp[i-2][2] = 1;
				s[++cnt].z[0] = z[i-1]; s[cnt].z[1] = z[i];
			}
		}
		if ( dp[i][3] == 1 ) {
			dp[i-2][2] = 1;
			if ( i - 2 >= 5 ) {s[++cnt].z[0] = z[i-1]; s[cnt].z[1] = z[i];}
			t = (z[i-2]==z[i+1]) + (z[i-1]==z[i+2]) + (z[i]==z[i+3]);
			if ( t != 3 ) {
				if ( i - 3 < 5 ) continue;
				dp[i-3][3] = 1;
				s[++cnt].z[0] = z[i-2]; s[cnt].z[1] = z[i-1]; s[cnt].z[2] = z[i];
			}
		}
	}
	sort ( s + 1 , s + 1 + cnt , cmp );
	for ( i = 1 ; i <= cnt ; i++ ) {
		if ( strcmp ( s[i].z , s[i-1].z ) != 0 ) ans++;
	}
	printf ( "%d\n" , ans );
	for ( i = 1 ; i <= cnt ; i++ ) {
		if ( strcmp ( s[i].z , s[i-1].z ) != 0 ) printf ( "%s\n" , s[i].z );
	}
}
int main () {
	work ();
	return 0;
}