// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, a, b, k;
	cin >> n >> a >> b >> k;

	vector<int> c(n);
	for (int& z : c) {
		int x;
		cin >> x;

		if (x % (a+b) == 0)
			x = a+b;
		else
			x %= a+b;

		z = (x+a-1)/a - 1;
	}

	sort(begin(c), end(c));
	int u = 0;
	for (int x : c) {
		if (x <= k) {
			k -= x;
			u++;
		}
	}
	cout << u << '\n';
}