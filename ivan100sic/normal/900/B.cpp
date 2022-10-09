#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	int pos = 0;
	while (pos < 1000000) {
		pos++;
		int dgt = a * 10 / b;
		if (dgt == c) {
			cout << pos;
			return 0;
		}
		a = 10*a % b;
	}

	cout << -1;
}