// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

vector<int> rd(int n) {
	vector<int> a(n);
	for (int& x : a) cin >> x;
	return a;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		auto a = rd(n), b = rd(n), c = rd(n);
		vector<int> p(n);
		p[0] = a[0];
		for (int i=1; i<n-1; i++) {
			if (a[i] != p[i-1]) p[i] = a[i];
			else if (b[i] != p[i-1]) p[i] = b[i];
			else p[i] = c[i];
		}

		if (a[n-1] != p[n-2] && a[n-1] != p[0]) p[n-1] = a[n-1];
		else if (b[n-1] != p[n-2] && b[n-1] != p[0]) p[n-1] = b[n-1];
		else p[n-1] = c[n-1];

		for (int x : p) {
			cout << x << ' ';
		}
		cout << '\n';
	}
}