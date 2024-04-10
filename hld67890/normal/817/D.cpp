#include <stdio.h>
#include <algorithm>

using namespace std;

const long long NN = 1200000;
long long n;
long long a[NN] , pre[3][NN] , next[3][NN];
long long s[NN] , tops;
long long ans;
void work () {
	long long i;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		while ( tops && a[s[tops]] < a[i] ) {
			next[0][s[tops]] = i;
			tops--;
		}
		pre[0][i] = s[tops];
		s[++tops] = i;
	}
	for ( i = 1 ; i <= n ; i++ ) if ( next[0][i] == 0 ) next[0][i] = n + 1;
	tops = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		while ( tops && a[s[tops]] > a[i] ) {
			next[1][s[tops]] = i;
			tops--;
		}
		pre[1][i] = s[tops];
		s[++tops] = i;
	}
	for ( i = 1 ; i <= n ; i++ ) if ( next[1][i] == 0 ) next[1][i] = n + 1;
	for ( i = 1 ; i <= n ; i++ ) {
		ans += a[i] * (i-(pre[0][i]+1)+1) * (next[0][i]-1-i+1);
		ans -= a[i] * (i-(pre[1][i]+1)+1) * (next[1][i]-1-i+1);
	}
	//for ( i = 1 ; i <= n ; i++ ) printf ( "%I64d %I64d\n" , pre[1][i] , next[1][i] );
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}