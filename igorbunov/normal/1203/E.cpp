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
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	int ans = 0, last = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] - 1 > last) {
			arr[i]--;
		}

		if (arr[i] == last) {
			arr[i]++;
		}

		if (arr[i] > last) {
			ans++;
			last = arr[i];
		}
	}

	cout << ans;
}