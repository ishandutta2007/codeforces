#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a, b;
	cin >> a;

	while (a.back() == '/') {
		a.pop_back();
	}

	if (a.size() == 0) {
		a = '/';
	}

	char last = 0;
	for (char x : a) {
		if (x == last && x == '/') {
			;
		} else {
			b += x;
		}
		last = x;
	}
	cout << b;
}