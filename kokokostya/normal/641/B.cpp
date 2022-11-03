#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector< vector<int> > arr(n);
	for (int i = 0; i < n; i++) {
		arr[i].resize(m);
	}
	vector< pair<int, int> > did;
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, c;
			cin >> x;
			x--;
			c = arr[x][0];
			for (int j = 0; j < m - 1; j++) {
				arr[x][j] = arr[x][j + 1];
			}
			arr[x][m - 1] = c;
			did.push_back({ 1, x });
		}
		if (t == 2) {
			int x, c;
			cin >> x;
			x--;
			c = arr[0][x];
			for (int j = 0; j < n - 1; j++) {
				arr[j][x] = arr[j + 1][x];
			}
			arr[n - 1][x] = c;
			did.push_back({ 2, x });
		}
		if (t == 3) {
			int x, y, c;
			cin >> x >> y >> c;
			arr[x - 1][y - 1] = c;
		}
	}
	for (int i = did.size() - 1; i >= 0; i--) {
		int x = did[i].second;
		if (did[i].first == 1) {
			int c = arr[x][m - 1];
			for (int j = m - 1; j > 0; j--) {
				arr[x][j] = arr[x][j - 1];
			}
			arr[x][0] = c;
		}
		else {
			int c = arr[n - 1][x];
			for (int j = n - 1; j > 0; j--) {
				arr[j][x] = arr[j - 1][x];
			}
			arr[0][x] = c;
		}
	
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}