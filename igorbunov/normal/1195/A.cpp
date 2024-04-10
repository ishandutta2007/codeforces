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
	int n, k;
	cin >> n >> k;

	vector<int> arr(k);

	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		c--;
		arr[c]++;
	}

	int now = (n + 1) / 2;
	int ans1 = 0;
	for (int i = 0; i < k; i++) {
		int a = arr[i];

		int b = arr[i] / 2;

		if (b > now) {
			ans1 += 2 * now;
			cout << ans1;
			return 0;
		}
		arr[i] %= 2;

		ans1 += 2 * b;
		now -= b;
	}

	for (int i = 0; i < k; i++) {
		if (now == 0) {
			cout << ans1;
			return 0;
		}
		if (arr[i] > 0) {
			ans1++;
			now--;
		}
	}
	cout << ans1;
}