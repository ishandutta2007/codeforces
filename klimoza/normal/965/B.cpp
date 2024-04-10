#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	string t;
	vector<vector<pair<int, int>>> field(n);
	vector<vector<int>> ans(n);
	for (int i = 0; i < n; i++) {
		field[i].resize(n);
		cin >> t;
		ans[i].resize(n);
		for (int j = 0; j < n; j++) {
			if (t[j] == '#')	field[i][j] = { 0, 0 };
			else {
				field[i][j] = { 1, 1 };
				if (j != 0) field[i][j].second = field[i][j - 1].second + 1;
				if (i != 0) field[i][j].first = field[i - 1][j].first + 1;
				if (field[i][j].second >= k) {
					for (int h = j - k + 1; h <= j; h++) {
						ans[i][h]++;
					}
				}
				if (field[i][j].first >= k) {
					for (int h = i - k + 1; h <= i; h++) {
						ans[h][j]++;
					}
				}
			}
		}
	}
	int maxx = 0;
	int maxy = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans[i][j] > ans[maxx][maxy]) {
				maxx = i;
				maxy = j;
			}
		}
	}
	cout << maxx + 1 << " " << maxy + 1 << "\n";
	//system("pause");	
}