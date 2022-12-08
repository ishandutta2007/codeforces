#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
int n;
int h[320000];
int s1[420000];
int s2[420000];
int top1 , top2;
int dp[420000];
void work () {
	int i , lst;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &h[i] );
	}
	dp[1] = 0;
	s1[1] = s2[1] = 1;
	top1 = top2 = 1;
	for ( i = 2 ; i <= n ; i++ ) {
		dp[i] = dp[i-1] + 1;
		lst = -1;
		while ( top1 && h[s1[top1]] >= h[i] ) {
			dp[i] = min ( dp[i] , dp[s1[top1]] + 1 );
			lst = h[s1[top1]];
			top1--;
		}
		if ( top1 && lst != h[i] ) dp[i] = min ( dp[i] , dp[s1[top1]] + 1 );
		s1[++top1] = i;
		
		lst = -1;
		while ( top2 && h[s2[top2]] <= h[i] ) {
			dp[i] = min ( dp[i] , dp[s2[top2]] + 1 );
			lst = h[s2[top2]];
			top2--;
		}
		if ( top2 && lst != h[i] ) dp[i] = min ( dp[i] , dp[s2[top2]] + 1 );
		s2[++top2] = i;
		
		//printf ( "%d %d %d\n" , dp[i] , top1 , top2 );
	}
	printf ( "%d\n" , dp[n] );
}
int main () {
	work ();
	return 0;
}