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

	int a, b, c;
	cin >> a >> b >> c;
	int n;
	cin >> n;

	multiset<int> usb, ps2;

	for (int i=1; i<=n; i++) {
		int x;
		string s;
		cin >> x >> s;
		if (s[0] == 'U') {
			usb.insert(x);
		} else {
			ps2.insert(x);
		}
	}

	long long total = 0;
	int x = 0;

	while (usb.size() && a > 0) {
		a--;
		x++;
		total += *usb.begin();
		usb.erase(usb.begin());
	}

	while (ps2.size() && b > 0) {
		b--;
		x++;
		total += *ps2.begin();
		ps2.erase(ps2.begin());
	}

	for (int x : ps2) {
		usb.insert(x);
	}

	while (usb.size() && c > 0) {
		c--;
		x++;
		total += *usb.begin();
		usb.erase(usb.begin());
	}

	cout << x << ' ' << total;
}