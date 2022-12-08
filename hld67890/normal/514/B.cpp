#include <iostream>

using namespace std;

const int maxn = 1001;
int n , x0 , y0;
int x[maxn] , y[maxn];
bool f[maxn];
void work () {
	int i , j , ans = 0;
	cin >> n >> x0 >> y0;
	for ( i = 1 ; i <= n ; i++ ) {
		cin >> x[i] >> y[i];
		x[i] -= x0;
		y[i] -= y0;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( f[i] == 0 ) {
			ans++;
			for ( j = i + 1 ; j <= n ; j++ ) {
				if ( x[i] * y[j] == x[j] * y[i] ) f[j] = 1;
			}
		}
	}
	cout << ans << endl;
}
int main () {
	work ();
	return 0;
}