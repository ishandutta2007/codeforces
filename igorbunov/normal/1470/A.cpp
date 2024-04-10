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

#define int long long
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i]--;
	}
	vector<int> c(m);
	for (int i = 0; i < m; i++) {
		cin >> c[i];
	}
	sort(arr.begin(), arr.end());
	vector<int> pref(n);
	for (int i = 0; i < n; i++) {
		pref[i] += c[arr[i]];
		if (i) {
			pref[i] += pref[i - 1];
		}
	}
	vector<int> pref1(n);
	for (int i = 0; i < min(n, m); i++) {
		pref1[i] += c[i];
		if (i) {
			pref1[i] += pref1[i - 1];
		}
	}
	int ans = pref[n - 1];
	for (int i = n - 1; i >= 0; i--) {
		int need = n - i;
		if (arr[i] + 1 < need) {
			break;
		}
		int now = pref1[need - 1];
		//cout << i << " " << now << endl;
		if (i) {
			now += pref[i - 1];
		}
		//cout << i << " " << now << endl;
		ans = min(ans, now);
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