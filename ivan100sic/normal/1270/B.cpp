#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++)
			cin >> a[i];
		int ok = 0;
		for (int i=0; i<n-1; i++) {
			if (abs(a[i] - a[i+1]) >= 2) {
				cout << "YES\n";
				cout << i+1 << ' ' << i+2 << '\n';
				ok = 1;
				break;
			}
		}
		if (!ok)
			cout << "NO\n";
	}
}