/*

a0*t0 + 2*a1*t1 + 4*a2*t2 + 8*a3*t3 = 8



*/

#include <iostream>
#include <algorithm>
using namespace std;

long long b[200005], c[200005], n, a[200005];
long long bitcnt[62];

int main() {
	cin >> n;
	for (long long i=1; i<=n; i++) {
		cin >> b[i];
	}
	for (long long i=1; i<=n; i++) {
		cin >> c[i];
	}

	long long sum = 0;
	for (long long i=1; i<=n; i++) {
		sum += b[i] + c[i];
	}
	sum /= n;
	
	for (long long i=1; i<=n; i++) {
		a[i] = (b[i] + c[i] - sum / 2) / n;
		long long x = a[i];
		for (long long i=0; i<60; i++) {
			if (x & (1ll<<i)) {
				bitcnt[i]++;
			}
		}
	}

	for (long long i=1; i<=n; i++) {
		long long x = a[i];
		long long sum_and = 0, sum_or = 0;

		for (long long i=0; i<30; i++) {
			if (x & (1ll<<i)) {
				sum_or += n * (1ll<<i);
				sum_and += bitcnt[i] * (1ll<<i);
			} else {
				sum_or += bitcnt[i] * (1ll<<i);
			}
			
		}
		if (sum_and != b[i] || sum_or != c[i]) {
			cout << -1;
			return 0;
		}
	}

	for (long long i=1; i<=n; i++) {
		cout << a[i] << ' ';
	}


}