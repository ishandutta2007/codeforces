#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int d = a[1] - a[0];
	for (int i=1; i<n; i++) {
		if (a[i] - a[i-1] != d) {
			cout << a[n-1];
			return 0;
		}
	}
	cout << a[n-1] + d;
}