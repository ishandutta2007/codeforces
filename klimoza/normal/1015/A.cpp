#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	vector<bool> used(m + 1);
	for (int i = 0; i < n; i++) {
		for (int j = a[i].first; j <= a[i].second; j++) {
			used[j] = true;
		}
	}
	vector<int> ans;
	for (int i = 1; i <= m; i++) {
		if (!used[i]) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	//system("pause");
	return 0;
}