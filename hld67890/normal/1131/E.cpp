#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 120000;
struct node {
	int l , r , same , ans[30];
	char lc , rc;
} s[maxn];
int n;
char z[maxn];
int ans;
node operator * ( node x1 , node x2 ) {
	node y;
	int i , tmp;
	if ( x1.same == 1 && x2.same == 1 && x1.lc == x2.lc ) {
		for ( i = 0 ; i <= 26 ; i++ ) y.ans[i] = 0;
		y.l = y.r = y.ans[x1.lc-'a'] = (x1.ans[x1.lc-'a']+1) * x2.ans[x1.lc-'a'] + x1.ans[x1.lc-'a'];
		y.lc = y.rc = x1.lc;
		y.same = 1;
		return y;
	}
	else {
		y.same = 0;
		y.lc = x2.lc;
		y.rc = x2.rc;
		if ( x2.same == 1 ) {
			if ( x1.lc == x2.lc ) {
				y.l = (x1.l+1) * x2.l + x1.l;
			}
			else {
				y.l = x2.l;
			}
			if ( x1.rc == x2.rc ) {
				y.r = (x1.r+1) * x2.r + x1.r;
			}
			else {
				y.r = x2.r;
			}
		}
		else {
			y.l = x2.l;
			y.r = x2.r;
		}
		for ( i = 0 ; i <= 25 ; i++ ) {
			y.ans[i] = max ( (x1.ans[i]!=0?1:0) , x2.ans[i] );
			if ( x1.ans[i] != 0 ) {
				tmp = 1;
				if ( x2.lc == i + 'a' ) tmp += x2.l;
				if ( x2.rc == i + 'a' ) tmp += x2.r;
				y.ans[i] = max ( y.ans[i] , tmp );
				if ( x2.same == 1 && x2.lc == i + 'a' ) {
					y.ans[i] = max ( y.ans[i] , (x1.ans[i]+1) * x2.ans[i] + x1.ans[i] );
				}
			}
		}
	}
	return y;
}
void work () {
	int i , j , l , k;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s" , z + 1 );
		l = strlen ( z + 1 ) ;
		s[i].lc = z[1];
		s[i].rc = z[l];
		for ( j = 1 ; j <= l ; j++ ) {
			if ( z[j] != z[1] ) break;
		}
		j--;
		s[i].l = j;
		for ( j = l ; j >= 1 ; j-- ) {
			if ( z[j] != z[l] ) break;
		}
		j++;
		s[i].r = l - j + 1;
		if ( s[i].l == l ) s[i].same = 1;
		else s[i].same = 0;
		k = 0;
		z[0] = '0';
		for ( j = 1 ; j <= l ; j++ ) {
			if ( z[j] != z[j-1] ) {
				if ( j != 1 ) s[i].ans[z[j-1]-'a'] = max ( s[i].ans[z[j-1]-'a'] , k );
				k = 1;
			}
			else k++;
		}
		s[i].ans[z[l]-'a'] = max ( s[i].ans[z[l]-'a'] , k );
	}
	for ( i = 2 ; i <= n ; i++ ) {
		s[1] = s[1] * s[i];
		//printf ( "%d %d %d %c %c %d %d %d\n" , s[1].l , s[1].r , s[1].same , s[1].lc , s[1].rc , s[1].ans[0] , s[1].ans[1] , s[1].ans['n'-'a'] );
	}
	ans = 0;
	for ( i = 0 ; i <= 25 ; i++ ) {
		ans = max ( ans , s[1].ans[i] );
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}