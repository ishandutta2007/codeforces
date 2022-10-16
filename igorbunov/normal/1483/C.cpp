#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <random>
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
#define int long long
int n;
int t[4000000];

int all_max(int v, int l, int r, int vl, int vr) {
	if (l >= r) {
		return -1000000000;
	}
	if (l == vl && r == vr) {
		return t[v];
	}
	int vm = (vl + vr) / 2;
	int sum1 = all_max(v * 2 + 1, l, min(r, vm), vl, vm);
	int sum2 = all_max(v * 2 + 2, max(l, vm), r, vm, vr);
	return max(sum1, sum2);
}

void update(int v, int vl, int vr, int pos, int val) {
	if (vl >= vr) {
		return;
	}
	if (vl == pos && vl + 1 == vr) {
		t[v] = val;
		return;
	}
	int vm = (vl + vr) / 2;
	if (pos < vm) {
		update(v * 2 + 1, vl, vm, pos, val);
	} else {
		update(v * 2 + 2, vm, vr, pos, val);
	}
	t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

void upd(int pos, int val) {
	update(0, 0, n, pos, val);
}

int get(int l, int r) {
	return all_max(0, l, r, 0, n);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> h(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	vector<int> prev(n, -1);
	{
		vector<int> now;
		for (int i = n - 1; i >= 0; i--) {
			while (now.size() != 0 && h[now.back()] > h[i]) {
				prev[now.back()] = i;
				now.pop_back();
			}
			now.push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<int> dp(n, -1000000000000000LL);
	dp[0] = b[0];
	upd(0, dp[0]);

	for (int i = 1; i < n; i++) {
		int kek = prev[i];
		if (kek != -1) {
			dp[i] = b[i] + get(kek, i);
			dp[i] = max(dp[i], dp[kek]);
		} else {
			dp[i] = b[i] + max(0LL, get(0, i));
		}
		upd(i, dp[i]);
	}
	cout << dp[n - 1];
}