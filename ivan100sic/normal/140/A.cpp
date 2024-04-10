#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <cmath>
using namespace std;

const double ludolf = 3.14159265358979323;

double kv(double x) {
	return x*x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, r, R;
	cin >> n >> R >> r;

	if (n == 1) {
		cout << (r <= R ? "YES" : "NO");
	} else if (n == 2) {
		cout << (2*r <= R ? "YES" : "NO");
	} else {
		double x1 = R-r;
		double y1 = 0;

		double x2 = (R-r) * cos(2*ludolf / n);
		double y2 = (R-r) * sin(2*ludolf / n);

		double dist2 = kv(x1-x2) + kv(y1-y2);

		cerr << dist2 << ' ' << 4*r*r << '\n';

		cout << (dist2 >= 3.999999999*r*r ? "YES" : "NO");
	}
}