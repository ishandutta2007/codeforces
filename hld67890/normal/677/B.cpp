#include <iostream>
#include <stdio.h>

using namespace std;

//long long
long long n , h , k;
long long a;
long long ans;
int main () {
	int i;
	long long t;
	cin >> n >> h >> k;
	t = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		cin >> a;
		if ( a + t <= h ) t += a;
		else {
			ans += t / k;
			t = t % k;
			if ( a + t <= h ) t += a;
			else {
				t = a;
				ans++;
			}
		}
	}
	ans += t / k;
	t = t % k;
	if ( t ) ans++;
	cout << ans << endl;
	return 0;
}