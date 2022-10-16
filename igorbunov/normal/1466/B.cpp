#include <algorithm>
#include <iostream>
#include <cstdlib>
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

//309810XU
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	vector<int> cnt(3 * n + 4);
	for (int i = n - 1; i >= 0; i--) {
		if (cnt[arr[i] + 1] == 0) {
			cnt[arr[i] + 1]++;
		} else {
			cnt[arr[i]]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < 3 * n + 4; i++) {
		ans += (cnt[i] > 0);
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}