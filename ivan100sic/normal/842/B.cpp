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

long long d, r, n, s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> r >> d >> n;

	long long rad = r-d;
	long long whole = r;

	r = rad;
	d = whole;

	for (int i=1; i<=n; i++) {
		long long x, y, a;
		cin >> x >> y >> a;

		int d2c = x*x + y*y;
		if (d2c >= (r+a)*(r+a) && d2c <= (d-a)*(d-a) && a <= d) {
			s++;
		}
	}

	cout << s;
}