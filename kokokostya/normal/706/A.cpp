#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <queue>

using namespace std;

int main() {
	long double a, b;
	cin >> a >> b;
	long double t = 1000000000;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long double x, y, v;
		cin >> x >> y >> v;
		if (sqrt((x - a) * (x - a) + (y - b) * (y - b)) < v * t)
			t = sqrt((x - a) * (x - a) + (y - b) * (y - b)) / v;
	}
	cout << setprecision(15) << t;
	return 0;
}