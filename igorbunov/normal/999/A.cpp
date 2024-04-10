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
	int n, k;
	cin >> n >> k;
	int ans = 0;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int l = 0;
	int r = n - 1;
	while (r >= l) {
		if (arr[l] <= k) {
			l++;
			ans++;
		} else {
			if (arr[r] <= k) {
				r--;
				ans++;
			} else {
				break;
			}
		}
	}
	cout << ans;
	return 0;
}