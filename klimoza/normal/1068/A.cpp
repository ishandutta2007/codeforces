#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;

int main() {
	long long int n, m, k, l;
	cin >> n >> m >> k >> l;
	if (n - k < l || m > n) cout << -1 << "\n";
	else {
		long long int f = ceil(((long double)k + l) / (long double)m);
		if (f * m > n) {
			cout << -1 << "\n";
		}
		else {
			cout << f << "\n";
		}
	}
	//system("pause");
	return 0;
}