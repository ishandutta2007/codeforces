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
		int n, f=0;
		cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		int h = *max_element(begin(a), end(a));
		for (int i=0; i<n; i++) {
			if (a[i] == h && ((i > 0 && a[i] > a[i-1]) || (i < n-1 && a[i] > a[i+1]))) {
				cout << i+1 << '\n';
				f = 1;
				break;
			}
		}

		if (!f) {
			cout << "-1\n";
		}
	}
}