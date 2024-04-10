#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int n , k;
int f[2200000];
double p[120] , dp[2200000] , ans[30] , s;
queue < int > q;
void work () {
	int i , j , t , sum , ok;
	scanf ( "%d%d" , &n , &k );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%lf" , &p[i] );
	dp[0] = 1; f[0] = 1;
	q.push ( 0 );
	while ( q.size () != 0 ) {
		t = q.front (); q.pop ();
		f[t] = 0; s = 1;
		i = t; j = 1;
		while ( i ) {
			if ( i % 2 ) s -= p[j];
			i >>= 1; j++;
		}
		if ( s == 0 ) continue;
		for ( i = 1 ; i <= n ; i++ ) {
			//cout << t << " " << (1<<(i-1)) << endl;
			if ( (t & (1<<(i-1))) == 0 ) {
				dp[t|(1<<(i-1))] += dp[t] * (p[i]/s);
				if ( !f[t|(1<<(i-1))] ) q.push ( t | (1<<(i-1)) );
				f[t|(1<<(i-1))] = 1;
			}
		}
	}
	ok = 0;
	for ( i = 1 ; i <= n ; i++ ) if ( p[i] != 0 ) ok++;
	k = min ( k , ok );
	for ( i = 0 ; i < (1<<n) ; i++ ) {
		t = i; sum = 0;
		while ( t ) {
			if ( t % 2 ) sum++;
			t >>= 1;
		}
		//cout << i << " " << sum << " " << dp[i] << endl;
		if ( sum == k ) {
			t = i; j = 1;
			while ( t ) {
				if ( t % 2 ) {
					ans[j] += dp[i];
				}
				t >>= 1; j++;
			}
			s += dp[i];
		}
	}
	for ( i = 1 ; i < n ; i++ ) printf ( "%lf " , ans[i] / s );
	printf ( "%lf\n" , ans[i] / s );
}
int main () {
	work ();
	return 0;
}