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

long long trougao(long long x) {
	long long l = 1, r = 3e9, o = 0;

	while (l <= r) {
		long long m = (l+r) / 2;
		if (m * (m+1) / 2 >= x) {
			o = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}

	return o;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	long long n, m, x = 0, t;

	// prvih m dana sve ok
	cin >> n >> m;

	if (n <= m) {
		cout << n;
		return 0;
	}

	x = n - m;
	t = m;

	cerr << x << ' ' << t << '\n';
	// sad prazni polako

	cout << t + trougao(x);
}