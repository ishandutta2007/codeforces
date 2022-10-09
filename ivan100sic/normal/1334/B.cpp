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
		for (int i=0; i<n; i++)
			cin >> a[i];
		sort(begin(a), end(a), greater<int>());
		ll z = 0, j = 0;
		for (int i=0; i<n; i++) {
			z += a[i];
			if ((i+1ll) * x <= z)
				j = i+1;
		}
		cout << j << '\n';
	}
}