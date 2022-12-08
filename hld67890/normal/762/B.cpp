#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 310000;
struct so {
	long long x , a;
} s[maxn];
long long n , a , b , c;
char z[10];
long long tot , sum;
bool cmp ( so x1 , so x2 ) {
	return x1.x < x2.x;
}
void work () {
	long long i;
	scanf ( "%I64d%I64d%I64d" , &a , &b , &c );
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d%s" , &s[i].x , z + 1 );
		if ( z[1] == 'U' ) s[i].a = 1;
		else s[i].a = 2;
	}
	sort ( s + 1 , s + 1 + n , cmp );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( s[i].a == 1 ) {
			if ( a ) a--, tot++, sum += s[i].x;
			else {
				if ( c ) c--, tot++, sum += s[i].x;
			}
		}
		else {
			if ( b ) b--, tot++, sum += s[i].x;
			else {
				if ( c ) c--, tot++, sum += s[i].x;
			}
		}
	}
	printf ( "%I64d %I64d\n" , tot , sum );
}
int main () {
	work ();
	return 0;
}