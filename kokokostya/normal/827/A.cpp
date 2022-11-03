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

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<string> t(n);
	vector< vector<int> > a(n);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		int sz;
		cin >> sz;
		a[i].resize(sz);
		for (int j = 0; j < sz; j++) {
			cin >> a[i][j];
			a[i][j]--;
			mx = max(a[i][j] + int(t[i].length()), mx);
		}
	}
	vector< vector<int> > st(mx);
	for (int i = 0; i < n; i++) {
		for (int j : a[i])
			st[j].push_back(i);
	}
	int len = -1;
	int m = 0;
	int pos = 0;
	for (int i = 0; i < mx; i++) {
		for (int j : st[i]) {
			if (i + t[j].length() > len + 1) {
				m = j;
				len = int(i + t[j].length()) - 1;
				pos = i;
			}
		}
		if (len < i) {
			cout << 'a';
		}
		else
			cout << t[m][i - pos];
	}

	return 0;
}