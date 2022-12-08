#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;


bool comp(pair<int, int> x, pair<int, int> y) {
	return x.first > y.first;
}


int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end(), comp);
	vector<int> days(k);
	int ans = 0;
	for (int i = 0; i < k; i++) {
		days[i] = a[i].second;
		ans += a[i].first;
	}
	cout << ans << "\n";
	sort(days.begin(), days.end());
	if (k >= 2) {
		cout << days[0] + 1 << " ";
		for (int i = 1; i < k - 1; i++) {
			cout << days[i] - days[i - 1] << " ";
		}
		cout << n - days[k - 2] - 1 << "\n";
	}
	else {
		cout << n << "\n";
	}
	//system("pause");
	return 0;
}