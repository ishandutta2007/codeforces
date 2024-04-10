// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		int s = accumulate(begin(a), end(a), 0);
		auto [i, j] = minmax_element(begin(a), end(a));
		int c = count(begin(a), end(a), x);
		if (*i == *j && *i == x) {
			cout << "0\n";
		} else if (s == n*x || c > 0) {
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}
}