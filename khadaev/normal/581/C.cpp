#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k, t, ans = 0;
	vector<int> adds;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		ans += (t / 10);
		if (t == 100) continue;
		adds.push_back(10 - t % 10);
		for (int j = 0; j < 9 - t / 10; ++j) adds.push_back(10);
	};
	//cout << ans;
	sort(adds.begin(), adds.end());
	int ii = 0;
	while (ii < adds.size() && k >= adds[ii]) {
		ans++;
		k -= adds[ii];
		++ii;
		};
	cout << ans;
}