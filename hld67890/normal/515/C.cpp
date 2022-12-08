#include <iostream>

using namespace std;

int n , a2 , a3 , a5 , a7;
void add ( int a ) {
	if ( a == 0 || a == 1 ) return ;
	if ( a >= 2 ) { a2++; }
	if ( a >= 3 ) { a3++; }
	if ( a >= 4 ) { a2 += 2; }
	if ( a >= 5 ) { a5++; }
	if ( a >= 6 ) { a2++; a3++; }
	if ( a >= 7 ) { a7++; }
	if ( a >= 8 ) { a2 += 3; }
	if ( a >= 9 ) { a3 += 2; }
}
void work () {
	int i;
	char z[200];
	cin >> n >> z;
	for ( i = 0 ; i < n ; i++ ) {
		add ( z[i] - '0' );
	}
	i = 0;
	while ( a2 ) {
		if ( a7 != 0 ) {
			cout << 7;
			a7--; a5--; a3 -= 2; a2 -=4;
		}
		else {
			if ( a5 != 0 ) {
				cout << 5;
				a5--; a3--; a2 -= 3;
			}
			else {
				if ( a3 != 0 ) {
					cout << 3;
					a3--; a2--;
				}
				else {
					cout << 2;
					a2--;
				}
			}
		}
	}
	cout << endl;
}
int main () {
	work ();
	return 0;
}