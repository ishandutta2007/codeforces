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

		reverse(begin(a), end(a));
		int i = 1;
		while (i < n && a[i-1] <= a[i]) {
			i++;
		}

		int j = min(n, i+1);

		while (j < n && a[j-1] >= a[j]) {
			j++;
		}

		cout << n - j << '\n';
	}
}