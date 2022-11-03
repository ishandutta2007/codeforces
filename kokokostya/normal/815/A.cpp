#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>

using namespace std;
//#define LOCAL
const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	vector< vector<int> > a(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	int res = INF;
	int us = 0;
	for (int j = 0; j <= 500; j++) {
		vector<int> r(n), c(m);
		r[0] = j;
		c[0] = a[0][0] - j;
		for (int i = 1; i < n; i++) {
			r[i] = a[i][0] - c[0];
		}
		for (int i = 1; i < m; i++) {
			c[i] = a[0][i] - r[0];
		}
		bool is = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				is &= (a[i][j] == r[i] + c[j]);
			}
		}
		int s = 0;
		for (int i = 0; i < n; i++) {
			is &= r[i] >= 0;
			s += r[i];
		}
		for (int i = 0; i < m; i++) {
			is &= c[i] >= 0;
			s += c[i];
		}
		if (is && s < res) {
			res = s;
			us = j;
		}
	}
	if (res == INF)
		cout << -1;
	else {
		vector< pair<int, int> > ans;
		vector<int> r(n), c(m);
		r[0] = us;
		c[0] = a[0][0] - us;
		for (int i = 1; i < n; i++) {
			r[i] = a[i][0] - c[0];
		}
		for (int i = 1; i < m; i++) {
			c[i] = a[0][i] - r[0];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < r[i]; j++) {
				ans.push_back({ i + 1, 1 });
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < c[i]; j++) {
				ans.push_back({ i + 1, 0 });
			}
		}
		cout << ans.size() << '\n';
		for (pair<int, int> i : ans) {
			if (i.second)
				cout << "row ";
			else
				cout << "col ";
			cout << i.first << '\n';
		}
	}
	
	return 0;
}