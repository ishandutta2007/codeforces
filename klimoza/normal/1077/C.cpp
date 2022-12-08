#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long int ll;


int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		sum += a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	vector<int> ans;
	for (int i = 0; i < n - 1; i++) {
		if (sum - a[i].first - a[n - 1].first == a[n - 1].first) {
			ans.push_back(a[i].second);
		}
	}
	if (sum - a[n - 1].first - a[n - 2].first == a[n - 2].first) {
		ans.push_back(a[n - 1].second);
	}
	cout << ans.size() << "\n";
	for (int i : ans) {
		cout << i << " ";
	}
	//system("pause");  
	return 0;
}