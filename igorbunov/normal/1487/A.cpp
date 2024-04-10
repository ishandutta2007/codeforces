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
	int n;
	cin >> n;
	vector<int> arr(n);
	int min1 = 1000000;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		min1 = min(min1, arr[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (arr[i] != min1);
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