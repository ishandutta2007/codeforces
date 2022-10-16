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
#include <exception>
#include <stdexcept>

#define int long long

using namespace std;

signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> pref(n, 0);
	double ans = -1000000000.0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pref[i] = arr[i];
		if (i) {
			pref[i] += pref[i - 1];
		}
	}
	for (int s_size = k; s_size <= n; s_size++) {
		for (int i = 0; i < n - s_size + 1; i++) {
			if (i) {
				int sum = pref[i + s_size - 1] - pref[i - 1];
				ans = max(ans, (double)sum / (double)s_size);
			} else {
				int sum = pref[i + s_size - 1];
				ans = max(ans, (double)sum / (double)s_size);
			}
		}
	}
	cout << fixed << setprecision(12) << ans;
}