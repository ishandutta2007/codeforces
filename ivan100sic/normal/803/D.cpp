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

int k, n;
string s;
vector<int> a, b;

bool ok(int w) {
	int lines = 0;
	int curr = 0;

	for (int x : b) {
		if (x > w) {
			return false;
		}
		if (x + curr > w) {
			curr = x;
			lines++;
		} else {
			curr += x;
		}
	}

	if (curr > 0) {
		lines++;
	}

	return lines <= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> k;
	getline(cin, s);
	getline(cin, s);

	n = s.size();

	a.push_back(-1);
	for (int i=0; i<n; i++) {
		if (s[i] == ' ' || s[i] == '-') {
			a.push_back(i);
		}
	}
	a.push_back(n-1);

	for (int i=1; i<a.size(); i++) {
		b.push_back(a[i] - a[i-1]);
		//cerr << ' ' << *b.rbegin() << '\n';
	}

	int l=1, r=n, o=n;

	while (l <= r) {
		int m = (l+r) / 2;
		if (ok(m)) {
			o = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}

	cout << o << '\n';
}