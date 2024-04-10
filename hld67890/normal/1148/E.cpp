#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 310000;
struct node {
	long long s , i;
} s[maxn];
long long n , m;
long long t[maxn];
long long st[maxn] , tops;
long long sums , sumt;
long long mx[maxn*5] , my[maxn*5] , md[maxn*5];
bool cmp ( node x1 , node x2 ) {
	return x1.s < x2.s;
}
void work () {
	long long i , j , x;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &s[i].s );
		s[i].i = i;
		sums += s[i].s;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &t[i] );
		sumt += t[i];
	}
	if ( sums != sumt ) {
		printf ( "NO\n" );
		return ;
	}
	sort ( s + 1 , s + 1 + n , cmp );
	sort ( t + 1 , t + 1 + n );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( t[i] - s[i].s > 0 ) {
			st[++tops] = i;
		}
		if ( t[i] - s[i].s < 0 ) {
			while ( tops ) {
				x = min ( s[i].s - t[i] , t[st[tops]] - s[st[tops]].s );
				s[i].s -= x;
				s[st[tops]].s += x;
				m++;
				mx[m] = s[st[tops]].i;
				my[m] = s[i].i;
				md[m] = x;
				if ( s[st[tops]].s == t[st[tops]] ) tops--;
				if ( t[i] == s[i].s ) break;
			}
			if ( t[i] != s[i].s ) {
				printf ( "NO\n" );
				return ;
			}
		}
	}
	printf ( "YES\n" );
	printf ( "%I64d\n" , m );
	for ( i = 1 ; i <= m ; i++ ) {
		printf ( "%I64d %I64d %I64d\n" , mx[i] , my[i] , md[i] );
	}
}
int main () {
	work ();
	return 0;
}