#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k, x;
	cin >> n >> k >> x;
	vector<int> a(n);
	for (int& x : a) {
		cin >> x;
	}

	for (int i=n-k; i<n; i++) {
		a[i] = x;
	}

	cout << accumulate(a.begin(), a.end(), 0);
}