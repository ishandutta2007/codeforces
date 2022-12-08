#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 210000;
int n , k;
char s[maxn];
int next[maxn];
int st[maxn] , tops;
int ans[maxn];
void work () {
	int i , tmp;
	scanf ( "%d%d" , &n , &k );
	scanf ( "%s" , s + 1 );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( s[i] == '(' ) {
			st[++tops] = i;
		}
		else {
			next[st[tops]] = i;
			tops--;
		}
	}
	tmp = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( tmp != k && s[i] == '(' ) {
			ans[i] = 1;
			ans[next[i]] = 1;
			tmp += 2;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( ans[i] == 1 ) printf ( "%c" , s[i] );
	}
	printf ( "\n" );
}
int main () {
	work ();
	return 0;
}