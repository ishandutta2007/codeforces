#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector< vector< pair<int, string> > > arr(m);
	string s;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> s >> a >> b;
		arr[a - 1].push_back({ b, s });
	}
	for (int i = 0; i < m; i++) {
		sort(arr[i].begin(), arr[i].end());
	}
	for (int i = 0; i < m; i++) {
		int k = arr[i].size();
		if (k != 2 && arr[i][k - 3].first == arr[i][k - 2].first) { cout << '?' << '\n'; }
		else {
			cout << arr[i][k - 1].second << ' ' << arr[i][k - 2].second << '\n';
		}
	}


	return 0;
}