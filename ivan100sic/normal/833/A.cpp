#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

long long proveri(long long x) {
	long long l=1, r=1000000, m;
	while (l <= r) {
		m = (l+r) / 2;
		if (m*m*m > x) {
			r = m-1;
		} else if (m*m*m < x) {
			l = m+1;
		} else {
			return m;
		}
	}
	return 0;
}

int pow_of_p(long long p, long long x) {
	int c=0;
	while (x % p == 0) {
		x /= p;
		c++;
	}
	return c;
}

int f[1000005];

void erat() {
	for (long long i=2; i<1000005; i++) {
		if (f[i] == 0) {
			f[i] = i;
			for (long long j=i*i; j<1000005; j+=i) {
				if (f[j] == 0) {
					f[j] = i;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	erat();
	cin >> n;
	while (n--) {
		long long a, b;
		cin >> a >> b;
		long long cbrt = proveri(a*b);
		if (cbrt) {
			// faktorisi
			set<int> p;
			while (cbrt > 1) {
				p.insert(f[cbrt]);
				cbrt /= f[cbrt];
			}

			bool ok = true;

			for (int pp : p) {
				int ap = pow_of_p(pp, a);
				int bp = pow_of_p(pp, b);
				// cerr << ap << ' ' << bp << '\n';
				if (2*ap < bp || 2*bp < ap) {
					ok = false;
					break;
				}
			}

			if (ok) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
			
		} else {
			cout << "No\n";
		}
	}
}