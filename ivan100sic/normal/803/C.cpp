#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, k, sol = -1, k2;
	cin >> n >> k;

	if (k > 2e5 || k*(k+1) / 2 > n) {
		cout << -1;
		return 0;
	}

	k2 = k*(k+1) / 2;

	for (long long i=1; i*i<=n; i++) {
		if (n % i == 0) {
			if (i <= n / k2) {
				sol = max(sol, i);
			}
			if (n / i <= n / k2) {
				sol = max(sol, n / i);
			}
		}
	}

	for (int i=1; i<k; i++) {
		cout << i*sol << ' ';
	}
	cout << n-(k2-k)*sol;
}