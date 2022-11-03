#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector< pair<int, int> > arr;
	int n;
	cin >> n;
	arr.resize(n);
	vector<int> ax(n);
	vector<int> ay(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());
	vector<int> wa;
	wa.resize(n);
	wa.push_back(-1);
	ans.push_back(-1);
	for (int i = 0; i < n; i++) {
		cin >> wa[i];
	}
	for (int i = 0; i < n; i++) {
		int a = arr[i].second - arr[i].first;
		int j = max(ay[arr[i].second], ax[arr[i].first]);
		while (j < n && (wa[j] != a || ans[j] != 0)) {
			j++;
		}
		if (j == n) { cout << "NO"; return 0; }
		if (j > ay[arr[i].second]) { ay[arr[i].second] = j; }
		if (j > ax[arr[i].first]) { ax[arr[i].first] = j; }
		ans[j] = i + 1;

	}
	cout << "YES" << '\n';
	for (int i = 0; i < n; i++) {
		cout << arr[ans[i] - 1].first << ' ' << arr[ans[i] - 1].second << '\n';
	}


	return 0;
}