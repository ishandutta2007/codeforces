#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 220000;
const double eps = 1e-9;
long long n , sy , a , b , q;
long long l[maxn] , r[maxn];
long long sum[maxn];
double ans;
void work () {
	long long i ,  le , ri , mid , x , y , x1 , x2;
	double px1 , px2;
	scanf ( "%I64d%I64d%I64d" , &sy , &a , &b );
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d%I64d" , &l[i] , &r[i] );
		sum[i] = sum[i-1] + r[i] - l[i];
	}
	scanf ( "%I64d" , &q );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%I64d%I64d" , &x , &y );
		if ( a == x ) px1 = x;
		else {
			px1 = -(double(y))*double(a-x)/(double(sy-y)) + x;
		}
		if ( b == x ) px2 = x;
		else {
			px2 = -(double(y))*(double(b-x))/(double(sy-y)) + x;
		}
		if ( px1 > r[n] || px2 < l[1] ) {
			printf ( "%.9lf\n" , 0.0 );
			continue;
		}
		le = 1; ri = n;
		while ( le < ri - 1 ) {
			mid = (le+ri)/2;
			if ( r[mid] <= px1 - eps ) le = mid;
			else ri = mid;
		}
		if ( r[le] >= px1 - eps ) x1 = le;
		else x1 = ri;
		//printf ( "##%I64d %lf\n" , ri , px1 );
		//printf ( "%I64d %I64d\n" , x1 , x2 );
		le = 1; ri = n;
		while ( le < ri - 1 ) {
			mid = (le+ri)/2;
			if ( l[mid] <= px2 - eps ) le = mid;
			else ri = mid;
		}
		if ( l[ri] <= px2 - eps ) x2 = ri;
		else x2 = le;
		if ( x1 > x2 ) {
			printf ( "%.9lf\n" , 0.0 );
			continue;
		}
		ans = (double(sum[x2]-sum[x1-1])) * (double(y-sy) ) / (double(y));
		if ( px1 > l[x1] ) ans -= (double(px1-l[x1])) * (double(y-sy) ) / (double(y));
		if ( px2 < r[x2] ) ans -= (double(r[x2]-px2)) * (double(y-sy) ) / (double(y));
		printf ( "%.9lf\n" , ans );
	}
}
int main () {
	work ();
	return 0;
}