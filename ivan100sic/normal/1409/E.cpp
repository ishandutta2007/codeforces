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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
		}

		sort(begin(a), end(a));

		vector<int> l(n);
		for (int i=0, j=0; i<n; i++) {
			while (a[i] - a[j] > k) j++;
			l[i] = i-j+1;
		}
		for (int i=1; i<n; i++) {
			l[i] = max(l[i], l[i-1]);
		}

		// strogo off
		int sol = 0;

		for (int i=n-1, j=n-1; i>0; i--) {
			while (a[j] - a[i] > k) j--;
			sol = max(sol, l[i-1] + (j-i+1));
		}

		// 2k
		for (int i=0, j=0; i<n; i++) {
			while (a[i] - a[j] > 2*k) j++;
			sol = max(sol, j-i+1);
		}

		cout << sol << '\n';
	}
}