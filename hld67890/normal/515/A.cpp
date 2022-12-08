#include <iostream>

using namespace std;

long long n , m , s;
void work () {
	cin >> n >> m >> s;
	if ( n < 0 ) n = -n;
	if ( m < 0 ) m = -m;
	if ( ( n + m ) % 2 == s % 2 && s >= n + m ) cout << "Yes" << endl;
	else cout << "No" << endl;
}
int main () {
	work ();
	return 0;
}