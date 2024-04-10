#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[300000];
void work () {
	int i , l , ml , mi;
	long long tmp , tmp1 , max1 = -1 , max2 = 1 , s;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	if ( n == 1 ) {
		printf ( "1\n%d\n" , a[1] );
		return ;
	}
	sort ( a + 1 , a + 1 + n );
	l = 1; s = 0;
	for ( i = 1 ; i < n ; i++ ) {
		//cout << i <<" " << s << " " << (2*i-2*l+1) << " " << a[i] << " " << l << endl;
		s += a[i] + a[n-(i-l)+1];
		//cout << i <<" " << s << " " << (2*i-2*l+1) << " " << a[i] << " " << l << endl;
		//cout <<  s << " " << a[l] << "   " <<a[n-(i-l-1)]  << " " << (2*i-2*l+1) << " " << (2*i-2*l+1-2) << endl;
		while ( i > l && ( s - a[l] - a[n-(i-l-1)] ) * (2*i-2*l+1) > s * (2*i-2*l+1-2) ) s -= a[l] + a[n-(i-l++)+1];
		//if ( i == n - (i-l+1) + 1 ) l++ , s -= a[i] + a[i-1] + a[l-1];
		//cout << i <<" " << s << " " << (2*i-2*l+1) << " " << a[i] << " " << l << endl;
		tmp = (long long)s * (long long) max2;
		tmp1 = (long long) max1 * (long long)(2*i-2*l+1) + (long long)a[i] * (long long)(2*i-2*l+1) * (long long)max2;
		if ( tmp > tmp1 ) max1 = s - a[i] * (long long)(2*i-2*l+1), max2 = (2*i-2*l+1), ml = l, mi = i;
		if ( i == n-(i-l+1) || i == n-(i-l) ) s -= a[l] + a[n-(i-l++)+1];
	}
	//cout << mi << " "<< ml << " " << maxx << endl;
	printf ( "%d\n" , mi * 2 - ml * 2 + 1 );
	for ( i = ml ; i <= mi ; i++ ) printf ( "%d " , a[i] );
	for ( i = n - (mi-ml)+1 ; i <= n ; i++ ) printf ( "%d " , a[i] );
}
int main () {
	work ();
	return 0;
}