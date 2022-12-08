#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	long long a , b;
} dis[20000];
long long n , x1 , y1 , x2 , y2 , x[20000] , y[20000];
bool cmp ( node a , node b ) {
	return a.a < b.a;
}
void work () {
	int i , j;
	long long ans = (1ll<<62) , maxx;
	scanf ( "%I64d%I64d%I64d%I64d%I64d" , &n , &x1 , &y1 , &x2 , &y2 );
	for ( i = 1; i <= n ; i++ ) {
		scanf ( "%I64d%I64d" , &x[i] , &y[i] );
		dis[i].a = (x1-x[i])*(x1-x[i]) + (y1-y[i])*(y1-y[i]);
		dis[i].b = (x2-x[i])*(x2-x[i]) + (y2-y[i])*(y2-y[i]);
	}
	sort ( dis + 1 , dis + 1 + n , cmp );
	for ( i = 0 ; i <= n ; i++ ) {
		maxx = 0;
		for ( j = i + 1 ; j <= n ; j++ ) maxx = max ( maxx , dis[j].b );
		ans = min ( ans , maxx + dis[i].a );
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}