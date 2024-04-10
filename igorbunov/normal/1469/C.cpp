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
 
using namespace std;

#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

pair<int, int> merge(int l1, int r1, int l2, int r2) {
	if (r1 < l2 || r2 < l1) {
		return make_pair(-1, -1);
	}
	return make_pair(max(l1, l2), min(r1, r2));
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int r = h[0];
	int l = h[0];
	for (int i = 0; i < n - 1; i++) {
		int r1 = r + (k - 1);
		int l1 = l - (k - 1);
		int l2 = h[i + 1];
		int r2 = h[i + 1] + (k - 1);
		auto p = merge(l1, r1, l2, r2);
		if (p.f == -1) {
			cout << "No\n";
			return;
		}
		l = p.f;
		r = p.s;
	}
	if (l == h[n - 1]) {
		cout << "Yes\n"; 
	} else {
		cout << "No\n";
	}
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