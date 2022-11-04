#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>

using namespace std;

#define LOCAL

struct point {
	int a[5];
};

bool f(point a, point b) {
	int s = 0;
	for (int i = 0; i < 5; i++)
		s += a.a[i] * b.a[i];
	return s <= 0;
}

point diff(point a, point b) {
	point res;
	for (int i = 0; i < 5; i++)
		res.a[i] = a.a[i] - b.a[i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("testbrain.in", "r", stdin);
	freopen("testbrain.out", "w", stdout);
#endif
	int n;
	cin >> n;
	if (n > 100) {
		cout << 0;
		return 0;
	}
	vector<point> a(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++)
			cin >> a[i].a[j];
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		bool is = 1;
		for (int j = 0; j < n; j++) {
			for (int q = j + 1; q < n; q++) {
				if (i != j && i != q) {
					is &= f(diff(a[j], a[i]), diff(a[q], a[i]));
				}
			}
		}
		if (is)
			ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i + 1<< ' ';
	return 0;
}