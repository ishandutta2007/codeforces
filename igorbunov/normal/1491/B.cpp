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
	int n, u, v;
	cin >> n >> u >> v;
	vector<int> arr(n);
	bool good = true;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		good &= (arr[i] == arr[0]);
	}
	for (int i = 0; i < n - 1; i++) {
		if (abs(arr[i] - arr[i + 1]) > 1) {
			cout << 0 << endl;
			return;
		}
	}
	if (good) {
		cout << v + min(u, v) << endl;
		return;
	}
	cout << min(u, v) << endl;
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