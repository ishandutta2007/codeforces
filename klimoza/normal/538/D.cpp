#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 998244353;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<int, int>> f;
	vector<pair<int, int>> c;
	set<pair<int, int>> free;
	string st;
	for (int i = 0; i < n; i++) {
		cin >> st;
		for (int j = 0; j < n; j++) {
			if (st[j] == 'o') {
				c.push_back({ i, j });
			}
			else if (st[j] == 'x') {
				f.push_back({ i, j });
			}
			else {
				free.insert({ i, j });
			}
		}
	}
	vector<pair<int, int>> ans;
	for (auto i : f) {
		bool fl = false;
		for (int k = 0; k < c.size(); k++) {
			auto j = c[k];
			pair<int, int> cur = { i.first - j.first, i.second - j.second };
			bool bl = true;
			for (int h = 0; h < c.size(); h++) {
				if (h == k) continue;
				if (free.find({ c[h].first + cur.first, c[h].second + cur.second }) != free.end()) {
					bl = false;
					break;
				}
			}
			if (bl) {
				ans.push_back(cur);
				fl = true;
				break;
			}
		}
		if (!fl) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	vector<vector<char>> an(2 * n - 1, vector<char>(2 * n - 1, '.'));
	an[n - 1][n - 1] = 'o';
	for (auto i : ans) {
		an[n - 1 + i.first][n - 1 + i.second] = 'x';
	}
	for (int i = 0; i < 2 * n - 1; i++) {
		for (auto c : an[i]) cout << c;
		cout << endl;
	}
	//system("pause");
	return 0;
}