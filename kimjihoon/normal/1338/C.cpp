#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		long long n; cin >> n;
		long long p = (n - 1LL) % 3;
		n = (n - 1LL) / 3;
		long long s = 0, t = 1;
		while (s + t <= n) {
			s += t; 
			t *= 4;
		}
		long long rn = n - s;
		if (p == 0) {
			cout << t + rn << '\n';
			continue;
		}
		long long b = t * 2, tr = 4;
		for (long long i = 0; (1LL << i) <= t; i++) {
			long long rm = rn % tr;
			if (i % 2 == 0) {
				if (rm >= tr / 2) b += (1LL << i);
			}
			else {
				if (tr / 4 <= rm && rm < tr / 2 + tr / 4) b += (1LL << i);
				tr *= 4;
			}
		}
		if (p == 1) cout << b << '\n';
		else cout << ((t + rn) ^ b) << '\n';
	}
	return 0;
}