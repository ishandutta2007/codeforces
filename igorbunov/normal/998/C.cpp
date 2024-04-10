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
	int n, x, y;
	cin >> n >> x >> y;
	string b;
	cin >> b;
	vector<int> arr;
	arr.push_back(b[0] - '0');
	int last = arr[0];
	int null_count = 0;
	if (last == 0) {
		null_count++;
	}
	for (int i = 1; i < n; i++) {
		int c = b[i] - '0';
		if (c != last) {
			arr.push_back(c);
			if (c == 0) {
				null_count++;
			}
			last = c;
		}
	}
	/*for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << null_count << endl;*/
	if (!null_count) {
		cout << 0;
		return 0;
	}
	cout << min( (null_count - 1) * x + y, (null_count - 1) * y + y);
	return 0;
}