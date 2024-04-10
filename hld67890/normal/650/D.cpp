#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	int x , i , l , r , num;
} s[500000];
int n , m;
int a[500000] , t[500000] , top , le[500000] , ri[500000] , c[500000] , d[500000];
int ans[500000];
bool cmp ( node x1 , node x2 ) {
	return x1.i < x2.i;
}
bool cmp1 ( int x , int y , int k ) {
	if ( k == 1 ) return x < y;
	return x > y;
}
int find ( int x , int k ) {
	int l , r , mid;
	l = 1 ; r = top + 1; t[r] = 2147483647 * (1-k);
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		if ( cmp1 ( x , t[mid] , k ) == true ) l = mid;
		else r = mid;
	}
	if ( cmp1 ( x , t[l] , k ) == true ) {
		t[top + 1] = 0;
		return r;
	}
	t[top + 1] = 0;
	return l;
}
void work () {
	int i , j , x;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &s[i].i , &s[i].x );
		s[i].num = i;
	}
	sort ( s + 1 , s + 1 + m , cmp );
	s[0].i = -1; s[m+1].i = n + 1;
	j = 1;
	for ( i = 1 ; i <= n ; i++ ) {
		while ( s[j].i == i ) {
			s[j].l = find ( s[j].x , 0 );
			j++;
		}
		x = find ( a[i] , 0 );
		le[i] = x;
		t[x] = a[i];
		if ( x > top ) top++;
		//for ( int l = 1 ; l <= top ; l++ ) cout << t[l] << " ";
		//cout << endl << "@$#  " << top << endl;
	}
	for ( i = 1 ; i <= top ; i++ ) t[i] = 0;
	top = 0; j = m;
	for ( i = n ; i >= 1 ; i-- ) {
		while ( s[j].i == i ) {
			s[j].r = find ( s[j].x , 1 ) ;
			j--;
		}
		x = find ( a[i] , 1 );
		ri[i] = x;
		t[x] = a[i];
		if ( x > top ) top++;
	}
	for ( i = 1 ; i <= n ; i++ ) if ( le[i] + ri[i] - 1 == top ) c[le[i]]++;
	for ( i = 1 ; i <= n ; i++ ) if ( le[i] + ri[i] - 1 == top ) d[i] = c[le[i]] == 1;
	//cout << top << endl;
	//for ( i = 1 ; i <= n ; i++ ) cout << d[i] << " ";
	//cout << endl;
	//for ( i = 1 ; i <= n ; i++ ) cout << c[i] << " ";
	//cout << endl;
	//for ( i = 1 ; i <= m ; i++ ) cout << s[i].x << " " << s[i].i << " " << s[i].l << " " << s[i].r << endl;
	for ( i = 1 ; i <= m ; i++ ) ans[s[i].num] = max ( top - d[s[i].i] , s[i].l + s[i].r - 1 );
	for ( i = 1 ; i <= m ; i++ ) printf ( "%d\n" , ans[i] );
}
int main () {
	work ();
	return 0;
}