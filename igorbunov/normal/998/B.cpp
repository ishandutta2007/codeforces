//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
#include <unordered_set>
#include <unordered_map>
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
#include <list>
#include <set>
#include <map>
 
using namespace std;
 
#define int long long
 
signed main() {
	int n, b;
	cin >> n >> b;
	vector<int> arr(100, 0);
	int now = n;
	int now1 = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		now1 += arr[i] % 2;
	}
	if (now != now1 * 2) {
		cout << 1 / 0;
		return 0;
	}
	vector<int> all;
	now = 0;
	now1 = 0;
	int last = 0;
	for (int i = 2; i <= n - 2; i += 2) {
		now += 2;
		now1 += arr[i - 1] % 2;
		now1 += arr[i - 2] % 2;
		if (now1 * 2 == now) {
			last = i;
			all.push_back(abs(arr[i] - arr[i - 1]));
			now = 0;
			now1 = 0;

		}
	}
	sort(all.begin(), all.end());
	int ans = 0;
	int count = 0;
	while (count <= b && ans < all.size()) {
		count += all[ans];
		ans++;
		if (count > b) {
			ans--;
		}
	}
	cout << ans;
	return 0;
}