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
		int n, k, l = 0;
		cin >> n >> k;
		vector<int> a(n);
		for (int i=0; i<n; i++) cin >> a[i];
		int j = min_element(begin(a), end(a)) - begin(a);
		for (int x=0; x<n; x++) {
			if (x != j) {
				l += (k - a[x]) / a[j];
			}
		}
		cout << l << '\n';
	}
}