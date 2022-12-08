#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

//long long
const long long maxn = 3100;
long long n , m;
long long now;
long long a[maxn][maxn] , tot[maxn];
priority_queue < long long > q;
long long ans;
long long check ( long long x ) {
	long long i , j , ret = 0 , nx;
	nx = now;
	while ( q.size () ) q.pop ();
	for ( i = 2 ; i <= m ; i++ ) {
		//printf ( "%I64d %I64d\n" , i,tot[i]-x );
		for ( j = 1 ; j <= tot[i] - x + 1 ; j++ ) {
			ret += a[i][j];
			nx++;
		}
		for ( j ; j <= tot[i] ; j++ ) q.push ( -a[i][j] );
	}
	while ( nx < x ) {
		nx++;
		ret += -q.top ();
		q.pop ();
	}
	return ret;
}
void work () {
	long long i , x , y;
	scanf ( "%I64d%I64d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d%I64d" , &x , &y );
		a[x][++tot[x]] = y;
	}
	for ( i = 1 ; i <= m ; i++ ) {
		sort ( a[i] + 1 , a[i] + 1 + tot[i] );
	}
	ans = 21474836477777777ll;
	now = tot[1];
	for ( i = now ; i <= n ; i++ ) {
		ans = min ( ans , check ( i ) );
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}