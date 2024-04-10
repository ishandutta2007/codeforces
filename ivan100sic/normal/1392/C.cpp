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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& x : a) {
			cin >> x;
		}

		ll z = 0;
		for (int i=0; i<n-1; i++) {
			z += max(0, a[i] - a[i+1]);
		}

		cout << z << '\n';
	}
}