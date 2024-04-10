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
	int n;
	cin >> n;
	vector<int> arr(10, 0);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	//return 0;
	int cost = 0;
	for (int mask = 0; mask < 1024; mask++) {
		int mask1 = mask;
		cost = 0;
		for (int i = 9; i >= 0; i--) {
			cost += arr[i] * (mask1 / (1 << i));
			mask1 %= (1 << i);
		}
		mask1 = mask;
		if (cost != sum - cost) {
			int ans = 0;
			for (int i = 9; i >= 0; i--) {
				if (mask1 / (1 << i) && arr[i]) {
					ans++;
				}
			}
			if (ans == n || !ans) {
				continue;
			}
			cout << ans << endl;
			for (int i = 9; i >= 0; i--) {
				if (mask1 / (1 << i) && arr[i]) {
					cout << i + 1 << " ";
				}
			}
			return 0;
		}
	}
	cout << -1;
	return 0;
}