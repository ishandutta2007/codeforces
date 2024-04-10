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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a, b;
	int n;
	cin >> a >> b >> n;

	cout << a << ' ' << b << '\n';

	for (int i=0; i<n; i++) {
		string p, q;
		cin >> p >> q;

		if (p == a) {
			a = q;
		} else if (p == b) {
			b = q;
		} else if (q == a) {
			a = p;
		} else if (q == b) {
			b = p;
		}

		cout << a << ' ' << b << '\n';
	}
}