#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	long long n, m;
	cin >> n >> m;
	long long res = 0;
	vector<long long> v;
	v.push_back(0);
	int p = 0;
	for (long long b = 1; b <= n; b++) {
		v.push_back(b*b);
		while (v.back() - v[p] > m) {
			++p;
		}
		res += 2 * (min(v.back(), m) - (b - p));
	}
	bool f = false;
	for (long long i = 1; i < 2*n; i++, f = !f) {
		if (f) {
			if (2*i <= m)
				++res;
		} else {
			if (i <= m)
				++res;
		}
	}
	cout << res << endl;
	return 0;
}