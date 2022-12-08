#include <iostream>
#include <algorithm>

using namespace std;

long long a[210000] , n;
void work () {
	long long i , w , s , d;
	bool f = false;
	cin >> n >> w;
	for ( i = 0 ; i < n * 2 ; i++ ) cin >> a[i];
	sort ( a , a + n + n );
	s = a[n] / 2;
	if ( a[n] % 2 == 1 ) f = true;
	if ( s >= a[0] ) s = a[0],f = false;
	s = s * n * 3;
	if ( f ) s += n + n / 2;
	if ( s >= w ) s = w,f = 0;
	cout << s;
	if ( f && n % 2 == 1 ) cout << ".5";
	cout << endl;
}
int main () {
	work ();
	return 0;
}