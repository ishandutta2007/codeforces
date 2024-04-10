#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <set>
using namespace std;

long long gcd(long long a, long long b) {
	long long t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

vector<long long> divisors;

void find_divs(long long x) {
	divisors.clear();
	for (long long i=2; i*i<=x; i++) {
		if (i*i == x) {
			divisors.push_back(i);
		} else {
			if (x % i == 0) {
				divisors.push_back(i);
				divisors.push_back(x / i);
			}
		}
	}
	divisors.push_back(x);
	sort(divisors.begin(), divisors.end());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	long long a, b, s = 0;
	cin >> a >> b;

	while (1) {
		long long g = gcd(a, b);
		a /= g;
		b /= g;

		if (a == 1) {
			s += b;
			break;
		}

		find_divs(a);

		long long rmin = 1e18, dmin=1;

		for (long long d : divisors) {
			long long r = b % d;
			if (r < rmin) {
				rmin = r;
				dmin = d;
			}
		}

		b -= rmin;
		s += rmin;
	}

	cout << s;


}