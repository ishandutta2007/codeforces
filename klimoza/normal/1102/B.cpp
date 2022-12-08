#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 1e18;

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	vector<int> ans(n);
	sort(a.begin(), a.end());
	int cnt = 1;
	int len = 1;
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		if (cnt == k + 1) cnt = 1;
		ans[a[i].second] = cnt;
		cnt++;
		if (i > 0 && a[i].first == a[i - 1].first) {
			len++;
		}
		else {
			maxi = max(maxi, len);
			len = 1;
		}
	}
	maxi = max(maxi, len);
	if (maxi > k) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		for (int i : ans) cout << i << " ";
		cout << endl;
	}
	//system("pause");
	return 0;
}