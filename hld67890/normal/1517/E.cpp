#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long mod = 998244353;
long long n;
long long a[220000] , tot;
long long par[220000] , pre[220000];
long long le , ri , p , c;
long long ans;
void clear () {
	long long i;
	for ( i = 1 ; i <= n ; i++ ) {
		par[i] = pre[i] = 0;
	}
	tot = le = ri = ans = 0;
}
long long get ( long long l , long long r ) {
	if ( l <= 1 ) l = 2;
	return par[r] - par[l-2];
}
long long check ( long long x , long long i , long long del ) {
	//printf ( "check %lld %lld %lld\n" , x , i +p, get (le,le+x*2) );
	if ( (pre[i+p] + get(le+2,le+x*2)+del)*2 < tot ) return 1;
	return 0;
}
void work () {
	long long i , l , r , mid;
	scanf ( "%lld" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &a[i] );
		tot += a[i];
		pre[i] = pre[i-1] + a[i];
		if ( i <= 2 ) par[i] = a[i];
		else par[i] = par[i-2] + a[i];
	}
	ans = 0;
	for ( p = 0 ; p <= 1 ; p++ )
	for ( c = 0 ; c <= 1 ; c++ )
	for ( i = p * 2 ; i <= n ; i++ ) {
		if ( p + i + 3 * c > n ) continue;
		le = i + p;
		if ( (n-3*c-le) % 2 == 1 ) ri = n - c * 3 - 1;
		else ri = n - c * 3;
		//printf ( "p%lld c%lld i%lld le%lld ri%lld\n" , p , c , i , le , ri );
		if ( (pre[i+p]-p*a[1]+c*a[n]) * 2 >= tot ) continue;
		if ( le == ri ) {
			if ( (pre[i+p] - p * a[1] + c*a[n]) * 2 < tot ) {
				ans++;
			}
			//printf ( "con p=%lld c=%lld i=%lld ans=%lld\n" , p , c , i , ans );
			continue;
		}
		if ( le > ri ) continue;
		//printf ( "%lld\n" , pre[i+p] - p * a[1] + c*a[n]+ get(le,ri) );
		if ( (pre[i+p] - p * a[1] + c*a[n]+ get(le+2,ri)) * 2 < tot ) {
			ans += (ri-le) / 2 + 1;
		}
		else {
			l = 0; r = (ri-le)/2;
			while ( l < r - 1 ) {
				mid = (l+r)/2;
				if ( check ( mid , i ,- p * a[1] + c*a[n]) == 1 ) l = mid;
				else r = mid;
			}
			if ( check ( r , i ,- p * a[1] + c*a[n]) == 1 ) ans += r+1;
			else ans += l+1;
			//printf ( "search %lld %lld\n" , l , r );
		}
		//printf ( "le%lld ri%lld\n" , le , ri );
		//printf ( "p=%lld c=%lld i=%lld ans=%lld\n" , p , c , i , ans );
	}
	for ( i = 2 ; i <= n - 2 ; i++ ) {
		if ( pre[i] > tot - pre[i] ) ans++;
	}
	printf ( "%lld\n" , ans % mod );
	clear ();
}
int main () {
	//freopen ( "e.in" , "r" , stdin );
	//freopen ( "e.out" , "w" , stdout );
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}