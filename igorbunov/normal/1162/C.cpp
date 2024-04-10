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

bool check(vector<vector<int>> &arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (arr[i][j] >= arr[i][j + 1]) {
				return false;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j][i] >= arr[j + 1][i]) {
				return false;
			}
		}
	}
	return true;
}

signed main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> arr(n);
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		a--;
		arr[a].push_back(i);
	} 
	for (int i = 0; i < n; i++) {
		sort(arr[i].begin(), arr[i].end());
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].size() == 0) {
			ans++;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (arr[i].size() == 0) {
			ans++;
			continue;
		}
		if (arr[i + 1].size() == 0) {
			ans++;
			continue;
		}
		if (arr[i][0] > arr[i + 1].back()) {
			ans++;
		}
	}
	for (int i = 1; i < n; i++) {
		if (arr[i].size() == 0) {
			ans++;
			continue;
		}
		if (arr[i - 1].size() == 0) {
			ans++;
			continue;
		}
		if (arr[i][0] > arr[i - 1].back()) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}