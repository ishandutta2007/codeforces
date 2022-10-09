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
		for (int& x : a)
			cin >> x;
		sort(begin(a), end(a));
		int j = 1;
		for (int i=0; i<n; i++) {
			if (a[i] <= i+1) {
				j = i+2;
			}
		}
		cout << j << '\n';
	}
}