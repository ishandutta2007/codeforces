#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

long long m, n;
long long x[100005];
set<long long> xs;

long long suma, sumakv, kvsuma;

long long pw(long long a, long long b) {
	if (b == 0) {
		return 1;
	}

	long long tmp = pw(a, b/2);
	tmp = tmp * tmp % m;

	if (b % 2) {
		tmp = tmp * a % m;
	}

	return tmp;
}

long long inv(long long a) {
	return pw(a, m-2);
}

long long msqrt(long long n) {

	if (n == 0) {
		return 0;
	}

	if (pw(n, m/2) != 1) {
		return -1;
	}

	long long z;
	for (long long i=2; i<m; i++) {
		if (pw(i, m/2) == m-1) {
			z = i;
			break;
		}
	}

	cerr << "Nonresidue found: " << z << '\n';

	long long q=m-1, s=0;
	while (q % 2 == 0) {
		q /= 2;
		s++;
	}

	long long M = s;
	long long c = pw(z, q);
	long long t = pw(n, q);
	long long r = pw(n, (q+1)/2);

	while (1) {
		if (t == 1) {
			return r;
		}
		long long i = 1;
		long long tp = t*t % m;
		while (1) {
			if (tp == 1) {
				break;
			}
			tp = tp * tp % m;
			i++;
		}
		long long b = pw(c, 1ll << (M - i - 1));
		M = i;
		c = b*b % m;
		t = t*b % m * b % m;
		r = r*b % m;
	}
}

long long probaj(long long b) {

	long long a = (suma + m - b * ((n * 1ll * (n-1) / 2) % m) % m) % m;

	cerr << "a pre: " << a << '\n';

	a = a * inv(n) % m;

	cerr << "inv: " << inv(n) << '\n';
	cerr << "a: " << a << '\n';

	set<long long> ks;

	long long val = a;

	for (int i=0; i<n; i++) {
		ks.insert(val);
		val = (val + b) % m;
	}

	if (ks == xs) {
		return a;
	} else {
		return -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> m >> n;
	for (int i=0; i<n; i++) {
		cin >> x[i];

		suma = (suma + x[i]) % m;
		sumakv = (sumakv + x[i] * 1ll * x[i]) % m;

		xs.insert(x[i]);
	}

	long long xy = ((suma*suma - n*sumakv) % m + m) % m;

	// specijalni slucajevi

	if (n == 1) {
		cout << x[0] << ' ' << 0;
		return 0;
	}

	if (n == 2) {
		cout << min(x[0], x[1]) << ' ' << abs(x[0] - x[1]);
		return 0;
	}


	if (n == m) {
		cout << "0 1\n";
		return 0;
	}

	if (n == m-1) {
		for (int i=0; i<m; i++) {
			if (xs.count(i) == 0) {
				cout << (i+1) % m << " 1";
				return 0;
			}
		}
	}


	// m >= 5

	long long b2 = xy * 12ll * inv(n*n % m  *  (1 - n*n % m + m)%m) % m;

	cerr << b2 << '\n';

	long long b = msqrt(b2);

	cerr << b << '\n';

	if (b == -1) {
		cout << -1;
		return 0;
	}

	long long a = probaj(b);

	if (a != -1) {
		cout << a << ' ' << b;
		return 0;
	}

	cout << -1;



}