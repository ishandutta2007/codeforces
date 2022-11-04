#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

struct vert {
	int mn, mx, val;
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector< vector<int> > arr(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	vector< vert > str(n, { -1, -1, 0 }), col(m, { -1, -1, 0 });
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]) {
				str[i].val++;
				if (str[i].mn == -1 || j < str[i].mn)
					str[i].mn = j;
				if (str[i].mx == -1 || j > str[i].mx)
					str[i].mx = j;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j][i]) {
				col[i].val++;
				if (col[i].mn == -1 || j < col[i].mn)
					col[i].mn = j;
				if (col[i].mx == -1 || j > col[i].mx)
					col[i].mx = j;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (str[i].val) {
			ans += str[i].mn;
			ans += (m - 1) - str[i].mx;
			ans += 2 * (str[i].mx - str[i].mn + 1 - str[i].val);
		}
	}
	for (int i = 0; i < m; i++) {
		if (col[i].val) {
			ans += col[i].mn;
			ans += (n - 1) - col[i].mx;
			ans += 2 * (col[i].mx - col[i].mn + 1 - col[i].val);
		}
	}
	cout << ans;
	return 0;
}