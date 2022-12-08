#include <iostream>
#include <stdio.h>

using namespace std;

int n;
int a[220000] , b[210000];
int st1[20][220000] , st2[20][220000];
int poww[221000] , exp[221000];
long long ans;
int check1 ( int l , int r ) {
	//cout << l << " " << r << " "<< st1[exp[r-l+1]][l] << " " << st1[exp[r-l+1]][r-poww[r-l+1]+1] << " " << st2[exp[r-l+1]][l] << " " << st2[exp[r-l+1]][r-poww[r-l+1]+1] << endl;
	if ( max ( st1[exp[r-l+1]][l] , st1[exp[r-l+1]][r-poww[r-l+1]+1] ) < min ( st2[exp[r-l+1]][l] , st2[exp[r-l+1]][r-poww[r-l+1]+1] ) )
		return 1;
	return 0;
}
int check2 ( int l , int r ) {
	//cout << l << " " << r << " "<< st1[exp[r-l+1]][l] << " " << st1[exp[r-l+1]][r-poww[r-l+1]+1] << " " << st2[exp[r-l+1]][l] << " " << st2[exp[r-l+1]][r-poww[r-l+1]+1] << endl;
	if ( max ( st1[exp[r-l+1]][l] , st1[exp[r-l+1]][r-poww[r-l+1]+1] ) <= min ( st2[exp[r-l+1]][l] , st2[exp[r-l+1]][r-poww[r-l+1]+1] ) )
		return 1;
	return 0;
}
void work () {
	int i , j , x1 , x2;
	scanf ( "%d" , &n );
	for ( i = 1 , j = 0 ; i <= n ; i = i * 2 , j++ ) poww[i] = i, exp[i] = j;
	for ( i = 1 ; i <= n ; i++ ) if ( !poww[i] ) poww[i] = poww[i-1], exp[i] = exp[i-1];
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] ), st1[0][i] = a[i];
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &b[i] ), st2[0][i] = b[i];
	for ( i = 1 ; i <= 17 ; i++ ) for ( j = 1 ; j <= n ; j++ ) st1[i][j] = max ( st1[i-1][j] , j + (1<<(i-1)) > n ? -1000000001 : st1[i-1][j+(1<<(i-1))] );
	for ( i = 1 ; i <= 17 ; i++ ) for ( j = 1 ; j <= n ; j++ ) st2[i][j] = min ( st2[i-1][j] , j + (1<<(i-1)) > n ? 1000000001 : st2[i-1][j+(1<<(i-1))] );
	for ( i = 1 ; i <= n ; i++ ) {
		x1 = i; x2 = i;
		for ( j = 17 ; j >= 0 ; j-- ) if ( x1 + (1<<j) <= n && check1 ( i , x1 + (1<<j) ) == 1 ) x1 += (1<<j);
		for ( j = 17 ; j >= 0 ; j-- ) if ( x2 + (1<<j) <= n && check2 ( i , x2 + (1<<j) ) == 1 ) x2 += (1<<j);
		if ( a[i] == b[i] ) x1--;
		if ( x2 > x1 ) ans += (long long) (x2 - x1);
		//cout << x1 << " " << x2 << endl;
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}