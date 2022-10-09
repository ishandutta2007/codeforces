#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c, d=0;
	cin >> a >> b;

	c = 0;
	while (a > 0 || c >= b) {
		if (a > 0) {
			a--;
			c++;
			d++;
		}

		if (c >= b) {
			c -= b;
			a++;
		}
	}

	cout << d;

}