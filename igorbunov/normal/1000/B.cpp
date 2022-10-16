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
	int n, m;
	cin >> n >> m;
	vector<int> arr(n + 1);
	arr[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
	}
	arr.push_back(m);
	vector<int> sum(n + 2);
	vector<int> sum1(n + 2);
	vector<int> sum2(n + 2);
	sum[0] = 0;
	sum1[0] = 0;
	sum2[0] = 0;
	for (int i = 1; i < n + 2; i++) {
		sum[i] = sum[i - 1] + arr[i] - arr[i - 1];
		if (i % 2) {
			sum1[i] = sum1[i - 1] + arr[i] - arr[i - 1];
			sum2[i] = sum2[i - 1];
		} else {
			sum1[i] = sum1[i - 1];
			sum2[i] = sum2[i - 1] + arr[i] - arr[i - 1];
		}
	}
	/*for (int i = 0; i < n + 2; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < n + 2; i++) {
		cout << sum[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n + 2; i++) {
		cout << sum1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n + 2; i++) {
		cout << sum2[i] << " ";
	}
	cout << endl;*/
	int max1 = sum1[n + 1];
	for (int i = 0; i < n + 1; i++) {
		if (arr[i + 1] - arr[i] > 1) {
			int ans1 = sum1[i];
			ans1 += arr[i + 1] - arr[i] - 1;
			ans1 += sum2[n + 1] - sum2[i + 1];
			if (ans1 > max1) {
			max1 = ans1;
		}
		}
	}
	cout << max1;
}