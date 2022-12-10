#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int maxn = 220000;
int n , k;
int t[maxn];
int gap[maxn] , tot;
int ans;
void work () {
	int i , l , f , first;
	int k1 , ans1;
	scanf ( "%d%d" , &n , &k );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &t[i] );
	f = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( t[i] < 0 ) {
			t[i] = -1;
			k--;
			f = 1;
		}
		else t[i] = 1;
	}
	for ( i = 1 ; i <= n ; i++ ) if ( t[i] == -1 ) {
		first = i;
		break;
	}
	if ( k < 0 ) {
		printf ( "-1\n" );
		return ;
	}
	if ( f == 0 ) {
		printf ( "0\n" );
		return ;
	}
	tot = 0; l = 0;
	for ( i = first ; i <= n ; i++ ) {
		if ( i == first && t[i] == -1 ) {
			ans++;
			continue;
		}
		if ( t[i] == -1 && t[i - 1] == 1 ) {
			gap[++tot] = l;
			l = 0;
			ans++;
		}
		else {
			if ( t[i] == 1 ) l++;
			if ( t[i] == 1 && t[i-1] == -1 ) ans++;
		}
	}
	sort ( gap + 1 , gap + 1 + tot );
	ans1 = 999999999;
	if ( t[n] == 1 ) {
		if ( k >= l ) {
			k1 = k - l;
			ans1 = ans;
			ans1--;
			for ( i = 1 ; i <= tot ; i++ ) if ( k1 >= gap[i] ) {
				k1 -= gap[i];
				ans1 -= 2;
			}
		}
	}
	//printf ( "%d\n" , ans );
	for ( i = 1 ; i <= tot ; i++ ) if ( k >= gap[i] ) {
		k -= gap[i];
		ans -= 2;
	}
	//for ( i = 1 ; i <= tot ; i++ ) printf ( "%d " , gap[i] );
	printf ( "%d\n" , min ( ans , ans1 ) );
}
int main () {
	work ();
	return 0;
}