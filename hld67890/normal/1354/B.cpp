#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
char z[220000];
int pre[5][220000];
int ans;
void work () {
	int i , j , mx , mn;
	scanf ( "%s" , z + 1 );
	n = strlen ( z + 1 );
	pre[1][0] = pre[2][0] = pre[3][0] = -1;
	ans = 21111111;
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= 3 ; j++ )
			pre[j][i] = pre[j][i-1];
		pre[z[i]-'0'][i] = i;
		mx = max ( pre[1][i] , max ( pre[2][i] , pre[3][i] ) );
		mn = min ( pre[1][i] , min ( pre[2][i] , pre[3][i] ) );
		if ( mn != -1 ) ans = min ( ans , mx - mn + 1 );
	}
	if ( ans == 21111111 ) ans = 0;
	printf ( "%d\n" , ans );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}