#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

//long long
const long long maxn = 120000;
long long n , k;
long long a[maxn];
long long ans;
map < long long , long long > st;
void work () {
	long long i , s , t;
	scanf ( "%I64d%I64d" , &n , &k );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%I64d" , &a[i] );
	s = 0;
	//st.insert ( make_pair(s,1) );
	st[s]++;
	for ( i = 1 ; i <= n ; i++ ) {
		s += a[i];
		if ( k == 1 || k == -1 ) {
			ans += st[s - 1];
			if ( k == -1 ) ans += st[s + 1];
		}
		else {
			for ( t = 1 ; t <= 10000000000000000ll ; t = t * k ) ans += st[s - t];
		}
		//st.insert ( make_pair(s,1) );
		st[s]++;
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	//FILE *fpr = freopen ( "c.in" , "r" , stdin );
	work ();
	return 0;
}