#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	int x = count_if(a.begin(), a.end(), [](auto p) { return p.first < 0; });

	if (x <= 1 || x >= n-1) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}