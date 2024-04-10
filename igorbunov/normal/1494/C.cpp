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

#define mod NE_mod
#define int long long
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"


int solve(vector<int> a, vector<int> b) {
	int n = a.size();
	int m = b.size();

	map<int, int> kek;
	for (int i = 0; i < a.size(); i++) {
		kek[a[i]]++;
	}

	vector<int> suf(m + 1);
	for (int i = m - 1; i >= 0; i--) {
		suf[i] = kek[b[i]];
		if (i != m - 1) {
			suf[i] += suf[i + 1];
		}
	}

	int cnt = 0;
	int l = 0;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int now = suf[i + 1];
		while (cnt != n && a[cnt] <= b[i]) {
			cnt++;
		}
		while (l != m && b[l] < b[i] - cnt + 1) {
			l++;
		}
		now += i - l + 1;
		ans = max(ans, now);
	}
	return ans;
}

void solve1() {
	int n, m;
	cin >> n >> m;
	vector<int> arr1, arr2, arr3, arr4;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		if (val < 0) {
			arr1.push_back(-val);
		} else {
			arr2.push_back(val);
		}
	}

	for (int i = 0; i < m; i++) {
		int val;
		cin >> val;
		if (val < 0) {
			arr3.push_back(-val);
		} else {
			arr4.push_back(val);
		}
	}
	reverse(arr1.begin(), arr1.end());
	reverse(arr3.begin(), arr3.end());
	cout << solve(arr1, arr3) + solve(arr2, arr4) << endl;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve1();
	}
}