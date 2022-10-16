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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr1(n, vector<int>(m));
	vector<vector<int>> arr2(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr1[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr2[i][j];
		}
	}
	vector<vector<int>> arr3(n, vector<int>(m));
	vector<vector<int>> arr4(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr3[i][j] = min(arr1[i][j], arr2[i][j]);
			arr4[i][j] = max(arr1[i][j], arr2[i][j]);
		}
	}
	if (check(arr3, n, m) && check(arr4, n, m)) {
		cout << "Possible";
	} else {
		cout << "Impossible";
	}
	return 0;
}