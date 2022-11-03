#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector< pair<int, int> > arr(n + 1);
	for (int i = 0; i < n + 1; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i].second - arr[i - 1].second > 0) { if (arr[i + 1].first - arr[i].first < 0) { ans++; } }
		if (arr[i].second - arr[i - 1].second < 0) { if (arr[i + 1].first - arr[i].first > 0) { ans++; } }
		if (arr[i].first - arr[i - 1].first < 0) { if (arr[i + 1].second - arr[i].second < 0) { ans++; } }
		if (arr[i].first - arr[i - 1].first > 0) { if (arr[i + 1].second - arr[i].second > 0) { ans++; } }
	}
	cout << ans;

	return 0;
}