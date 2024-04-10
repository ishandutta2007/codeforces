#include <iostream>
#include <stdio.h>

using namespace std;

int n , t;
double x[20][20];
double abs ( double x ) {
	if ( x < 0.0 ) return -x;
	return x;
}
void pour ( int i , int j , double y ) {
	if ( i > n ) return ;
	if ( x[i][j] + y >= 1 ) {
		y = x[i][j] + y - 1;
		x[i][j] = 1;
		pour ( i + 1 , j , y / 2.0 );
		pour ( i + 1 , j + 1 , y / 2.0 );
	}
	else x[i][j] += y;
}
int main () {
	int i , j , ans;
	cin >> n >> t;
	for ( i = 1 ; i <= t ; i++ ) {
		pour ( 1 , 1 , 1.0 );
	}
	ans = 0;
	for ( i = 1 ; i <= n ; i++ ) for ( j = 1 ; j <= i ; j++ ) if ( abs (x[i][j] - 1.00) <= 1e-9 ) ans++;
	cout << ans << endl;
	return 0;
}