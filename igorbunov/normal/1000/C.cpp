//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
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

#define int long long

signed main() {
	int n;
	cin >> n;
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr.push_back({x, 0});
		arr.push_back({y, 1});
	}
	sort(arr.begin(), arr.end());
	vector<int> ans(n, 0);
	int now = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (arr[i].second) {
			ans[now - 1] += arr[i].first - arr[i - 1].first - 1;
			ans[now - 1]++;
			now--;
		} else {
			if (now) {
				ans[now - 1] += arr[i].first - arr[i - 1].first - 1;
			}
			now++;
			ans[now - 1]++;
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}