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
		int n, r=0;
		cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		for (int i=0; i<n-1; i++) {
			r += a[i] > a[i+1];
		}
		if (r == n-1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}