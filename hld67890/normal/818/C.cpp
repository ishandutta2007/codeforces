#include <stdio.h>
#include <algorithm>

using namespace std;

const int DD = 120000;
struct point {
	int x , y , i;
} s[DD*2];
int d;
int x1[DD] , y1[DD] , x2[DD] , y2[DD];
int exist[DD];
int needl , needr , needt , needb;
int cntl[DD] , cntr[DD] , cntt[DD] , cntb[DD];
int ans;
bool cmp1 ( point x1 , point x2 ) {
	return x1.x < x2.x;
}
bool cmp2 ( point x1 , point x2 ) {
	return x1.x > x2.x;
}
bool cmp3 ( point x1 , point x2 ) {
	return x1.y < x2.y;
}
bool cmp4 ( point x1 , point x2 ) {
	return x1.y > x2.y;
}
void work () {
	int i , cnt , tcnt , a , b;
	scanf ( "%d" , &d );
	scanf ( "%d%d" , &a , &b );
	for ( i = 1 ; i <= d ; i++ ) {
		scanf ( "%d%d%d%d" , &x1[i] , &y1[i] , &x2[i] , &y2[i] );
		s[i*2-1].x = x1[i];
		s[i*2-1].y = y1[i];
		s[i*2-1].i = i;
		s[i*2].x = x2[i];
		s[i*2].y = y2[i];
		s[i*2].i = i;
	}
	scanf ( "%d%d%d%d" , &needl , &needr , &needt , &needb );
	for ( i = 1 ; i <= d ; i++ ) {
		if ( x1[i] == x2[i] ) {
			cntt[i]--; cntb[i]--;
		}
		else {
			cntl[i]--; cntr[i]--;
		}
	}
	
	for ( i = 1 ; i <= d ; i++ ) exist[i] = 0;
	cnt = tcnt = 0;
	sort ( s + 1 , s + 1 + d + d , cmp1 );
	for ( i = 1 ; i <= d * 2 ; i++ ) {
		if ( i != 1 && s[i-1].x != s[i].x ) {
			cnt += tcnt;
			tcnt = 0;
		}
		if ( exist[s[i].i] ) {
			cntl[s[i].i] += cnt;
		}
		else {
			exist[s[i].i] = 1;
			tcnt++;
		}
	}
	
	for ( i = 1 ; i <= d ; i++ ) exist[i] = 0;
	cnt = tcnt = 0;
	sort ( s + 1 , s + 1 + d + d , cmp2 );
	for ( i = 1 ; i <= d * 2 ; i++ ) {
		if ( i != 1 && s[i-1].x != s[i].x ) {
			cnt += tcnt;
			tcnt = 0;
		}
		if ( exist[s[i].i] ) {
			cntr[s[i].i] += cnt;
		}
		else {
			exist[s[i].i] = 1;
			tcnt++;
		}
	}
	
	for ( i = 1 ; i <= d ; i++ ) exist[i] = 0;
	cnt = tcnt = 0;
	sort ( s + 1 , s + 1 + d + d , cmp3 );
	for ( i = 1 ; i <= d * 2 ; i++ ) {
		if ( i != 1 && s[i-1].y != s[i].y ) {
			cnt += tcnt;
			tcnt = 0;
		}
		if ( exist[s[i].i] ) {
			cntt[s[i].i] += cnt;
		}
		else {
			exist[s[i].i] = 1;
			tcnt++;
		}
		//printf ( "  %d %d %d %d\n" , s[i].x , s[i].y , s[i].i , cnt );
	}
	
	for ( i = 1 ; i <= d ; i++ ) exist[i] = 0;
	cnt = tcnt = 0;
	sort ( s + 1 , s + 1 + d + d , cmp4 );
	for ( i = 1 ; i <= d * 2 ; i++ ) {
		if ( i != 1 && s[i-1].y != s[i].y ) {
			cnt += tcnt;
			tcnt = 0;
		}
		if ( exist[s[i].i] ) {
			cntb[s[i].i] += cnt;
		}
		else {
			exist[s[i].i] = 1;
			tcnt++;
		}
	}
	ans = 0;
	for ( i = 1 ; i <= d ; i++ ) {
		//printf ( "%d %d %d %d\n" , cntl[i] , cntr[i] , cntt[i] , cntb[i] );
		if ( needl == cntl[i] && needr == cntr[i] && needt == cntt[i] && needb == cntb[i] ) ans = i;
	}
	if ( ans == 0 ) printf ( "-1\n" );
	else printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}