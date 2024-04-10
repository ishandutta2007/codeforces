#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

const int MaxN = 300100;
const int P = 7, MOD = 1e9 + 7;
ll p[MaxN];

struct fenwick {
	ll sum[MaxN];

	void update( int x, int exp ) {
		while( x < MaxN ) {
			sum[x] += p[exp];
			sum[x] %= MOD;
			x += x&-x;
		}
	}
	ll read( int x, ll ret = 0 ) {
		while( x ) {
			ret += sum[x];
			ret %= MOD;
			x -= x&-x;
		}
		return ret;
	}
	ll query( int x, int y ) {
		return ( read( y ) - read( x ) + MOD ) % MOD;
	}
} A, B;

int n;

int main() {

	cin >> n;
	p[0] = 1;
	for( int i=1; i<=n; i++ ) p[i] = p[i-1]*P % MOD;

	for( int i=0; i<n; i++ ) {

		int x;
		cin >> x;

    A.update( x, x );
		B.update( n - x + 1, n - x + 1 );

		int l = min( n-x, x-1 );
		if( !l ) continue;

		if( A.query( x - l - 1, x - 1 ) * ( x - l - 1 < n - x - l ? p[n - x + 1 - l - x + l] : 1 ) % MOD
		 != B.query( n - x - l, n - x ) * ( x - l < n - x + 1 - l ? 1 : p[ - n + x - 1 + l + x - l] ) % MOD ) {
			cout << "YES";
			goto van;
		}

	}
	cout << "NO";
	van:;
	return 0;
}