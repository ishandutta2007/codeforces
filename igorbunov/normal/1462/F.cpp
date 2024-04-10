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
	vector<int> l(n);
	vector<int> r(n);
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		arr[i] = make_pair(l[i], r[i]);
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());

	int ans = n;
	for (int i = 0; i < n; i++) {
		int now = 0;
		now += lower_bound(r.begin(), r.end(), arr[i].first) - r.begin();
		now += l.end() - upper_bound(l.begin(), l.end(), arr[i].second);
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