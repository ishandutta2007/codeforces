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
	int t;
	cin >> t;
	for (int _ = 0; _ < t; _++) {
		int n;
		cin >> n;
		vector<int> arr(n);

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end());

		int a = arr[n - 2];

		cout << min(a - 1, n - 2) << endl;
	}
}