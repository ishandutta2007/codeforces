#include <iostream>
#include <stdio.h>

using namespace std;

int n , k;
char z[120000];
int x[120000] , cnt;
int ans;
int main () {
	int i , j , t , now;
	cin >> n >> k >> z;
	x[1] = 1; cnt = 1;
	for ( i = 1 ; i < n ; i++ ) {
		if ( z[i] != z[i-1] ) x[++cnt] = 1;
		else x[cnt]++;
	}
	j = 2; t = k; now = 0;
	for ( i = 1 ; i <= cnt ; i += 2 ) {
		t += x[i-1];
		now -= x[i-1];
		if ( t > k ) t = k;
		if ( now < 0 ) j=i+1,now=0;
		while ( j <= cnt && x[j] <= t ) {
			t -= x[j];
			now += x[j] + x[j-1];
			j += 2;
		}
		ans = max ( ans , now + x[j-1] + min ( x[j] , t ) );
		//cout << i << " " << j << " " << now << endl;
		now -= x[i];
	}
	j = 1; t = k; now = 0;
	for ( i = 0 ; i <= cnt ; i += 2 ) {
		if ( i != 0 ) t += x[i-1], now -= x[i-1];
		if ( now < 0 ) j=i+1,now=0;
		if ( t > k ) t = k;
		while ( j <= cnt && x[j] <= t ) {
			t -= x[j];
			now += x[j] + x[j-1];
			j += 2;
		}
		ans = max ( ans , now + x[j-1] + min ( x[j] , t ) );
		//cout << i << " " << now << " " << t << endl;
		now -= x[i];
	}
	cout << ans << endl;
	getchar();getchar();
	return 0;
}