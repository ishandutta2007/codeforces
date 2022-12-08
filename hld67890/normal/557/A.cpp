#include <iostream>

using namespace std;

int x1,x2,x3,n1,n2,n3 , n;
void work () {
	int i , a , b , c;
	cin >> n;
	cin >> n1 >> x1 >> n2 >> x2 >> n3 >> x3;
	if ( x1 + n2 + n3 <= n ) {
		a = x1;
		n -= a;
		if ( x2 + n3 <= n ) {
			b = x2;
			c = n - x2;
		}
		else {
			b = n - n3;
			c = n3;
		}
	}
	else a = n - n2 - n3, b = n2 , c = n3;
	cout << a << " " << b << " " << c << endl;
}
int main () {
	work ();
	return 0;
}