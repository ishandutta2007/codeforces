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
 
#pragma GCC_OPTIMAZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

signed main() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {

		int a = arr[i];

		bool can = true;
		for (int j = max(i - x, 0LL); j < i; j++) {
			if (arr[j] < arr[i]) {
				can = false;
				break;
			}
		}

		for (int j = min(n - 1, i + y); j > i; j--) {
			if (arr[j] < arr[i]) {
				can = false;
				break;
			}
		}

		if (can) {
			cout << i + 1;
			return 0;
		}
	}
}