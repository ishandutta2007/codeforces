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

map<long long, int> cnt;
int len = 9;

void add(string a, int val) {
	for (int st = 0; st < len; st++) {
		string now = "";
		long long is = 0;
		for (int l = 1; st + l <= len; l++) {
			now += a[st + l - 1];
			is = is * 100 + a[st + l - 1];
			cnt[is] += val;
		}
	}
	return;
}

string get(string a) {
	string res = "10000000000";
	for (int st = 0; st < len; st++) {
		string now = "";
		long long is = 0;
		for (int l = 1; st + l <= len; l++) {
			now += a[st + l - 1];
			is = is * 100 + a[st + l - 1];
			if (!cnt[is] && res.length() > now.length())
				res = now;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("victory.in", "r", stdin);
	freopen("victory.out", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		add(a[i], 1);
	}
	for (int i = 0; i < n; i++) {
		add(a[i], -1);
		cout << get(a[i]) << '\n';
		add(a[i], 1);
	}
	
	return 0;
}