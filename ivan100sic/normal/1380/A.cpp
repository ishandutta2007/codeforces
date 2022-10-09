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
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}

		int ok = 0;
		
		for (int i=1; i<n-1; i++) {
			if (a[i-1] < a[i] && a[i] > a[i+1]) {
				cout << "YES\n";
				cout << i << ' ' << i+1 << ' ' << i+2 << '\n';
				ok = 1;
				break;
			}
		}

		if (!ok) {
			cout << "NO\n";
		}

	}
}