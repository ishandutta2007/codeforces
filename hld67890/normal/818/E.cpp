#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long NN = 120000;
long long n , k;
long long a[NN];
long long pk[50] , tk[50] , cnt;
long long ta[NN][40];
long long now[40] , left;
long long ans;
void work () {
	long long i , j , next;
	scanf ( "%I64d%I64d" , &n , &k );
	for ( i = 2 ; i * i <= k ; i++ ) {
		if ( k % i == 0 ) {
			cnt++;
			pk[cnt] = i;
			while ( k % i == 0 ) {
				k = k / i;
				tk[cnt]++;
			}
		}
	}
	if ( k != 1 ) {
		pk[++cnt] = k;
		tk[cnt] = 1;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= cnt ; j++ ) {
			while ( a[i] % pk[j] == 0 ) {
				a[i] = a[i] / pk[j];
				ta[i][j]++;
			}
		}
	}
	next = 0;
	left = cnt;
	for ( i = 1 ; i <= n ; i++ ) {
		while ( (next < i || left) && next < n ) {
			for ( j = 1 ; j <= cnt ; j++ ) {
				now[j] += ta[next+1][j];
				if ( now[j] - ta[next+1][j] < tk[j] && now[j] >= tk[j] ) {
					left--;
				}
			}
			next++;
		}
		if ( next == n && left ) break;
		ans += (long long)(n-next+1);
		//printf ( "%I64d\n" , next );
		for ( j = 1 ; j <= cnt ; j++ ) {
			now[j] -= ta[i][j];
			if ( now[j] < tk[j] && now[j] + ta[i][j] >= tk[j] ) {
				left++;
			}
		}
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}