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
		int f[2] = {0, 0};
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
			f[a[i]]++;
		}
		if (f[0] >= n/2) {
			cout << f[0] << '\n';
			for (int i=0; i<f[0]; i++)
				cout << "0 ";
			cout << '\n';
		} else {
			int r = f[1]/2*2;
			cout << r << '\n';
			for (int i=0; i<r; i++)
				cout << "1 ";
			cout << '\n';
		}
	}
}