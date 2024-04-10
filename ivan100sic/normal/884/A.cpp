#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, t;
	cin >> n >> t;
	int c = 0;
	while (n--) {
		int x;
		cin >> x;
		x = 86400 - x;
		t -= x;
		c++;
		if (t <= 0) {
			cout << c;
			return 0;
		}
	}
}