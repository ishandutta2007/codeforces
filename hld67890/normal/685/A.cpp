#include <iostream>
#include <stdio.h>

using namespace std;

int n , m;
int a[10] , b[10] , A , B;
int f[10] , flag , ans;
void work () {
	int i , t , cnt1 , cnt2;
	scanf ( "%d%d" , &n , &m );
	cnt1 = 0; t = n - 1;
	while ( t ) {
		t = t / 7;
		cnt1++;
	}
	cnt2 = 0; t = m - 1;
	while ( t ) {
		t = t / 7;
		cnt2++;
	}
	if ( cnt1 + cnt2 >= 8 ) {
		printf ( "0\n" );
		return ;
	}
	cnt1 = max ( cnt1 , 1 ); cnt2 = max ( cnt2 , 1 );
	for ( ; A < n ; ) {
		//cout << A << " " << B << endl;
		for ( i = 0 ; i <= 7 ; i++ ) f[i] = 0;
		flag = 1;
		for ( i = 1 ; i <= cnt1 ; i++ ) {
			if ( f[a[i]] == 1 ) flag = 0;
			f[a[i]] = 1;
		}
		for ( i = 1 ; i <= cnt2 ; i++ ) {
			if ( f[b[i]] == 1 ) flag = 0;
			f[b[i]] = 1;
		}
		//cout << a[1] << a[2] << " $$ " << b[1] << b[2] << endl;
		//if ( flag ) cout << A << B << endl;
		ans += flag;
		b[cnt2]++; B++;
		for ( i = cnt2 ; i >= 1 ; i-- ) {
			b[i-1] += b[i] / 7;
			b[i] %= 7;
		}
		if ( B == m ) {
			for ( i = 1 ; i <= cnt2 ; i++ ) b[i] = 0;
			a[cnt1]++; B = 0; A++;
			for ( i = cnt1 ; i >= 1 ; i-- ) {
				a[i-1] += a[i] / 7;
				a[i] %= 7;
			}
		}
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}