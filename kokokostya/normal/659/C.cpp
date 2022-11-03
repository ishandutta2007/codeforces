#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int s = 0;
	int i = 0;
	int nw = 1;
	vector<int> ans;
	while (s <= m) {
		if (i < n && arr[i] == nw) { i++;}
		else {
			s += nw;
			ans.push_back(nw);
		}
		nw++;
	}
	cout << ans.size() - 1 << '\n';
	for (int j = 0; j < ans.size() - 1; j++) {
		cout << ans[j] << ' ';
	}
	return 0;
}