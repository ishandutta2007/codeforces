#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long NN = 1200000;
const long long del = 2100000;
long long n;
long long p[NN];
long long c[NN*4];
long long ans , ansi;
void work () {
	long long i , k , tmp , s1 , s2;
	scanf ( "%I64d" , &n );
	tmp = 0; s1 = s2 = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &p[i] );
		c[p[i]-i+del]++;
		tmp += abs ( p[i] - i );
		if ( p[i] - i < 0 ) s1++;
		else s2++;
	}
	ans = tmp; ansi = 0;
	for ( i = n - 1 , k = 1 ; i >= 1 ; i-- , k++ ) {
		
		tmp = tmp - s1 + s2;
		//printf ( " %I64d %I64d %I64d\n" , tmp , s1 , s2 );

		s1 -= c[-k+del];
		s2 += c[-k+del];
		
		
		if ( p[k] != n ) {
			s1++;
			s2--;
		}
		tmp -= p[k];
		tmp += abs ( p[k] - n );
		c[p[k]-k+del]--;
		c[p[k]-n-k+del]++;
		//printf ( "%I64d %I64d %I64d\n" , tmp , s1 , s2 );
		
		if ( tmp < ans ) {
			ans = tmp;
			ansi = i;
		}
		//n-i
	}
	printf ( "%I64d %I64d\n" , ans , ansi );
}
int main () {
	//FILE *fpr = freopen ( "b.in" , "r" , stdin );
	work ();
	return 0;
}