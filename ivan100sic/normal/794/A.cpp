#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, a, b, c, d=0;
	cin >> a >> b >> c >> n;

	while (n--) {
		int x;
		cin >> x;
		if (b < x && x < c) {
			d++;
		}
	}

	cout << d;
}