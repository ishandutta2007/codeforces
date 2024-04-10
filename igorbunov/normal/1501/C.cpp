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

map<int, vector<int>> cnt_fake;
map<int, int> inds;
int cnt[5000005];

mt19937 rnd(574457);

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> arr1(n);
	vector<int> keke;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		inds[arr[i]] = i + 1;
		cnt_fake[arr[i]].push_back(i);
		if (cnt_fake[arr[i]].size() == 2) {
			keke.push_back(cnt_fake[arr[i]][0]);
			keke.push_back(cnt_fake[arr[i]][1]);
		}
		if (cnt_fake[arr[i]].size() >= 4) {
			cout << "YES\n";
			for (auto v: cnt_fake[arr[i]]) {
				cout << v + 1 << " ";
			}
			return 0;
		}
	}
	arr1 = arr;
	if (keke.size() >= 4) {
		cout << "YES\n";
		cout << keke[0] + 1 << " " << keke[2] + 1 << " " << keke[1] + 1 << " " << keke[3] + 1;
		return 0;
	}
	if (keke.size() == 2) {
		int val = arr[keke[0]] * 2;
		vector<int> ans;
		ans.push_back(keke[0]);
		ans.push_back(keke[1]);

		for (int i = 0; i < n; i++) {
			if (arr[i] == val / 2) {
				continue;
			}
			int need = val - arr[i];
			if (inds[need] != 0) {
				ans.push_back(i);
				ans.push_back(inds[need] - 1);
				break;
			}
		}
		if (ans.size() >= 4) {
			cout << "YES\n";
			for (auto v: ans) {
				cout << v + 1 << " ";
			}
			return 0;
		}
	}
	arr.clear();
	for (auto p: cnt_fake) {
		arr.push_back(arr1[p.second[0]]);
	}

	n = arr.size();
	sort(arr.begin(), arr.end());

	map<pair<int, int>, bool> used;
	unordered_map<int, vector<pair<int, int>>> for_ans;

	for (int i = 0; i < 100000; i++) {
		int a = rnd() % n;
		int b = rnd() % n;
		if (a == b) {
			continue;
		}
		if (a > b) {
			swap(a, b);
		}
		if (used[make_pair(a, b)]) {
			continue;
		}
		//cout << a << " " << b << " " << arr[a] << " " << arr[b] << endl;
		for_ans[arr[a] + arr[b]].push_back(make_pair(inds[arr[a]], inds[arr[b]]));
		if (for_ans[arr[a] + arr[b]].size() >= 2) {
			cout << "YES\n";
			for (auto p: for_ans[arr[a] + arr[b]]) {
				cout << p.first << " " << p.second << " ";
			}
			return 0;
		}
		used[make_pair(a, b)] = true;

	}
	cout << "NO\n";
	return 0;
	int ind = n - 1;
	int now = 0;
	for (int i = 5000000; i >= 0; i--) {
		if (arr[ind] == i) {
			now++;
			ind--;
		}
		cnt[i] = now;
	}

	int l = 0;
	int r = 10000000;

	while (r - l > 1) {
		int m = (l + r) / 2;
		int val = 0;

		for (int i = 0; i < n; i++) {
			if (m - arr[i] > 5000000) {
				continue;
			}
			val += cnt[max(arr[i] + 1, m - arr[i])];
		}
		//cout << l << " " << r << endl;
		//cout << m << " " << val << endl << endl; 
		if (val < 4) {
			r = m;
		} else {
			l = m;
		}
	}
	keke.clear();
	for (int i = 0; i < n; i++) {
		int need = l - arr[i];
		if (need <= arr[i]) {
			continue;
		}
		if (need > 0 && inds[need] != 0) {
			keke.push_back(inds[arr[i]]);
			keke.push_back(inds[need]);
		}
	}
	if (keke.size() >= 4) {
		cout << "YES\n";
		for (int i = 0; i < 4; i++) {
			cout << keke[i] << " ";
		}
		return 0;
	} else {
		cout << "NO\n";
	}
}