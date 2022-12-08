#include <stdio.h>
#include <algorithm>

using namespace std;

int n , x , y;
int bit[20];
int cnt;
int ans1 , ans2;
void work () {
	int i , j , t , ret , pos;
	scanf ( "%d%d%d" , &n , &x , &y );
	for ( i = 0 ; i <= 9 ; i++ ) {
		if ( n >= (1<<i) ) {
			cnt = 0;
			for ( j = 1 ; j <= n ; j++ ) {
				if ( j & (1<<i) ) cnt++;
			}
			if ( cnt != 0 ) {
				printf ( "? %d" , cnt );
				for ( j = 1 ; j <= n ; j++ ) {
					if ( j & (1<<i) ) printf ( " %d" , j );
				}
				printf ( "\n" );
				fflush(stdout);
				scanf ( "%d" , &ret );
			}
			if ( cnt % 2 == 0 ) t = x;
			else t = 0;
			t ^= y;
			if ( t == ret ) bit[i] = 1;
			else bit[i] = 0;
		}
	}
	for ( i = 1 ; i <= 9 ; i++ ) {
		if ( bit[i] == 1 ) {
			pos = i;
			break;
		}
	}
	ans1 |= (1<<pos);
	for ( i = 0 ; i <= 9 ; i++ ) {
		if ( i == pos ) continue;
		if ( n >= (1<<i) ) {
			cnt = 0;
			for ( j = 1 ; j <= n ; j++ ) {
				if ( (j & (1<<i)) != 0 && (j&(1<<pos)) != 0 ) cnt++;
			}
			if ( cnt != 0 ) {
				printf ( "? %d" , cnt );
				for ( j = 1 ; j <= n ; j++ ) {
					if ( (j & (1<<i)) != 0 && (j&(1<<pos)) != 0 ) printf ( " %d" , j );
				}
				printf ( "\n" );
				fflush(stdout);
				scanf ( "%d" , &ret );
			}
			else {
				ret = 0;
			}
			if ( cnt % 2 == 0 ) t = x;
			else t = 0;
			t ^= y;
			if ( bit[i] == 0 ) {
				if ( t == ret ) {
					ans1 |= (1<<i);
					ans2 |= (1<<i);
				}
			}
			else {
				if ( t == ret ) {
					ans1 |= (1<<i);
				}
				else {
					ans2 |= (1<<i);
				}
			}
		}
	}
	if ( ans1 > ans2 ) swap ( ans1 , ans2 );
	printf ( "! %d %d\n" , ans1 , ans2 );
	fflush(stdout);
}
int main () {
	work ();
	return 0;
}