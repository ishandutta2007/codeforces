#include <iostream>

using namespace std;

int a , b;
void work () {
	cin >> a >> b;
	if ( a > b * 2 ) a = b * 2;
	if ( b > a * 2 ) b = a * 2;
	cout << ( a + b ) / 3 << endl;
}
int main () {
	work ();
	return 0;
}