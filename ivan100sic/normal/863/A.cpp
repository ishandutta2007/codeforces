#include <bits/stdc++.h>
using namespace std;

long long rev(long long x) {
	long long t = 0;
	while (x) {
		t = 10*t + x % 10;
		x /= 10;
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	long long x;
	cin >> x;
	while (x % 10 == 0) {
		x /= 10;
	}
	if (x == rev(x)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}