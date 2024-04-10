#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

signed main() {
	int n, h, m;
	cin >> n >> h >> m;
	vector<vector<pair<int, int>>> arr(n);
	for (int i = 0; i < m; i++) {
		int l, r, a;
		cin >> l >> r >> a;
		l--;
		r--;
		arr[l].push_back(make_pair(0, a));
		arr[r].push_back(make_pair(1, a));
	}
	int ans = 0;
	multiset<int> now;
	now.insert(h);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j].first == 0) {
				now.insert(arr[i][j].second);
			}
		}
		ans += *(now.begin()) * (*(now.begin()));
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j].first == 1) {
				now.erase(now.find(arr[i][j].second));
			}
		}
	}
	cout << ans;
	return 0;
}