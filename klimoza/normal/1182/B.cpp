#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>

using namespace std;

typedef long long ll;

ll INF = 4e18;
ll INFi = 2e9;
long double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
	
	int h, w;
	cin >> h >> w;
	vector<string> field(h);
	for (int i = 0; i < h; i++) cin >> field[i];
	pair<int, int> ind = { -1, -1 };
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i > 0 && j > 0 && i < (h - 1) && j < (w - 1) && field[i][j] == '*' && field[i - 1][j] == '*' && field[i + 1][j] == '*' &&
				field[i][j - 1] == '*' && field[i][j + 1] == '*') {
				ind = { i, j };
				break;
			}
		}
	}
	if (ind == make_pair(-1, -1)) {
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < ind.first; i++) {
		if (field[i][ind.second] == '*' && field[i + 1][ind.second] != '*') {
			cout << "NO\n";
			return 0;
		}
	}
	for (int i = h - 1; i > ind.first; i--) {
		if (field[i][ind.second] == '*' && field[i - 1][ind.second] != '*') {
			cout << "NO\n";
			return 0;
		}
	}
	for (int j = 0; j < ind.second; j++) {
		if (field[ind.first][j] == '*' && field[ind.first][j + 1] != '*') {
			cout << "NO\n";
			return 0;
		}
	}
	for (int j = w - 1; j > ind.second; j--) {
		if (field[ind.first][j] == '*' && field[ind.first][j - 1] != '*') {
			cout << "NO\n";
			return 0;
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (j != ind.second && i != ind.first && field[i][j] == '*') {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	return 0;
}