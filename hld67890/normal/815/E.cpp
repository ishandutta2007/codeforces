#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

//long long
long long n , k;
long long ans;
long long find ( long long l , long long r , long long need , long long res ) {
	//printf ( "%I64d %I64d %I64d %I64d\n" , l , r , need , res );
	if ( (r-l)/2 == need && res == 1 ) {
		return (r+l)/2;
	}
	long long mid = (l+r)/2;
	map < long long , long long , greater <long long> > m , dis;
	map < long long , long long , greater <long long> >::iterator it;
	dis[(r-l)/2]++;
	m[mid-l] = 1;
	for ( it = m.begin() ; it -> first >= 1 && it != m.end () ; it++ ) {
		dis[(it->first-1)/2] += it -> second;
		m[(it->first-1)/2] += it -> second;
		m[it->first/2] += it -> second;
	}
	long long tmp = dis[need];
	if ( res <= tmp ) return find ( l , mid - 1 , need , res );
	else return find ( mid + 1 , r , need , res - tmp );
}
void work () {
	long long i , j , cnt;
	map < long long , long long , greater <long long> > m , dis;
	map < long long , long long , greater <long long> >::iterator it;
	scanf ( "%I64d%I64d" , &n , &k );
	if ( k == 1 ) {
		printf ( "1\n" );
		return ;
	}
	if ( k == 2 ) {
		printf ( "%I64d\n" , n );
		return ;
	}
	n -= 2; k -= 2;
	m[n] = 1;
	for ( it = m.begin() ; it -> first >= 1 && it != m.end () ; it++ ) {
		dis[(it->first-1)/2] += it -> second;
		m[(it->first-1)/2] += it -> second;
		m[it->first/2] += it -> second;
	}
	for ( it = dis.begin () ; it != dis.end () ; it++ ) {
		if ( it -> second >= k ) {
			printf ( "%I64d\n" , find ( 2 , n + 1 , it -> first , k ) );
			break;
		}
		k -= it -> second;
	}
}
int main () {
	work ();
	return 0;
}