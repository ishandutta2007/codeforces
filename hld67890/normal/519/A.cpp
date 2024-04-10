#include <iostream>

using namespace std;

int w , b;
char z[10];
void work () {
	int i , j;
	for ( i = 1 ; i <= 8 ; i++ ) {
		cin >> z;
		for ( j = 0 ; j < 8 ; j++ ) {
			if ( z[j] == 'q' ) b += 9;
			if ( z[j] == 'r' ) b += 5;
			if ( z[j] == 'b' ) b += 3;
			if ( z[j] == 'n' ) b += 3;
			if ( z[j] == 'p' ) b += 1;
			if ( z[j] == 'Q' ) w += 9;
			if ( z[j] == 'R' ) w += 5;
			if ( z[j] == 'B' ) w += 3;
			if ( z[j] == 'N' ) w += 3;
			if ( z[j] == 'P' ) w += 1;
		}
	}
	if ( w > b ) cout << "White" << endl;
	if ( w == b ) cout << "Draw" << endl;
	if ( w < b ) cout << "Black" << endl;
}
int main () {
	work ();
	return 0;
}