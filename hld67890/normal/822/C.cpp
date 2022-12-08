#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long NN = 210000;
struct so {
	long long x , f , len , v;
} s[NN*2];
long long n , x;
long long minn[NN];
long long ans;
bool cmp ( so x1 , so x2 ) {
	if ( x1.x == x2.x ) return x1.f < x2.f;
	return x1.x < x2.x;
}
void work () {
	long long i , l , r , c;
	scanf ( "%I64d%I64d" , &n , &x );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d%I64d%I64d" , &l , &r , &c );
		s[i*2-1].x = l; s[i*2-1].f = 1; s[i*2-1].len = r-l+1; s[i*2-1].v = c;
		s[i*2].x = r + 1; s[i*2].f = -1; s[i*2].len = r-l+1; s[i*2].v = c;
	}
	sort ( s + 1 , s + 1 + n + n , cmp );
	for ( i = 0 ; i <= 200000 ; i++ ) minn[i] = 21474836477777ll;
	ans = 21474836477777ll;
	for ( i = 1 ; i <= n * 2 ; i++ ) {
		if ( s[i].len > x ) continue;
		if ( s[i].f == 1 ) {
			ans = min ( ans , s[i].v + minn[x-s[i].len] );
		}
		else {
			minn[s[i].len] = min ( minn[s[i].len] , s[i].v );
		}
	}
	if ( ans != 21474836477777ll ) printf ( "%I64d\n" , ans );
	else printf ( "-1\n" );
}
int main () {
	work ();
	return 0;
}