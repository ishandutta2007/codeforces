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

int log1(int k) {
	int now = 1LL;
	int ans = 0LL;

	while (now < k) {
		now *= 2;
		ans++;
	}

	return ans;
}

signed main() {
	int n, a;
	cin >> n >> a;
	a *= 8LL;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int a1 = 1LL;
	int val = arr[0];

	vector<pair<int, int>> b;

	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[i - 1]) {
			b.push_back(make_pair(val, a1));
			a1 = 1LL;
			val = arr[i];
		} else {
			a1++;
		}
	}

	b.push_back(make_pair(val, a1));

	int sz1 = b.size();

	while (sz1 > 0 && n * log1(sz1) > a) {
		sz1--;
	}

	int now = 0;
	int ans = 0;
	for (int i = 0; i < sz1; i++) {
		now += b[i].second;
	}

	ans = now;

	for (int i = sz1; i < b.size(); i++) {
		now -= b[i - sz1].second;
		now += b[i].second;
		ans = max(now, ans);
	}

	cout << n - ans << endl;
}