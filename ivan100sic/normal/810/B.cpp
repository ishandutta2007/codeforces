#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	vector<int> b;
	int n, f;
	long long sol = 0;
	cin >> n >> f;
	for (int i=0; i<n; i++) {
		int k, l;
		cin >> k >> l;

		sol += min(l, k);

		int profit = min(l, 2*k) - min(l, k);

		b.push_back(profit);
	}

	sort(b.begin(), b.end(), greater<int>());
	cout << accumulate(b.begin(), b.begin() + f, sol);
}